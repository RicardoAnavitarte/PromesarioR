#include "dialog.h"
#include "readall.h"
#include "widget.h"
#include <QApplication>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication::setStyle("Plastique");
    a.setApplicationName("PromesarioAnisoft");
    a.setOrganizationName("Anisoft");
    a.setOrganizationDomain("www.Anisoft.com");
    a.setApplicationVersion("8.2");
    a.setStyle("fusion");

   Dialog w;
    //Widget w;
    w.show();

    return a.exec();
}
