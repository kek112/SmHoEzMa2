#include "settings.h"

#include <QVBoxLayout>

#include <QQmlEngine>
#include <QQmlComponent>

CSettings::CSettings(QWidget *parent) : QWidget(parent)
{
    m_pMapWidget = new QQuickWidget(this);

    m_pMapWidget->setSource(QUrl("qrc:/map.qml"));
    m_pMapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    m_pMapWidget->show();

    m_pSetLocationButton = new CCustomButton("Set Location", this);

    QVBoxLayout* mainLayout = new QVBoxLayout();

    mainLayout->addWidget(m_pMapWidget);
    mainLayout->addWidget(m_pSetLocationButton);

    connect(m_pSetLocationButton, &CCustomButton::clicked, this, &CSettings::SetPositionPressed);

    setLayout(mainLayout);
}

void CSettings::SetPositionPressed()
{
    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/map.qml"));
    QObject *object = component.create();

    QVariant returnedValue;
    QMetaObject::invokeMethod(object, "setPostion",
        Q_RETURN_ARG(QVariant, returnedValue));

    emit SetHomeLocation(returnedValue.value<QGeoCoordinate>());
    delete object;
}
