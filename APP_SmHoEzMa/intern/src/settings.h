#ifndef SETTINGS_H
#define SETTINGS_H

#include "custombutton.h"

#include <QGeoCoordinate>
#include <QWidget>
#include <QQuickWidget>

class CSettings : public QWidget
{
    Q_OBJECT
public:
    explicit CSettings(QWidget *parent = nullptr);

signals:
    void SetHomeLocation(QGeoCoordinate _coordinate);

public slots:
    void SetPositionPressed();

private:
    QQuickWidget*   m_pMapWidget;
    CCustomButton*    m_pSetLocationButton;
};

#endif // SETTINGS_H
