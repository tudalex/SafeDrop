#ifndef GOOGLESERVICESAUTH_H
#define GOOGLESERVICESAUTH_H

#include <QObject>
#include <QtWebKitWidgets>

class GoogleServicesAuth : public QObject
{
    Q_OBJECT
public:
    explicit GoogleServicesAuth(QObject *parent = 0);

signals:

public slots:
    void newurl(QString);
private:
    QWebView * view;
};

#endif // GOOGLESERVICESAUTH_H
