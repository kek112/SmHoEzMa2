#ifndef TEMPERERATURSENSOR_H
#define TEMPERERATURSENSOR_H

#include <QObject>
#include <QNetworkReply>

class CTemperatureSensor : public QObject
{
    Q_OBJECT
public:
    ////
    /// sensordaten in pushdown menü
    ///
    CTemperatureSensor(int    _sensorNumber,
                    QString _ip);

public:
    int getTemperature();

private:
    int                     m_sensorNumber;
    QString                 m_replyMessage;
    QNetworkAccessManager   manager;
    QNetworkReply*          reply;


    QString  m_ip       = "192.168.178.64";
    QString  m_APICall  = QString("http://")+m_ip+":45455/api/Thermo/"+QString::number(m_sensorNumber);

private:
    void        updateAPICall();

private slots:
    void        waitForReply();

};
#endif // TEMPERERATURSENSOR_H
