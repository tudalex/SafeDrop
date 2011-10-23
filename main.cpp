#include <QtGui/QApplication>
#include <QSystemTrayIcon>
#include <QFileSystemWatcher>
#include <QDebug>
#include <QDir>
//#include <QStringList>
#include "watch.h"

QStringList recurse_get(const QString &path);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
   // w.show();

    Watch *watch = new Watch();
    QFileSystemWatcher *fswatch = new QFileSystemWatcher();
    fswatch->addPaths(recurse_get("C:/work"));
    foreach (QString str, fswatch->files())
        qDebug()<<"File: "<<str;
    foreach (QString str, fswatch->directories())
        qDebug()<<"Folder: "<<str;

    QObject::connect(fswatch, SIGNAL(fileChanged(QString)), watch, SLOT(fileChanged(QString)));
    QObject::connect(fswatch, SIGNAL(directoryChanged(QString)), watch, SLOT(fileChanged(QString)));


    return a.exec();
}

QStringList recurse_get(const QString &path)
{
    QStringList list;
    QDir dir(path);

    foreach (QString s, dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        QStringList temp = recurse_get(dir.absoluteFilePath(s));
        list<<temp; //Processing all folders first
        qDebug()<<"Folder: "<<s<<" Path: "<<dir.absoluteFilePath(s);
    }

    foreach (QString s, dir.entryList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot))
    {
        list<<dir.absoluteFilePath(s);
        qDebug()<<"File: "<<s<<" Path: "<<dir.absoluteFilePath(s);
    }
    return list<<path;
}
