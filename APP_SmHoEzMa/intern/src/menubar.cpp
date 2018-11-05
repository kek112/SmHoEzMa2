#include "menubar.h"

CMenuBar::CMenuBar(QWidget *parent) : QWidget(parent)
{
    // https://www.pc-magazin.de/ratgeber/smart-home-router-nas-hub-tipps-einsteiger-3198483.html
    m_Image = QPixmap("qrc:/menuImage");
    m_pImageLabel = new QLabel(this);
    m_pImageLabel->setPixmap(m_Image);
    m_pImageLabel->resize(size().width(), size().height() / 4);

    QButtonGroup* menuButtonGroup = new QButtonGroup(this);

    m_pDevicesButton = new CCustomButton("Devices",     this);
    m_pAboutButton   = new CCustomButton("About",       this);
    m_pSleepButton   = new CCustomButton("Sleep",       this);
    m_pSettingsButton= new CCustomButton("Settings",    this);

    menuButtonGroup->addButton(m_pDevicesButton);
    menuButtonGroup->addButton(m_pSettingsButton);
    menuButtonGroup->addButton(m_pAboutButton);
    menuButtonGroup->addButton(m_pSleepButton);

    connect(menuButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(priavteButtonPressed(QAbstractButton*)));


    m_pMainLayout = new QVBoxLayout();
    setLayout(m_pMainLayout);

    m_pMainLayout->addWidget(m_pImageLabel);
    m_pMainLayout->addWidget(m_pDevicesButton);
    m_pMainLayout->addWidget(m_pSettingsButton);
    m_pMainLayout->addWidget(m_pAboutButton);
    m_pMainLayout->addWidget(m_pSleepButton);
    m_pMainLayout->addStretch(1);

    m_pMainLayout->setContentsMargins(0,0,0,0);

    setAutoFillBackground(true);

    setStyleSheet("CMenuBar{border: 2px solid black;}");
}

void CMenuBar::priavteButtonPressed(QAbstractButton* _pressedButton)
{
    if(_pressedButton == m_pDevicesButton)
    {
        emit DeviceButtonPressed();
    }
    if(_pressedButton == m_pAboutButton)
    {
        emit AboutButtonPressed();
    }
    if(_pressedButton == m_pSleepButton)
    {
        emit SleepButtonPressed();
    }
    if(_pressedButton == m_pSettingsButton)
    {
        emit SettingsButtonPressed();
    }
}

void CMenuBar::resizeEvent(QResizeEvent *_event)
{
//    m_pImageLabel->resize(size().width(), size().height() / 4);
    m_Image = QPixmap(":/menuImage").scaledToWidth(size().width());
    m_pImageLabel->setPixmap(m_Image);

    QWidget::resizeEvent(_event);
}
