#ifndef ADDDEVICEVIEW_H
#define ADDDEVICEVIEW_H

#include "custombutton.h"
#include "devicestructure.h"

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>

class CAddDeviceView : public QWidget
{
    Q_OBJECT
public:
    explicit CAddDeviceView(QWidget *parent = nullptr);


signals:
    void sendDevice(CDeviceStructure::Device _device);
    void cancel();

private slots:
    void AcceptSettings();

private:
    QLabel*         m_pNameLabel;
    QLineEdit*      m_pNameEdit;

    QLabel*         m_pIpLabel;
    QLineEdit*      m_pIpEdit;

    QLabel*         m_pMacLabel;
    QLineEdit*      m_pMacEdit;

    QLabel*         m_pNumberLabel;
    QSpinBox*       m_pNumberSpin;

    QLabel*         m_pTypeLabel;
    QComboBox*      m_pTypeCombo;

    CCustomButton*    m_pAcceptButton;
    CCustomButton*    m_pCancelButton;

    QGridLayout*    m_pMainLayout;
};

#endif // ADDDEVICEVIEW_H
