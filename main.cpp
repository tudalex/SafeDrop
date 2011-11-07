#include <QtGui/QApplication>
#include <QSystemTrayIcon>
#include <QFileSystemWatcher>
#include <QDebug>
#include <QDir>
//#include <QStringList>
#include "watch.h"
#include "googleservicesauth.h"
#include <QtWebKit>
QStringList recurse_get(const QString &path);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
   // w.show();

    Watch *watch = new Watch();
    GoogleServicesAuth * auth = new GoogleServicesAuth();


    return a.exec();
}
