#ifndef MAPTHREAD_H
#define MAPTHREAD_H

#include "androidsensor.h"
#include "devicestructure.h"

#include <QObject>

class CMapThread : public QObject
{
    Q_OBJECT

    //TODO: finsh mapThread (when an object gets deleted there is a posibility that the thread trys to access it)
    //whenever a device is added or removed the worker function gets stoped (flag in function) then a copy of the device list is send to the worker and the function gets restarted
public:
    explicit CMapThread(CDeviceStructure _Devices, QObject *parent = nullptr);

signals:
    void reachedHome(int _device);

public slots:
    void StopThread();
    void UpdateDeviceStructure(CDeviceStructure _Devices);
    void checkGPS();
    void SetHome(QGeoCoordinate _coordinate);

private:
    bool m_StopThread;

    CDeviceStructure m_Devices;

    CAndroidSensor m_GPS;
    QGeoCoordinate m_HomeCoordinate;
};

#endif // MAPTHREAD_H
