#include "watch.h"


Watch::Watch(QObject *parent) :
    QObject(parent)
{
    root_path= QString("C:/work");
    mirror_path = QString("C:/work2");
    //TODO: Only works wit absolute paths
    m_tray = new QSystemTrayIcon();
    m_tray->show();
    fswatch = new QFileSystemWatcher();
    fswatch->addPaths(recurse_get(root_path));
    connect(fswatch, SIGNAL(fileChanged(QString)),this, SLOT(fileChanged(QString)));
    connect(fswatch, SIGNAL(directoryChanged(QString)), this, SLOT(folderChanged(QString)));
}

void Watch::fileChanged(QString file)
{
    m_tray->showMessage("File Changed", file);
    qDebug()<<"File changed: "<<file;
    QString relative_path = QString(file).remove(0,root_path.size());
    qDebug()<<"file: "<<file<<"relative path: "<<relative_path <<"full new path: "<< QString(mirror_path).append(relative_path);
    QFile::remove(QString(mirror_path).append(relative_path));
    qDebug()<<"Copying returned: "<<QFile::copy(file,QString(mirror_path).append(relative_path));
}

void Watch::folderChanged(QString folder)
{
    m_tray->showMessage("Folder Changed", folder );
    fswatch->addPaths(recurse_get(folder, false));
    qDebug()<<"Folder changed: "<<folder;

}


QStringList Watch::recurse_get(const QString &path, bool recurse )
{
    QStringList list;
    QDir dir(path);
    if (recurse)
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

