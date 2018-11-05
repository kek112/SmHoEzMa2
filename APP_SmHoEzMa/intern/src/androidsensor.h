#ifndef ANDROIDSENSOR_H
#define ANDROIDSENSOR_H

#include <QDebug>
#include <QNmeaPositionInfoSource>

class CAndroidSensor : QObject
{
    Q_OBJECT
public:
    CAndroidSensor(QObject *parent = 0);

    QGeoCoordinate getGPSLocation();

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
    void setGPSLocation(QGeoPositionInfo geoPositionInfo);

private:
    QGeoPositionInfoSource* locationInfo_;

    QGeoCoordinate m_Coordinates;
};

#endif // ANDROIDSENSOR_H
