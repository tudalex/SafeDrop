#include "googleservicesauth.h"
#include <QDebug>

GoogleServicesAuth::GoogleServicesAuth(QObject *parent) :
    QObject(parent)
{
    view = new QWebView();
    view->load(QUrl("https://accounts.google.com/o/oauth2/auth?client_id=406812157823.apps.googleusercontent.com&redirect_uri=urn:ietf:wg:oauth:2.0:oob&scope=https://docs.google.com/feeds/&response_type=code"));

    connect(view, SIGNAL(titleChanged(QString)), this, SLOT(newurl(QString)));
    view->show();
}

void GoogleServicesAuth::newurl(QString url)
{
    qDebug()<<"url is: "<<url;

}
