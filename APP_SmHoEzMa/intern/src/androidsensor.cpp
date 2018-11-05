#include "androidsensor.h"
///
/// \brief CAndroidSensor::CAndroidSensor
/// \param parent
/// this class is used to call the different sensors of the android phone
/// only used for GPS at the moment
///
CAndroidSensor::CAndroidSensor(QObject *parent)
    : QObject(parent)
{
    //        qDebug()<<QGeoPositionInfoSource::availableSources();
    //        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    //        if (source) {
    //            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
    //                    this, SLOT(positionUpdated(QGeoPositionInfo)));
    //            source->startUpdates();
    //        }

    // obtain the location data source
    locationInfo_ = QGeoPositionInfoSource::createDefaultSource(this);

    // select positioning method
    locationInfo_->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);

    // when the position has changed the setGPSLocation slot is called
    connect(locationInfo_, SIGNAL(positionUpdated(QGeoPositionInfo)),
            this, SLOT(setGPSLocation(QGeoPositionInfo)));

    // start listening for position updates
    locationInfo_->startUpdates();
}

QGeoCoordinate CAndroidSensor::getGPSLocation()
{
    return m_Coordinates;
}

void CAndroidSensor::positionUpdated(const QGeoPositionInfo &info)
{
    qDebug() << "Position updated:" << info;
}

void CAndroidSensor::setGPSLocation(QGeoPositionInfo geoPositionInfo)
{
    m_Coordinates = geoPositionInfo.coordinate();

//    QString text="Location=unknown";

//    if (geoPositionInfo.isValid())
//    {
//        // get the current location coordinates
//        QGeoCoordinate geoCoordinate = geoPositionInfo.coordinate();

//        // transform coordinates to lat/lon
//        qreal latitude = geoCoordinate.latitude();
//        qreal longitude = geoCoordinate.longitude();

//        text=QString("Latitude=%1\nLongitude=%2")
//                .arg(latitude,0,'g',8)
//                .arg(longitude,0,'g',8);
//    }
//    qDebug()<<text;

}
