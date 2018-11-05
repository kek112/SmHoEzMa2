#ifndef MENUBAR_H
#define MENUBAR_H

#include "custombutton.h"

#include <QButtonGroup>
#include <QPixmap>
#include <QLabel>
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QWidget>

class CMenuBar : public QWidget
{
    Q_OBJECT
public:
    explicit CMenuBar(QWidget *parent = nullptr);

signals:
    void DeviceButtonPressed();
    void SettingsButtonPressed();
    void AboutButtonPressed();
    void SleepButtonPressed();

private slots:
    void priavteButtonPressed(QAbstractButton *_pressedButton);

protected:
    void resizeEvent(QResizeEvent* _event);

private:
    QPixmap         m_Image;

    QLabel*         m_pImageLabel;
    CCustomButton*  m_pDevicesButton;
    CCustomButton*  m_pAboutButton;
    CCustomButton*  m_pSleepButton;
    CCustomButton*  m_pSettingsButton;

    QVBoxLayout*    m_pMainLayout;
};

#endif // MENUBAR_H
