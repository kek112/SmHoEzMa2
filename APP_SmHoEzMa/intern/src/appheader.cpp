#include "appheader.h"

CAppHeader::CAppHeader(QWidget *parent) : QWidget(parent)
{
    m_pAppNameLabel = new QLabel("SmHoEzMa", this);

    m_pNavigationButton = new CCustomButton(this);

    connect(m_pNavigationButton, SIGNAL(clicked(bool)), this, SIGNAL(MenuButtonPressed()));

    m_pMainLayout = new QHBoxLayout();
    setLayout(m_pMainLayout);

    m_pMainLayout->addWidget(m_pNavigationButton);
    m_pMainLayout->addWidget(m_pAppNameLabel, 1);

    m_pMainLayout->setContentsMargins(0,0,0,0);

    setNavigationMenu();

    setStyleSheet("background: #7a9cc6");
}

void CAppHeader::setNavigationMenu()
{
    m_pNavigationButton->setIcon(QIcon(":/menuIcon"));
}

void CAppHeader::setNavigationBack()
{
    m_pNavigationButton->setIcon(QIcon(":/backIcon"));
}
