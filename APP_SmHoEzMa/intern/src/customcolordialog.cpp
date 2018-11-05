#include "customcolordialog.h"

#include <QGridLayout>

CCustomColorDialog::CCustomColorDialog(QWidget *parent) : QWidget(parent)
{
    m_pRedSlider    = new QSlider(Qt::Horizontal, this);
    m_pGreenSlider  = new QSlider(Qt::Horizontal, this);
    m_pBlueSlider   = new QSlider(Qt::Horizontal, this);

    m_pRedSlider  ->setMinimum(0);
    m_pGreenSlider->setMinimum(0);
    m_pBlueSlider ->setMinimum(0);

    m_pRedSlider  ->setMaximum(255);
    m_pGreenSlider->setMaximum(255);
    m_pBlueSlider ->setMaximum(255);

    m_pDisplayColor = new QWidget(this);

    m_pAcceptButton = new CCustomButton("Accept", this);
    m_pCancelButton = new CCustomButton("Cancel", this);

    QGridLayout* pLayout = new QGridLayout;
    setLayout(pLayout);

    pLayout->addWidget(m_pDisplayColor, 0,0, 1,2);
    pLayout->addWidget(m_pRedSlider,    1,0, 1,2);
    pLayout->addWidget(m_pGreenSlider,  2,0, 1,2);
    pLayout->addWidget(m_pBlueSlider,   3,0, 1,2);
    pLayout->addWidget(m_pAcceptButton, 4,0);
    pLayout->addWidget(m_pCancelButton, 4,1);

    UpdateColor();
}

void CCustomColorDialog::UpdateColor()
{
    QColor color(m_pRedSlider->value(), m_pGreenSlider->value(), m_pBlueSlider->value());
}

void CCustomColorDialog::CancelDialog()
{
    hide();
}

void CCustomColorDialog::AcceptDialog()
{
    emit ColorAccepted(QColor(m_pRedSlider->value(), m_pGreenSlider->value(), m_pBlueSlider->value()));
    hide();
}
