#include "UDE_3dsmax.h"

#define UDE_3dsmax_CLASS_ID	Class_ID(0xa6018b18, 0x6a35c316)

class UDE_3dsmax : public UtilityObj { public:
		
	UDE_3dsmax();
	virtual ~UDE_3dsmax();

  virtual void DeleteThis();

	virtual void BeginEditParams    (Interface *poInterface, IUtil *iu);
  virtual void EndEditParams      (Interface *poInterface, IUtil *iu) {}
  virtual void SelectionSetChanged(Interface *poInterface, IUtil *iu) {}

	static UDE_3dsmax* GetInstance() {

		static UDE_3dsmax theUDE_3dsmax;
		return &theUDE_3dsmax; 
	}
};


class UDE_3dsmaxClassDesc : public ClassDesc2 {

public:
  virtual int IsPublic() { return TRUE; }
  virtual void* Create(BOOL) { return UDE_3dsmax::GetInstance(); }
  virtual const TCHAR *	ClassName() { return GetString(IDS_CLASS_NAME); }
  virtual SClass_ID SuperClassID() { return UTILITY_CLASS_ID; }
  virtual Class_ID ClassID() { return UDE_3dsmax_CLASS_ID; }
  virtual const TCHAR* Category() { return GetString(IDS_CATEGORY); }

  virtual const TCHAR* InternalName() { return _T("UDE_3dsmax"); }
  virtual HINSTANCE HInstance() { return hInstance; }
};

ClassDesc2* GetUDE_3dsmaxDesc() { 

	static UDE_3dsmaxClassDesc UDE_3dsmaxDesc;
	return &UDE_3dsmaxDesc; 
}

//--- EDITOR CONFIG ---

COLORREF g_stColorBackground   = RGB(  0,   0,   0);
COLORREF g_stColorDefault      = RGB(  0, 128, 128);
COLORREF g_stColorComment      = RGB(192, 192, 192);
COLORREF g_stColorNumber       = RGB(  0, 130, 104);
COLORREF g_stColorWord         = RGB(128, 128, 128);
COLORREF g_stColorString       = RGB(  0, 101, 130);
COLORREF g_stColorCharacter    = RGB(  0, 101, 130);
COLORREF g_stColorUUId         = RGB(128, 128, 128);
COLORREF g_stColorPreProcessor = RGB(130, 125,   0);
COLORREF g_stColorOperator     = RGB(128, 128, 128);
COLORREF g_stColorMark         = RGB(  0,   0, 192);
COLORREF g_stColorCursor       = RGB(255, 255, 255);

//lexer keywords
static const char g_szKeyWords[] = 

  "InStock Behaviors EventScript Delay Mute Consume Print DebugBreak Begin End <this> "

  "3DControl 3DRotate 3DPulseScale 3DPlaneTranslator 3DSplineTranslator "

  "2DControl 2DFadeOut 2DPulseScale 2DRotate "

  "AlignAndLink Trapdoor Door Box2DDraw ShowSpeech SpawnGroup DelObj CloneObj ResetGravity SetGravity SetCam SetBallPos SetBallVel "
  "StarBlink TentacleFlesh Ball Ammo Points PauseGameplay ResumeGameplay FadeToBlack FadeIn Cutscene ShowVictory ShowSpeech ShowText "
  "Accel Boost ArrowBlink WarningBeep BackToMainMenu Start SlowdownEffect "
;

//--- UDE_3dsmax -------------------------------------------------------

#define APP_NAME "User-Defined Editor - by Rockhead Games"

bool g_bnScintillaInit = false;

HINSTANCE g_hInstance = NULL;

Interface *g_poMaxInterface = NULL;

IUtil *g_poUtilUI = NULL;

HWND g_hWnd = NULL;

HWND g_hScintilla = NULL;

#define STYLE_MARK 11

LRESULT SendEditor(UINT wwMsg, WPARAM wParam = 0, LPARAM lParam = 0) {

  ASSERT(g_hScintilla);
  return ::SendMessage(g_hScintilla, wwMsg, wParam, lParam);
}

void SetAStyle(int nStyle, COLORREF stFore) {

  SendEditor(SCI_STYLESETFORE, nStyle, stFore);
  SendEditor(SCI_STYLESETBACK, nStyle, g_stColorBackground);
}

void SetupLexer() {

  SendEditor(SCI_STYLECLEARALL);

  SendEditor(SCI_SETLEXER, SCLEX_CPP);
  
  SendEditor(SCI_SETSTYLEBITS, 5);

  SendEditor(SCI_SETKEYWORDS, 0, (LPARAM)g_szKeyWords);

  for(int nCount = 0; nCount <= 21; nCount++)
    SetAStyle(nCount, g_stColorDefault);

  SetAStyle(SCE_C_DEFAULT,      g_stColorDefault);
  SetAStyle(SCE_C_COMMENT,      g_stColorComment);
  SetAStyle(SCE_C_COMMENTLINE,  g_stColorComment);
  SetAStyle(SCE_C_COMMENTDOC,   g_stColorComment);
  SetAStyle(SCE_C_NUMBER,       g_stColorNumber);
  SetAStyle(SCE_C_STRING,       g_stColorString);
  SetAStyle(SCE_C_CHARACTER,    g_stColorCharacter);
  SetAStyle(SCE_C_UUID,         g_stColorUUId);
  SetAStyle(SCE_C_OPERATOR,     g_stColorOperator);
  SetAStyle(SCE_C_PREPROCESSOR, g_stColorPreProcessor);
  SetAStyle(SCE_C_WORD,         g_stColorWord);
}

string GetEditorText() {

  string strText;

  if (g_hScintilla) {

    int nLen = SendEditor(SCI_GETLENGTH);
    if (nLen) {

      char *pszAux = (char *)FastAlloc(nLen + 1);
      SendEditor(SCI_GETTEXT, nLen + 1, (LPARAM)pszAux);
      pszAux[nLen] = '\0';

      strText = pszAux;

      FastFree(pszAux);
    }
  }

  return strText;
}

void SetEditorText(char *pszText) {

  SendEditor(SCI_CANCEL);
  SendEditor(SCI_SETUNDOCOLLECTION, 0);
  SendEditor(SCI_SETTEXT, 0, (LPARAM)pszText);
  SendEditor(SCI_SETUNDOCOLLECTION, 1);
  SendEditor(EM_EMPTYUNDOBUFFER);
  SendEditor(SCI_SETSAVEPOINT);
  SendEditor(SCI_GOTOPOS, 0);
}

ULONG GetNodeId(INode *poMaxNode) {

  ULONG wwNodeHandle = poMaxNode->GetActualINode()->GetHandle();
  return wwNodeHandle;
}

INode *GetNodeById(Interface *poInterface, ULONG wwId, INode *poCurrNode = NULL) {

  if (!poCurrNode)
    poCurrNode = poInterface->GetRootNode();

  if (GetNodeId(poCurrNode) == wwId)
    return poCurrNode;

  for(int nCount = 0; nCount < poCurrNode->NumberOfChildren(); nCount++) {

    INode *poNode = GetNodeById(poInterface, wwId, poCurrNode->GetChildNode(nCount));
    if (poNode)
      return poNode;
  }

  return NULL;
}

string     g_strOriginalText;
set<ULONG> g_swwCurrSel;
BOOL       g_bnConflict             = FALSE;
BOOL       g_bnConflictDialogOpened = FALSE;

void RetrieveText(Interface *poInterface) {

  g_swwCurrSel.clear();

  string strUserDefined;

  g_bnConflict = FALSE;

  BOOL bnFirst = TRUE;

  INode *poUniqueNode = NULL;

  for(int nCount = 0; nCount < poInterface->GetSelNodeCount(); nCount++) {

    INode *poMaxNode = poInterface->GetSelNode(nCount);

    TSTR pszUserData;
    poMaxNode->GetUserPropBuffer(pszUserData);
    string strCurrDefined = pszUserData;

    if (bnFirst) {

      bnFirst      = FALSE;
      poUniqueNode = poMaxNode;

      strUserDefined = strCurrDefined;
    }
    else {

      poUniqueNode = NULL;

      if (stricmp(ASCHAR(strUserDefined), ASCHAR(strCurrDefined))) {

        g_bnConflict   = TRUE;
        strUserDefined = "";
      }
    }

    g_swwCurrSel.insert(GetNodeId(poMaxNode));
  }

  SetEditorText(ASCHAR(strUserDefined));

  g_strOriginalText = strUserDefined;

  if (g_hWnd) {

    char szAux[512];

    if (!g_swwCurrSel.empty()) {

      if (poUniqueNode)
        sprintf(szAux, "Single selection:\r\n%s", poUniqueNode->GetName());
      else
        sprintf(szAux, "Multiple selection: %d Objects.\r\n%s",
          g_swwCurrSel.size(), g_bnConflict ? "CONFLICTING CONTENT!" : "Same content.");
    }
    else
      sprintf(szAux, "Nothing selected.");

    SetWindowText(GetDlgItem(g_hWnd, IDC_SELECTION_STATUS), szAux);
  }
}

void CommitChanges(Interface *poInterface) {

  string strCurrText = GetEditorText();

  if (!strcmp(ASCHAR(g_strOriginalText), ASCHAR(strCurrText)))
    return;

  if (g_bnConflict) {

    g_bnConflictDialogOpened = TRUE;

    if (MessageBox(poInterface->GetMAXHWnd(),
                   "Do you want to OVERWRITE the user-defined\r\ncontent of all the selected objects?",
                   "User-Defined Editor: CONFLICT DETECTED", MB_YESNO|MB_ICONEXCLAMATION) != IDYES) {

      SetEditorText("");
      g_bnConflictDialogOpened = FALSE;
      return;
    }

    g_bnConflictDialogOpened = FALSE;
  }

  BOOL bnWarnEmpty = (strCurrText.empty() ? TRUE : FALSE);

  for(set<ULONG>::iterator itswwNode = g_swwCurrSel.begin(); itswwNode != g_swwCurrSel.end(); itswwNode++) {

    INode *poMaxNode = GetNodeById(poInterface, *itswwNode);
    if (poMaxNode) {

      if (bnWarnEmpty) {

        bnWarnEmpty = FALSE;

        TSTR pszUserData;
        poMaxNode->GetUserPropBuffer(pszUserData);
        if (pszUserData[0] != '\0') {

          if (MessageBox(poInterface->GetMAXHWnd(),
                         "Do you confirm CLEANING the user-defined\r\ncontent of all the selected objects?",
                         "User-Defined Editor: CLEANING?", MB_YESNO|MB_ICONQUESTION) != IDYES) {

            RetrieveText(poInterface);
            return;
          }
        }
      }

      poMaxNode->SetUserPropBuffer(ASCHAR(strCurrText));
    }
  }

  g_strOriginalText = strCurrText;

  g_bnConflict = FALSE;
}

BOOL DetectSelectionChanged(Interface *poInterface) {

  set<ULONG> swwTmpSel;
  for(int nCount = 0; nCount < poInterface->GetSelNodeCount(); nCount++)
    swwTmpSel.insert(GetNodeId(poInterface->GetSelNode(nCount)));

  if (swwTmpSel.size() != g_swwCurrSel.size())
    return TRUE;

  set<ULONG>::iterator itswwCount1 = swwTmpSel.begin();
  set<ULONG>::iterator itswwCount2 = g_swwCurrSel.begin();
  for(; itswwCount1 != swwTmpSel.end(); itswwCount1++, itswwCount2++)
    if (*itswwCount1 != *itswwCount2)
      return TRUE;

  return FALSE;
}

Sci_CharacterRange GetSelection() {

  Sci_CharacterRange stRange;
  stRange.cpMin = SendEditor(SCI_GETSELECTIONSTART);
  stRange.cpMax = SendEditor(SCI_GETSELECTIONEND);
  return stRange;
}

void SetSelection(int nAnchor, int nCurrentPos) {

	SendEditor(SCI_SETSEL, nAnchor, nCurrentPos);
}

int DocLength() {

  return SendEditor(SCI_GETLENGTH);
}

void EnsureRangeVisible(int nPosStart, int nPosEnd, BOOL bnEnforcePolicy) {

  int nLineStart = SendEditor(SCI_LINEFROMPOSITION, MIN(nPosStart, nPosEnd));
  int nLineEnd   = SendEditor(SCI_LINEFROMPOSITION, MAX(nPosStart, nPosEnd));
  for(int nLine = nLineStart; nLine <= nLineEnd; nLine++)
    SendEditor(bnEnforcePolicy ? SCI_ENSUREVISIBLEENFORCEPOLICY : SCI_ENSUREVISIBLE, nLine);
}

int FindInTarget(char *pszFind, int nLenFind, int nStartPosition, int nEndPosition) {

  SendEditor(SCI_SETTARGETSTART, nStartPosition);
  SendEditor(SCI_SETTARGETEND,   nEndPosition);
  int nFind = SendEditor(SCI_SEARCHINTARGET, nLenFind, (LPARAM)pszFind);
  return nFind;
}

int FindNext(char *pszFind, BOOL bnReverse, BOOL bnWholeWord, BOOL bnMatchCase, BOOL bnWrapAround) {

  int nLenFind = strlen(pszFind);
  if (nLenFind == 0)
    return -1;

  Sci_CharacterRange stRange = GetSelection();

  int nStartPosition = stRange.cpMax;
  int nEndPosition   = DocLength();
  if (bnReverse) {

    nStartPosition = stRange.cpMin;
    nEndPosition   = 0;
  }

  DWORD wwFlags = (bnWholeWord ? SCFIND_WHOLEWORD : 0) |
                  (bnMatchCase ? SCFIND_MATCHCASE : 0);

  SendEditor(SCI_SETSEARCHFLAGS, wwFlags);

  int nFind = FindInTarget(pszFind, nLenFind, nStartPosition, nEndPosition);
  if (nFind == -1 && bnWrapAround) {

    if (bnReverse) {

      nStartPosition = DocLength();
      nEndPosition  = 0;
    }
    else {

      nStartPosition = 0;
      nEndPosition   = DocLength();
    }

    nFind = FindInTarget(pszFind, nLenFind, nStartPosition, nEndPosition);
  }

  if (nFind != -1) {

    int nStart = SendEditor(SCI_GETTARGETSTART);
    int nEnd   = SendEditor(SCI_GETTARGETEND);
    
    EnsureRangeVisible(nStart, nEnd, TRUE);

    SetSelection (nStart, nEnd);
    
    /*if (!replacing && closeFind) {

      DestroyFindReplace();
    }*/
  }

  return nFind;
}

char g_szFindWhat[512] = "";

INT_PTR CALLBACK FindDlgProc(HWND hWnd, UINT nMessage, WPARAM wParam, LPARAM lParam) {

  switch(nMessage) {

    case WM_INITDIALOG: {

      SetWindowText(GetDlgItem(hWnd, IDC_FIND_WHAT), g_szFindWhat);
    }
    break;

    case WM_CLOSE: {

      EndDialog(hWnd, LOWORD(wParam));
    }
    break;

    case WM_COMMAND: {

      switch(LOWORD(wParam)) {

        case IDOK: {

          GetWindowText(GetDlgItem(hWnd, IDC_FIND_WHAT), g_szFindWhat, sizeof(g_szFindWhat) - 1);
          FindNext(g_szFindWhat, FALSE, FALSE, FALSE, TRUE);

          EndDialog(hWnd, LOWORD(wParam));
        }
        break;

        case IDCANCEL: {

          EndDialog(hWnd, LOWORD(wParam));
        }
        break;
      }
    }
    break;
  }

  return 0;
}

BOOL g_bnShiftPress = FALSE;

BOOL g_bnDisableAcc = TRUE;

INT_PTR CALLBACK UDE_3dsmaxDlgProc(HWND hWnd, UINT nMessage, WPARAM wParam, LPARAM lParam) {

  static RECT s_stMinSize;

  switch(nMessage) {

    //case IDM_FIND:

    case WM_INITDIALOG: {

      SetWindowLong(hWnd, GWL_USERDATA, lParam);

      SetWindowText(GetDlgItem(hWnd, IDC_SELECTION_STATUS), "");

      GetWindowRect(hWnd, &s_stMinSize);

      RECT stRect;
      GetWindowRect(GetDlgItem(hWnd, IDC_EDITOR_SPACE), &stRect);

      POINT stPos;
      stPos.x = stPos.y = 0;
      MapWindowPoints(GetDlgItem(hWnd, IDC_EDITOR_SPACE), hWnd, &stPos, 1);

      g_hScintilla = CreateWindowEx(0, "Scintilla", "", WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN,
        stPos.x, stPos.y, stRect.right - stRect.left, stRect.bottom - stRect.top, hWnd, NULL, g_hInstance, NULL); 

      SendEditor(SCI_STYLESETFONT, STYLE_DEFAULT, (LPARAM)"Fixedsys");
      SendEditor(SCI_STYLESETSIZE, STYLE_DEFAULT, 10);
      SendEditor(SCI_STYLESETFORE, STYLE_DEFAULT, g_stColorDefault);
      SendEditor(SCI_STYLESETBACK, STYLE_DEFAULT, g_stColorBackground);

      SetAStyle(STYLE_DEFAULT, g_stColorDefault);

      SendEditor(SCI_SETSELFORE,   TRUE, ::GetSysColor(COLOR_HIGHLIGHTTEXT));
      SendEditor(SCI_SETSELBACK,   TRUE, ::GetSysColor(COLOR_HIGHLIGHT));
      SendEditor(SCI_SETCARETFORE,       g_stColorCursor);

      SendEditor(SCI_INDICSETSTYLE, STYLE_MARK, INDIC_ROUNDBOX);
      SendEditor(SCI_INDICSETFORE,  STYLE_MARK, g_stColorMark);
      SendEditor(SCI_INDICSETUNDER, STYLE_MARK, TRUE);

      SendEditor(SCI_SETVIRTUALSPACEOPTIONS, SCVS_RECTANGULARSELECTION | SCVS_USERACCESSIBLE);
      SendEditor(SCI_SETTABWIDTH,            2);
      SendEditor(SCI_SETUSETABS,             false);
      SendEditor(SCI_SETINDENT,              0); //same as SCI_SETTABWIDTH 

      SendEditor(SCI_SETFONTQUALITY, SC_EFF_QUALITY_LCD_OPTIMIZED);

      SendEditor(SCI_SETMARGINTYPEN, 0, SC_MARGIN_NUMBER);
      LRESULT nPix = SendEditor(SCI_TEXTWIDTH, STYLE_LINENUMBER, (LPARAM)"_9999");
      SendEditor(SCI_SETMARGINWIDTHN, 0, nPix);
      SendEditor(SCI_SETMARGINWIDTHN, 1);
      SendEditor(SCI_SETMARGINWIDTHN, 2);

      SendEditor(SCI_SETCURSOR, SC_CURSORNORMAL);

      SetupLexer();

      ShowWindow(g_hScintilla, SW_SHOW);
      SetFocus(g_hScintilla);
      
      //DisableAccelerators();

      ShowCursor(true);

      CenterWindow(hWnd, GetParent(hWnd));

      SetTimer(hWnd, 666, 250, (TIMERPROC)NULL);
    }
    return TRUE;

    case WM_TIMER: {

      if ((wParam == 666) && (g_hScintilla) && (g_poMaxInterface) && (!g_bnConflictDialogOpened)) {

        if (GetFocus() == g_hScintilla) {

          if (g_bnDisableAcc) {

            g_bnDisableAcc = FALSE;
            DisableAccelerators();
          }
        }
        else {

          if (!g_bnDisableAcc) {

            g_bnDisableAcc = TRUE;
            EnableAccelerators();
          }
        }

        if (DetectSelectionChanged(g_poMaxInterface)) {

          CommitChanges(g_poMaxInterface);
          RetrieveText (g_poMaxInterface);
        }
      }
    }
    return TRUE;

    case WM_SIZING: {

      LPRECT pstRect = (LPRECT)lParam;

      if (pstRect->right - pstRect->left < s_stMinSize.right - s_stMinSize.left)
        pstRect->right = pstRect->left + (s_stMinSize.right - s_stMinSize.left);

      if (pstRect->bottom - pstRect->top < s_stMinSize.bottom - s_stMinSize.top)
        pstRect->bottom = pstRect->top + (s_stMinSize.bottom - s_stMinSize.top);
    }
    return TRUE;

    case WM_SIZE: {

      if (g_hScintilla) {

        RECT stCurSize;
        GetWindowRect(hWnd, &stCurSize);

        int nAddWidth  = (stCurSize.right  - stCurSize.left) - (s_stMinSize.right  - s_stMinSize.left);
        int nAddHeight = (stCurSize.bottom - stCurSize.top)  - (s_stMinSize.bottom - s_stMinSize.top);

        RECT stRect;
        GetWindowRect(GetDlgItem(hWnd, IDC_EDITOR_SPACE), &stRect);

        POINT stPos;
        stPos.x = stPos.y = 0;
        MapWindowPoints(GetDlgItem(hWnd, IDC_EDITOR_SPACE), hWnd, &stPos, 1);

        MoveWindow(g_hScintilla, stPos.x, stPos.y, stRect.right - stRect.left + nAddWidth, stRect.bottom - stRect.top + nAddHeight, true);
      }
    }
    return TRUE;

    case WM_CLOSE: {

      EndDialog(hWnd, 0);

      g_hWnd       = NULL;
      g_hScintilla = NULL;
      g_swwCurrSel.clear();
    }
    return TRUE;

    case WM_DESTROY: {

      g_hWnd       = NULL;
      g_hScintilla = NULL;
      g_swwCurrSel.clear();
    }
    break;

    case WM_NOTIFY: {

      NMHDR *lpnmhdr = (LPNMHDR)lParam;
      if(lpnmhdr->hwndFrom == g_hScintilla) {

        //DisableAccelerators();

        SCNotification *pstSN = (SCNotification *)lParam;
        switch(lpnmhdr->code) {

          case SCN_CHARADDED: {

            /*if (pstSN->ch == 6) { //Ctrl+F

              DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_FIND), hWnd, FindDlgProc, NULL);
              SendEditor(SCI_UNDO);
              return 1;
            }*/
          }
          break;

          case SCN_KEY: {

            int nAux = pstSN->ch;
          }
          break;

          /*case SCEN_SETFOCUS: {

            DisableAccelerators();
          }
          break;

          case SCEN_KILLFOCUS: {

            EnableAccelerators();
          }
          break;*/
        }
      }
    }
    break;

    case WM_COMMAND: {

      switch(HIWORD(wParam)) {

        case 0: { //Menu...

          switch(LOWORD(wParam)) {

            case IDM_FIND:
              DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_FIND), hWnd, FindDlgProc, NULL);
            break;
          }
        }
        break;

        /*case EN_SETFOCUS: {

          if (((HWND)lParam == g_hWnd) || ((HWND)lParam == g_hScintilla)) {

            DisableAccelerators();
            return TRUE;
          }
        }
        break;

        case EN_KILLFOCUS: {

          if (((HWND)lParam == g_hWnd) || ((HWND)lParam == g_hScintilla)) {

            EnableAccelerators();
            return TRUE;
          }
        }*/
      }
    }
    break;

    case WM_KEYDOWN: {

      switch(wParam) {

        case VK_F3:

          if (g_szFindWhat[0] == '\0') {

            DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_FIND), hWnd, FindDlgProc, NULL);
          }
          else {

            if (!g_bnShiftPress)
              FindNext(g_szFindWhat, FALSE, FALSE, FALSE, TRUE);
            else
              FindNext(g_szFindWhat, TRUE, FALSE, FALSE, TRUE);
          }

        break;

        case VK_SHIFT:
        case VK_RSHIFT:
          g_bnShiftPress = TRUE;
        break;
      }
    }
    break;

    case WM_KEYUP: {

      switch(wParam) {

        case VK_SHIFT:
        case VK_RSHIFT:
          g_bnShiftPress = FALSE;
        break;
      }
    }
    break;

    case WM_NCACTIVATE: {

      if (!wParam) {

        if (!g_bnConflictDialogOpened)
          CommitChanges(g_poMaxInterface);
      }
    }
    break;
  }

  return 0;
}

void UDE_3dsmax::BeginEditParams(Interface* poInterface, IUtil* iu) {

  g_hInstance      = hInstance;
  g_poMaxInterface = poInterface;
  g_poUtilUI       = iu;

  if (!g_bnScintillaInit) {

    if (LoadLibrary("SciLexer.dll")) {

      g_bnScintillaInit = true;
    }
    else {

      if (LoadLibrary("SciLexer.dll")) {

        g_bnScintillaInit = true;
      }
      else {

        MessageBox(GetDesktopWindow(), "The Scintilla DLL could not be loaded.", "Error loading Scintilla", MB_OK | MB_ICONERROR);
        return;
		  }
    }
  }

  if (!g_hWnd)
    g_hWnd = CreateDialogParam(g_hInstance, MAKEINTRESOURCE(IDD_PANEL), GetActiveWindow(), UDE_3dsmaxDlgProc, (LPARAM)this);
  else
    SetActiveWindow(g_hWnd);
}
	
UDE_3dsmax::UDE_3dsmax() {

  //unify memory function pointers (3dsmax + Toolbox)
  Toolbox_malloc  = (void *(__cdecl *)(size_t))malloc;
  Toolbox_calloc  = (void *(__cdecl *)(size_t,size_t))calloc;
  Toolbox_realloc = (void *(__cdecl *)(void*,size_t))realloc;
  Toolbox_free    = (void (__cdecl *)(void *))free;
}

UDE_3dsmax::~UDE_3dsmax() {

  g_poUtilUI       = NULL;
  g_poMaxInterface = NULL;
}

void UDE_3dsmax::DeleteThis() {
}
