#ifndef DEVICESTRUCTURE_H
#define DEVICESTRUCTURE_H

#include <QString>
#include <QHostAddress>
#include <QtXml>
#include <QGeoCoordinate>

class CDeviceStructure
{

public:

    ///
    /// \brief The EDevices enum
    /// this will decide which options are displayed on the view and which classes are to be created
    ///
    enum EDevices
    {
        PHILIPLSCLOLORLAMP,
        PHILIPLSLUXLAMP,
        TEMPERATURESENSOR,
        HUMIDITYSENSOR
    };

public:
    struct Device
    {
      QString           m_Name;
      QHostAddress      m_IpAddress;
      QString           m_MacAddress;
      EDevices          m_DeviceType;
      int               m_DeviceNumber;
      bool              m_HomecomingActive;
      QGeoCoordinate    m_Coordinate;
    };


public:
    CDeviceStructure();
    ~CDeviceStructure();
    bool save();
    bool load();
    bool deleteDevice(int _Index);
    bool deleteDevice(QString _Name);
    bool addDevices(QString         _Name,
                    QHostAddress    _IpAddress,
                    QString         _MacAddress,
                    EDevices        _DeviceType,
                    int             _DeviceNumber,
                    bool            _Active,
                    QGeoCoordinate  _Coordinate);
    bool addDevices(Device _device);
    void ClearDevices();


    QList<Device> returnDevices();
    QList<Device> retrieveElements(QDomElement root, QString tag);


private:
    QList<Device> m_Devices;

    QString m_FileName              = "devicelist.xml";

    QString m_XmlNameString         = "Name";
    QString m_XmlIpAdressString     = "IpAddress";
    QString m_XmlMacAddressString   = "MacAddress";
    QString m_XmlDeviceTypeString   = "DeviceType";
    QString m_XmlDeviceNumber       = "DeviceNumber";
    QString m_XmlActive             = "Active";
    QString m_XmlLatitude           = "Latitude";
    QString m_XmlLongitude          = "Longitude";




};

Q_DECLARE_METATYPE(CDeviceStructure::EDevices)

#endif // DEVICESTRUCTURE_H
