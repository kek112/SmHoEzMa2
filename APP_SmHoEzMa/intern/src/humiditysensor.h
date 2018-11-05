#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include <QObject>
#include <QNetworkReply>

class CHumiditySensor : public QObject
{
    Q_OBJECT
public:
    ////
    /// sensordaten in pushdown menü
    ///
    CHumiditySensor(int    _sensorNumber,
                    QString _ip);

public:
    int getHumidity();

private:
    int                     m_sensorNumber;
    QString                 m_replyMessage;
    QNetworkAccessManager   manager;
    QNetworkReply*          reply;


    QString  m_ip       = "192.168.178.64";
    QString  m_APICall  = QString("http://")+m_ip+":45455/api/Humidity/"+QString::number(m_sensorNumber);

private:
    void        updateAPICall();

private slots:
    void        waitForReply();

};

#endif // HUMIDITYSENSOR_H
