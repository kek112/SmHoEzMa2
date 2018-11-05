#include "adddeviceview.h"

CAddDeviceView::CAddDeviceView(QWidget *parent) : QWidget(parent)
{
    m_pNameLabel    = new QLabel("Name:", this);
    m_pIpLabel      = new QLabel("IP-Address:", this);
    m_pNumberLabel  = new QLabel("Device Number", this);
    m_pTypeLabel    = new QLabel("Device Type", this);

    m_pNameEdit     = new QLineEdit(this);
    m_pIpEdit       = new QLineEdit(this);
    m_pIpEdit->setInputMask("000.000.000.000;_");

    m_pNumberSpin   = new QSpinBox(this);
    m_pNumberSpin->setMinimumHeight(120);
    m_pNumberSpin->setMaximum(25);
    m_pNumberSpin->setMinimum(1);

    m_pTypeCombo    = new QComboBox(this);
    m_pTypeCombo->addItem("Philips Colorlamp", CDeviceStructure::PHILIPLSCLOLORLAMP);
    m_pTypeCombo->addItem("Philips Luxlamp", CDeviceStructure::PHILIPLSLUXLAMP);
    m_pTypeCombo->addItem("Temperaturesensor", CDeviceStructure::TEMPERATURESENSOR);
    m_pTypeCombo->addItem("Humiditysensor", CDeviceStructure::HUMIDITYSENSOR);

    m_pAcceptButton = new CCustomButton("Accept", this);
    m_pCancelButton = new CCustomButton("Cancel", this);

    m_pMainLayout = new QGridLayout();

    m_pMainLayout->addWidget(m_pNameLabel,      0,0);
    m_pMainLayout->addWidget(m_pNameEdit,       0,1);

    m_pMainLayout->addWidget(m_pIpLabel,        1,0);
    m_pMainLayout->addWidget(m_pIpEdit,         1,1);

    m_pMainLayout->addWidget(m_pNumberLabel,    2,0);
    m_pMainLayout->addWidget(m_pNumberSpin,     2,1);

    m_pMainLayout->addWidget(m_pTypeLabel,      3,0);
    m_pMainLayout->addWidget(m_pTypeCombo,      3,1);

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(m_pAcceptButton);
    buttonLayout->addWidget(m_pCancelButton);

    m_pMainLayout->addLayout(buttonLayout, 4, 0, 1, 2);

    setLayout(m_pMainLayout);

    connect(m_pCancelButton, SIGNAL(clicked(bool)), this, SIGNAL(cancel()));
    connect(m_pAcceptButton, SIGNAL(clicked(bool)), this, SLOT(AcceptSettings()));
}

void CAddDeviceView::AcceptSettings()
{
    CDeviceStructure::Device device;
    device.m_DeviceNumber   = m_pNumberSpin->value();
    device.m_DeviceType     = m_pTypeCombo->currentData().value<CDeviceStructure::EDevices>();
    device.m_Name           = m_pNameEdit->text();
    device.m_IpAddress      = QHostAddress(m_pIpEdit->text());

    emit sendDevice(device);
}
