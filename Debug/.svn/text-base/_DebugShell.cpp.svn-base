//===========================================================================================================================================
/// \file   _DebugShell.cpp
/// \brief  Main file when adding framework's debug shell support to an application.
/// \author Christian Lykawka
/// \date   04.05.2011
//===========================================================================================================================================

#define _DEBUG_SHELL_CPP_

#include "_DebugShell.h"

#include "DebugShell/DebugShellApp.h"
#include "DebugShell/DebugShellHub.h"

namespace aer {

//start debug shell for an application
BOOL DebugShellStartApp(char *pszHubAddress, char *pszErrMsg) {

  new CDebugShellApp; //creates the app singleton...
  return DEBUG_SHELL_APP->Init(pszHubAddress, pszErrMsg);
}

//start debug shell hub
BOOL DebugShellStartHub(char *pszAddress, char *pszErrMsg) {

  new CDebugShellHub; //creates the hub singleton...
  return DEBUG_SHELL_HUB->Init(pszAddress, pszErrMsg);
}

//update debug shell per frame
void DebugShellUpdate(IDebugShellUpdate *poInterface) {

  if (DEBUG_SHELL)
    DEBUG_SHELL->Update(poInterface);
}

}//end of namespace
