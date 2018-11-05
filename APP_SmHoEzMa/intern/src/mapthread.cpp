#include "mapthread.h"

CMapThread::CMapThread(CDeviceStructure _Devices, QObject *parent)
    : QObject(parent)
    , m_Devices(_Devices)
{

}

void CMapThread::StopThread()
{
    m_StopThread = true;
}

void CMapThread::UpdateDeviceStructure(CDeviceStructure _Devices)
{
    m_Devices = _Devices;
}

void CMapThread::checkGPS()
{
    m_StopThread = false;
    forever
    {
        if(m_StopThread)
            return;

        QGeoCoordinate coordinate = m_GPS.getGPSLocation();

        int deviceNumber = 0;

        for(auto device : m_Devices.returnDevices())
        {
            if(m_StopThread)
                return;

            if(device.m_HomecomingActive && m_HomeCoordinate.distanceTo(coordinate) < 100)
            {
                emit reachedHome(deviceNumber);
            }
            deviceNumber++;
        }
    }
}

void CMapThread::SetHome(QGeoCoordinate _coordinate)
{
    m_HomeCoordinate = _coordinate;
}
