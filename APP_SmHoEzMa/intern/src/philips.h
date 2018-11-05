#ifndef Philips_H
#define Philips_H

#include <QObject>
#include <QNetworkReply>

class CPhilips:public QObject
{
    Q_OBJECT
public:
    CPhilips(QObject *parent = 0);
    CPhilips(QObject *parent,
                         bool   _swtichedOn,
                         int    _brightness,
                         int    _saturation,
                         int    _lampnumber,
                         QString _ip);

    void        switchOn();
    void        switchOff();
    void        setBrightness(int _brightness);
    void        setSaturation(int _saturation);
    QString     callBridge(QJsonDocument _body);
    QString     callBridge();

    bool        getOnOffState();
    int         getBrightness();
    int         getSaturation();

    QString     getAPICall() const;

    void        setStates();

    QString getIp() const;
    void setIp(const QString &ip);

    int getLampNumber() const;
    void setLampNumber(int lampNumber);

private:
    QNetworkAccessManager   manager;
    QNetworkReply*          reply;

    bool    m_actualSwitchedOn;
    int     m_actualBrightness;
    int     m_actualSaturation;

    bool    m_switchedOn;
    int     m_brightness;
    int     m_saturation;
    bool    m_colorloop;
    int     m_lampNumber;
    QString m_replyMessage;

    QString  m_ip               = "192.168.178.64";
    QString  m_APICall          = QString("http://")+m_ip+":8000/api/newdeveloper/lights/"+QString::number(m_lampNumber)+"/state";
    QString  m_APICallForGet    = QString("http://")+m_ip+":8000/api/newdeveloper/lights/"+QString::number(m_lampNumber)+"/";


private:
    void        updateAPICall();
    void        updateValues();

private slots:
    void        waitForReply();

};

#endif // Philips_H
