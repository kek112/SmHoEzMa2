#include "devicestructure.h"

#include <QStandardPaths>
#include <QtXml>

///
/// This class represents the structure of devices how they will be handled in the app and will be saved
/// as XML
/// die ENUM Edevices is used to call the class for each device
/// this class will also save/load all devices
///
/// it also adds/deletes devices to the list which can can be used to manage all saved devices
///

///
/// \brief CDeviceStructure::CDeviceStructure
///

///todo program funtkion
CDeviceStructure::CDeviceStructure()
{
    load();
    save();
}

CDeviceStructure::~CDeviceStructure()
{
    save();
}


///todo program funtkion

///
/// \brief CDeviceStructure::save
/// safe the device lsit into xml file with the scheme
///
///
/// <Devices>
/// <Name=””, IpAddress=””, MacAddress=””,DeviceType=””, DeviceNumber="">
/// <Name=””, IpAddress=””, MacAddress=””,DeviceType=””, DeviceNumber="">
/// <Name=””, IpAddress=””, MacAddress=””,DeviceType=””, DeviceNumber="">
/// </Devices>
///
///
///
/// \return
///
bool CDeviceStructure::save()
{
    QFile file(m_FileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;


    QDomDocument doc;
    QDomElement xmldevice = doc.createElement( "Devices" );

    foreach (Device tempdevice, m_Devices)
    {
        xmldevice.setAttribute(m_XmlNameString,         tempdevice.m_Name);
        xmldevice.setAttribute(m_XmlIpAdressString,     tempdevice.m_IpAddress.toString());
        xmldevice.setAttribute(m_XmlMacAddressString,   tempdevice.m_MacAddress);
        xmldevice.setAttribute(m_XmlDeviceNumber,       tempdevice.m_DeviceNumber);
        xmldevice.setAttribute(m_XmlDeviceTypeString,   tempdevice.m_DeviceType);
        xmldevice.setAttribute(m_XmlActive,             tempdevice.m_HomecomingActive ? 1 : 0);
        xmldevice.setAttribute(m_XmlLatitude,           QString::number(tempdevice.m_Coordinate.latitude()));
        xmldevice.setAttribute(m_XmlLongitude,          QString::number(tempdevice.m_Coordinate.longitude()));

        doc.appendChild(xmldevice);
    }
    QTextStream out(&file);
    out<<xmldevice;
    return true;
}

///
/// \brief CDeviceStructure::load
/// load all devices from xml into struct
/// best when called first so u have a device list :)
/// check if xml exists
/// \return
///
bool CDeviceStructure::load()
{
    QDomDocument document;
    QFile file (QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation)[0] + m_FileName);

    // Open a file for reading
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading.";
        return -1;
    }
    else
    {
        // loading
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load the file for reading.";
            return -1;
        }
        file.close();
    }

    // Getting root element
    QDomElement root = document.firstChildElement();

    // retrievelements(QDomElement root, QString tag, QString att)
    m_Devices = retrieveElements(root, "Devices");

}

///
/// \brief CDeviceStructure::returnDevices
/// returns all devices which are currently saved in the structure
/// \return
/// returns all devices which are currently saved in the structure :=)
///
QList<CDeviceStructure::Device> CDeviceStructure::returnDevices()
{
    return m_Devices;
}

///
/// \brief CDeviceStructure::addDevices
/// add one device to your list
/// create new struct and add it to list
/// checks if the name is already taken :)
/// \return
/// after check has failed it will return false otherwise
/// new struct is added and true will be returned
///
bool CDeviceStructure::addDevices(QString           _Name,
                                    QHostAddress    _IpAddress,
                                    QString         _MacAddress,
                                    EDevices        _DeviceType,
                                    int             _DeviceNumber,
                                    bool            _Active,
                                    QGeoCoordinate  _Coordinate)
{
    Device device;

    //check if list filled with at least one element otherwise just append it
    if(!m_Devices.isEmpty())
    {
        //go through every device in the list to check for existing name
        for (auto tempdevice : m_Devices)
        {
            if(tempdevice.m_Name == _Name)
            {
                return false;
            }
        }
        device.m_Name           = _Name;
        device.m_IpAddress      = _IpAddress;
        device.m_MacAddress     = _MacAddress;
        device.m_DeviceType     = _DeviceType;
        device.m_DeviceNumber   = _DeviceNumber;
        device.m_HomecomingActive         = _Active;
        device.m_Coordinate     = _Coordinate;

        m_Devices.append(device);
        return true;
    }else
    {
        device.m_Name           = _Name;
        device.m_IpAddress      = _IpAddress;
        device.m_MacAddress     = _MacAddress;
        device.m_DeviceType     = _DeviceType;
        device.m_DeviceNumber   = _DeviceNumber;
        device.m_HomecomingActive         = _Active;
        device.m_Coordinate     = _Coordinate;

        m_Devices.append(device);
        return true;
    }


}

bool CDeviceStructure::addDevices(CDeviceStructure::Device _device)
{
    m_Devices.append(_device);
}

void CDeviceStructure::ClearDevices()
{
    m_Devices.clear();
}

///
/// \brief CDeviceStructure::deleteDevice
/// delete one specific device with the name
/// \return
/// will return true if name exists in lsist otherwise false :)
///
bool CDeviceStructure::deleteDevice(QString _Name)
{
    int cunter=0;
    //check if list filled with at least one element
    if(!m_Devices.isEmpty())
    {
            //go through every device in the list to check for existing name
        for (auto tempdevice : m_Devices)
        {
            cunter++;
            if(tempdevice.m_Name == _Name)
            {
                m_Devices.removeAt(cunter);
                return true;
            }
        }
    }
    return false;
}

bool CDeviceStructure::deleteDevice(int _Index)
{
    if(!m_Devices.isEmpty())
    {
        if(_Index>=m_Devices.size())
            return false;
        m_Devices.removeAt(_Index);
        return true;
    }else
    {
        return false;
    }

}
///
/// \brief retrievElements
/// runs through all nodes under the tag and puts them into the device list
/// \param root
/// needs root element from where to start
/// \param tag
/// specify which node is important
/// <Devices>
/// <Name=””, IpAddress=””, MacAddress=””,DeviceType=””, DeviceNumber="">
/// <Name=””, IpAddress=””, MacAddress=””,DeviceType=””, DeviceNumber="">
/// <Name=””, IpAddress=””, MacAddress=””,DeviceType=””, DeviceNumber="">
/// </Devices>
/// this is the needed scheme so the function can work properly
/// \return
/// returns list created from the nodes
QList<CDeviceStructure::Device> CDeviceStructure::retrieveElements(QDomElement root, QString tag)
{

    QList<Device> devicelist;
    QDomNodeList nodes = root.elementsByTagName(tag);

    //qDebug() << "# nodes = " << nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();

            Device device;

            device.m_Name           = e.attribute(m_XmlNameString);
            device.m_IpAddress      = e.attribute(m_XmlIpAdressString);
            device.m_MacAddress     = e.attribute(m_XmlMacAddressString);
            device.m_DeviceType     = static_cast<EDevices>(e.attribute(m_XmlDeviceTypeString).toInt());
            device.m_DeviceNumber   = e.attribute(m_XmlDeviceNumber).toInt();
            device.m_HomecomingActive         = e.attribute(m_XmlActive) == 0 ? false : true;
            device.m_Coordinate     = QGeoCoordinate(e.attribute(m_XmlLatitude).toDouble(), e.attribute(m_XmlLongitude).toDouble());

            devicelist.append(device);
        }
    }
    return devicelist;
}
