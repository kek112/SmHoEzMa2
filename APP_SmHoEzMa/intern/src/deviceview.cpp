#include "deviceview.h"

#include <QDebug>
#include <QQuickView>


CDeviceView::CDeviceView(CDeviceStructure::Device _device, QWidget *parent)
    : QWidget(parent)
    , m_Device(_device)
    , m_Hue(0)
{
    m_pColorLamp = nullptr;
    m_pLuxLamp = nullptr;
    m_pHomecomingLamp = nullptr;
    m_pHumiditySensor = nullptr;
    m_pTemperatureSensor = nullptr;

    switch(m_Device.m_DeviceType)
    {
    case CDeviceStructure::PHILIPLSCLOLORLAMP:
    {
        m_pBrightnessDescriptionLabel   = new QLabel("Brightness", this);
        m_pSaturationDescriptionLabel   = new QLabel("Saturation", this);
        m_pColorDescriptionLabel        = new QLabel("Color", this);
        m_pOnOffDescriptionLabel        = new QLabel("Active", this);


        m_pBrightnessSlider = new QSlider(Qt::Horizontal, this);
        m_pSaturationSlider = new QSlider(Qt::Horizontal, this);
        m_pBrightnessSlider->setMinimum(0);
        m_pSaturationSlider->setMinimum(0);
        m_pBrightnessSlider->setMaximum(254);
        m_pSaturationSlider->setMaximum(254);

        m_pSwitchWidget = new CSwitchWidget(this);
        m_pSwitchWidget->setMinimumHeight(64);
        m_pSwitchWidget->setMinimumWidth(128);

//        m_pMapWidget = new QQuickWidget();

//        connect(m_pMapWidget, &QQuickWidget::statusChanged, this, &CDeviceView::QuickWidgetStatusChanged);

//        m_pMapWidget->setSource(QUrl("qrc:/map.qml"));
//        m_pMapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
//        m_pMapWidget->setMinimumHeight(200);
//        m_pMapWidget->show();

        qApp->setAttribute(Qt::AA_DontCreateNativeWidgetSiblings, true);

        m_pHomeComingOnOffLabel = new QLabel("Homecoming", this);
        m_pHomeComingOnOffSwitch = new CSwitchWidget(this);
        m_pHomeComingOnOffSwitch->setMinimumHeight(64);
        m_pHomeComingOnOffSwitch->setMinimumWidth(128);
//        m_pHomeComingSetButton = new CCustomButton("Set Destination", this);

//        m_pMapView = new QQuickView();
//        m_pMapView->setSource(QUrl("qrc:/map.qml"));
//        m_pMapView->setResizeMode(QQuickView::SizeRootObjectToView);
//        m_pMapView->hide();
//        m_pMapView->close();
//        QWidget *MapContainer = QWidget::createWindowContainer(m_pMapView, this);
//        MapContainer->show();
//        MapContainer->resize(200, 200);

//        m_pMapView = new CMapView(this);
//        m_pMapView->lower();

        m_pHueSlider = new QSlider(Qt::Horizontal, this);
        m_pHueSlider->setMinimum(0);
        m_pHueSlider->setMaximum(360);

        m_pHueSlider->setStyleSheet("border-image: url(:/ColorSpectrum);");

        m_pColorDialog = new QColorDialog(this);

        m_pMainLayout = new QGridLayout();

        m_pMainLayout->addWidget(m_pBrightnessDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pSaturationDescriptionLabel, 1,0);
        m_pMainLayout->addWidget(m_pColorDescriptionLabel,      2,0);
        m_pMainLayout->addWidget(m_pOnOffDescriptionLabel,      3,0);


        m_pMainLayout->addWidget(m_pBrightnessSlider,   0,1);
        m_pMainLayout->addWidget(m_pSaturationSlider,   1,1);
        m_pMainLayout->addWidget(m_pHueSlider,          2,1);
        m_pMainLayout->addWidget(m_pSwitchWidget,       3,1, Qt::AlignRight);

        //TODO: finish map (add set button & on/off switch)
//        m_pMainLayout->addWidget(m_pMapWidget,              5,0, 1,2);
//        m_pMainLayout->addWidget(MapContainer,              5,0, 1,2);
//        m_pMainLayout->addWidget(m_pMapView,                5,0, 1,2);
        m_pMainLayout->addWidget(m_pHomeComingOnOffLabel,   6,0);
        m_pMainLayout->addWidget(m_pHomeComingOnOffSwitch,  6,1, Qt::AlignRight);
//        m_pMainLayout->addWidget(m_pHomeComingSetButton,    7,0, 1,2);


        connect(m_pSaturationSlider,    &QSlider::sliderReleased,   this, &CDeviceView::SettingsChanged);
        connect(m_pBrightnessSlider,    &QSlider::sliderReleased,   this, &CDeviceView::SettingsChanged);
        connect(m_pSwitchWidget,        &CSwitchWidget::released,   this, &CDeviceView::SettingsChanged);
        connect(m_pHueSlider,           &QSlider::sliderReleased,   this, &CDeviceView::SettingsChanged);

        connect(m_pHomeComingSetButton, &QPushButton::clicked,      this, &CDeviceView::DebugMap);

//        qApp->processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents);

        break;
    }
    case CDeviceStructure::PHILIPLSLUXLAMP:
    {
        m_pBrightnessDescriptionLabel   = new QLabel("Brightness", this);
        m_pSaturationDescriptionLabel   = new QLabel("Saturation", this);
        m_pOnOffDescriptionLabel        = new QLabel("Active", this);


        m_pBrightnessSlider = new QSlider(Qt::Horizontal, this);
        m_pSaturationSlider = new QSlider(Qt::Horizontal, this);
        m_pBrightnessSlider->setMinimum(0);
        m_pSaturationSlider->setMinimum(0);
        m_pBrightnessSlider->setMaximum(254);
        m_pSaturationSlider->setMaximum(254);

        m_pSwitchWidget = new CSwitchWidget(this);
        m_pSwitchWidget->setMinimumHeight(64);
        m_pSwitchWidget->setMinimumWidth(128);

        m_pMainLayout = new QGridLayout();

        m_pMainLayout->addWidget(m_pBrightnessDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pSaturationDescriptionLabel, 1,0);
        m_pMainLayout->addWidget(m_pOnOffDescriptionLabel,      2,0);


        m_pMainLayout->addWidget(m_pBrightnessSlider,   0,1);
        m_pMainLayout->addWidget(m_pSaturationSlider,   1,1);
        m_pMainLayout->addWidget(m_pSwitchWidget,       2,1, Qt::AlignRight);


        connect(m_pSaturationSlider, &QSlider::sliderReleased, this, &CDeviceView::SettingsChanged);
        connect(m_pBrightnessSlider, &QSlider::sliderReleased, this, &CDeviceView::SettingsChanged);
        connect(m_pSwitchWidget,     &CSwitchWidget::released, this, &CDeviceView::SettingsChanged);

        break;
    }
    case CDeviceStructure::TEMPERATURESENSOR:
    {
        /**********************************************
        * NO BREAK --> uses same structure as Humidity
        **********************************************/
    }
    case CDeviceStructure::HUMIDITYSENSOR:
    {
        m_pOutputLabel = new QLabel(this);
        m_pOutputDescriptionLabel = new QLabel(this);

        m_pMainLayout = new QGridLayout();
        m_pMainLayout->addWidget(m_pOutputDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pOutputLabel, 0,1);

        break;
    }
    }
    setLayout(m_pMainLayout);

    UpdateDevice(_device);
}

CDeviceStructure::Device CDeviceView::GetDevice()
{
    return m_Device;
}

void CDeviceView::UpdateDevice(CDeviceStructure::Device _device)
{
    m_Device = _device;
    SettingsChanged();
}

void CDeviceView::ReachedHome()
{
    if(m_pHomecomingLamp != nullptr)
    {
        delete m_pHomecomingLamp;
    }
    m_pHomecomingLamp = new CPhilips(nullptr, true, m_pBrightnessSlider->value(), m_pSaturationSlider->value(), m_Device.m_DeviceNumber, m_Device.m_IpAddress.toString());
    m_pSwitchWidget->setChecked(true);
    m_Device.m_HomecomingActive = false;
    m_pHomeComingOnOffSwitch->setChecked(false);
}

void CDeviceView::SettingsChanged()
{
    if(m_pLuxLamp != nullptr)
    {
        delete m_pLuxLamp;
    }
    if(m_pColorLamp != nullptr)
    {
        delete m_pColorLamp;
    }
    if(m_pHumiditySensor != nullptr)
    {
        delete m_pHumiditySensor;
    }
    if(m_pTemperatureSensor != nullptr)
    {
        delete m_pTemperatureSensor;
    }

    switch(m_Device.m_DeviceType)
    {
    case CDeviceStructure::PHILIPLSCLOLORLAMP:
    {
        m_Hue = m_pHueSlider->value() * 182; //normaly hue ranges from 0-360 (degree in a cricle 360 = 0) but philips hue lamps expect vlaues from 0 - 65535 (uint16) --> *182
        m_pColorLamp = new CPhilipsColor(this,
                                         m_pSwitchWidget->isChecked(),
                                         m_pBrightnessSlider->value(),
                                         m_pSaturationSlider->value(),
                                         m_Device.m_DeviceNumber,
                                         m_Device.m_IpAddress.toString(),
                                         m_Hue);
        break;
    }
    case CDeviceStructure::PHILIPLSLUXLAMP:
    {
        m_pLuxLamp = new CPhilipsLux(nullptr,
                                     m_pSwitchWidget->isChecked(),
                                     m_pBrightnessSlider->value(),
                                     m_pSaturationSlider->value(),
                                     m_Device.m_DeviceNumber,
                                     m_Device.m_IpAddress.toString());

        break;
    }
    case CDeviceStructure::TEMPERATURESENSOR:
    {
        m_pTemperatureSensor = new CTemperatureSensor(m_Device.m_DeviceNumber, m_Device.m_IpAddress.toString());
        m_pOutputDescriptionLabel->setText("Temperatur:");
        m_pOutputLabel->setText(QString::number(m_pTemperatureSensor->getTemperature()) + "°C");
        break;
    }
    case CDeviceStructure::HUMIDITYSENSOR:
    {
        m_pHumiditySensor = new CHumiditySensor(m_Device.m_DeviceNumber, m_Device.m_IpAddress.toString());
        m_pOutputDescriptionLabel->setText("Humidity:");
        m_pOutputLabel->setText(QString::number(m_pHumiditySensor->getHumidity()) + "%");
        break;
    }
    }

    emit DeviceChanged();
}

void CDeviceView::OpenColorDialog()
{
//    auto color = m_pColorDialog->getColor();
    m_pColorDialog->resize(width(), m_pColorDialog->height());
    m_pColorDialog->show();

//    m_Hue = color.hue();

//    QPalette pal = m_pOpenColorDialog->palette();
//    pal.setColor(QPalette::Button, color);
//    m_pOpenColorDialog->setAutoFillBackground(true);
//    m_pOpenColorDialog->setPalette(pal);
//    m_pOpenColorDialog->update();

    SettingsChanged();
}

void CDeviceView::SleepDevice()
{
    if(CDeviceStructure::PHILIPLSLUXLAMP == m_Device.m_DeviceType || CDeviceStructure::PHILIPLSCLOLORLAMP == m_Device.m_DeviceType)
    {
        m_pSwitchWidget->setChecked(false);
        SettingsChanged();
    }
}

void CDeviceView::QuickWidgetStatusChanged(QQuickWidget::Status _status)
{
//    qDebug() << "STATUS -> " << _status;
//    if (_status == QQuickWidget::Error) {
//        qDebug() << "ERROR -> " << m_pMapWidget->errors();
//    }

//    if (_status == QQuickWidget::Ready) {
//        qDebug() << "IM READY TO LOAD";
//    }
}
