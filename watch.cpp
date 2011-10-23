#include "watch.h"


Watch::Watch(QObject *parent) :
    QObject(parent)
{
    m_tray = new QSystemTrayIcon();
    m_tray->show();
}

void Watch::fileChanged(QString file)
{
    m_tray->showMessage("File Changed", file);
    qDebug()<<"File changed: "<<file;

}

