#ifndef WATCH_H
#define WATCH_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QDir>

class Watch : public QObject
{
    Q_OBJECT
public:
    explicit Watch(QObject *parent = 0);

signals:

public slots:
    void fileChanged(QString);
    void folderChanged(QString);

private:
    QSystemTrayIcon * m_tray;
    QFileSystemWatcher *fswatch;
    QStringList recurse_get(const QString &path, bool recurse = true);
    QString root_path, mirror_path;
};

#endif // WATCH_H
