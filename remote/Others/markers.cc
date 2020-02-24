int SciTEBase::MarkAll() {
	int posCurrent = wEditor.Call(SCI_GETCURRENTPOS);
	int marked = 0;
	int posFirstFound = FindNext(false, false);

	SString findMark = props.Get("find.mark");
	if (findMark.length()) {
		wEditor.Call(SCI_SETINDICATORCURRENT, indicatorMatch);
		RemoveFindMarks();
		CurrentBuffer()->findMarks = Buffer::fmMarked;
	}
	if (posFirstFound != -1) {
		int posFound = posFirstFound;
		do {
			marked++;
			int line = wEditor.Call(SCI_LINEFROMPOSITION, posFound);
			BookmarkAdd(line);
			if (findMark.length()) {
				wEditor.Call(SCI_INDICATORFILLRANGE, 
				posFound, wEditor.Call(SCI_GETTARGETEND) - posFound);
			}
			posFound = FindNext(false, false);
		} while ((posFound != -1) && (posFound != posFirstFound));
	}
	wEditor.Call(SCI_SETCURRENTPOS, posCurrent);
	return marked;
}
void SciTEBase::BookmarkAdd(int lineno) {
	if (lineno == -1)
		lineno = GetCurrentLineNumber();
	if (!BookmarkPresent(lineno))
		wEditor.Call(SCI_MARKERADD, lineno, markerBookmark);
}

wEditor.Call(SCI_SETINDICATORCURRENT, indicatorHightlightCurrentWord);
wEditor.Call(SCI_INDICATORCLEARRANGE, 0, wEditor.Call(SCI_GETLENGTH));
wOutput.Call(SCI_SETINDICATORCURRENT, indicatorHightlightCurrentWord);
wOutput.Call(SCI_INDICATORCLEARRANGE, 0, wOutput.Call(SCI_GETLENGTH));
currentWordHighlight.statesOfDelay = currentWordHighlight.noDelay;

currentWordHighlight.isEnabled = props.GetInt("highlight.current.word", 0) == 1;
if (currentWordHighlight.isEnabled) {
	SString highlightCurrentWordColourString = props.Get("highlight.current.word.colour");
	if (highlightCurrentWordColourString.length() == 0) {
		// Set default colour for highlight.
		highlightCurrentWordColourString = "#A0A000";
	}
	Colour highlightCurrentWordColour = ColourFromString(highlightCurrentWordColourString);

	wEditor.Call(SCI_INDICSETSTYLE, indicatorHightlightCurrentWord, INDIC_ROUNDBOX);
	wEditor.Call(SCI_INDICSETFORE, indicatorHightlightCurrentWord, highlightCurrentWordColour);
	wOutput.Call(SCI_INDICSETSTYLE, indicatorHightlightCurrentWord, INDIC_ROUNDBOX);
	wOutput.Call(SCI_INDICSETFORE, indicatorHightlightCurrentWord, highlightCurrentWordColour);
	currentWordHighlight.isOnlyWithSameStyle = props.GetInt("highlight.current.word.by.style", 0) == 1;
	HighlightCurrentWord(true);
}

void SciTEBase::HighlightCurrentWord(bool highlight) {
	if (!currentWordHighlight.isEnabled)
		return;
	GUI::ScintillaWindow &wCurrent = wOutput.HasFocus() ? wOutput : wEditor;
	// Remove old indicators if any exist.
	wCurrent.Call(SCI_SETINDICATORCURRENT, indicatorHightlightCurrentWord);
	int lenDoc = wCurrent.Call(SCI_GETLENGTH);
	wCurrent.Call(SCI_INDICATORCLEARRANGE, 0, lenDoc);
	if (!highlight)
		return;
	// Get start & end selection.
	int selStart = wCurrent.Call(SCI_GETSELECTIONSTART);
	int selEnd = wCurrent.Call(SCI_GETSELECTIONEND);
	bool noUserSelection = selStart == selEnd;
	SString wordToFind = RangeExtendAndGrab(wCurrent, selStart, selEnd,
	        &SciTEBase::islexerwordcharforsel);
	if (wordToFind.length() == 0 || wordToFind.contains('\n') || wordToFind.contains('\r'))
		return; // No highlight when no selection or multi-lines selection.
	if (noUserSelection && currentWordHighlight.statesOfDelay == currentWordHighlight.noDelay) {
		// Manage delay before highlight when no user selection but there is word at the caret.
		currentWordHighlight.statesOfDelay = currentWordHighlight.delay;
		// Reset timer
		currentWordHighlight.elapsedTimes.Duration(true);
		return;
	}
	// Get style of the current word to highlight only word with same style.
	int selectedStyle = wCurrent.Call(SCI_GETSTYLEAT, selStart);

	// Case sensitive & whole word only.
	wCurrent.Call(SCI_SETSEARCHFLAGS, SCFIND_MATCHCASE | SCFIND_WHOLEWORD);
	wCurrent.Call(SCI_SETTARGETSTART, 0);
	wCurrent.Call(SCI_SETTARGETEND, lenDoc);
	// Find the first occurrence of word.
	int indexOf = wCurrent.CallString(SCI_SEARCHINTARGET,
	        wordToFind.length(), wordToFind.c_str());
	while (indexOf != -1 && indexOf < lenDoc) {
		if (!currentWordHighlight.isOnlyWithSameStyle || selectedStyle ==
		        wCurrent.Call(SCI_GETSTYLEAT, indexOf)) {
			wCurrent.Call(SCI_INDICATORFILLRANGE, indexOf, wordToFind.length());
		}
		// Try to find next occurrence of word.
		wCurrent.Call(SCI_SETTARGETSTART, indexOf + wordToFind.length() + 1);
		wCurrent.Call(SCI_SETTARGETEND, lenDoc);
		indexOf = wCurrent.CallString(SCI_SEARCHINTARGET, wordToFind.length(),
		        wordToFind.c_str());
	}
}

C:\Documents and Settings\William\Meus documentos\SciTE\scite\src\SciTEProps.cxx
