#define _APP_MAIN_CPP_

#include "aeroshell.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Toolbox_malloc  = (void *(__cdecl *)(size_t))malloc;
    Toolbox_calloc  = (void *(__cdecl *)(size_t,size_t))calloc;
    Toolbox_realloc = (void *(__cdecl *)(void*,size_t))realloc;
    Toolbox_free    = (void (__cdecl *)(void *))free;

    QApplication a(argc, argv);
    AERoshell *poAERoshell = new AERoshell(&a);
    int nReturnCode = a.exec();
    delete poAERoshell;

    return nReturnCode;
}
