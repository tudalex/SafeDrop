#ifndef WATCH_H
#define WATCH_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QDebug>

class Watch : public QObject
{
    Q_OBJECT
public:
    explicit Watch(QObject *parent = 0);

signals:

public slots:
    void fileChanged(QString);

private:
    QSystemTrayIcon * m_tray;
};

#endif // WATCH_H
