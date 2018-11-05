#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "aboutview.h"
#include "appheader.h"
#include "devicelistview.h"
#include "menubar.h"
#include "settings.h"

#include <QApplication>
#include <QDebug>
#include <QPropertyAnimation>
#include <QResizeEvent>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QWidget>

class CMainView : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int MenuXPosition READ MenuXPosition WRITE setMenuXPosition)

public:
    explicit CMainView(QWidget *parent = nullptr);

    int MenuXPosition() const;
    void setMenuXPosition(int MenuXPosition);

signals:
    void sendIsMenuVisible(bool _visible);

protected:
    void resizeEvent(QResizeEvent* _event);

private slots:
    void triggerMenu();
    void closeMenu(bool _sendSignal = false);
    void openMenu();

    void ShowDevices();
    void ShowSettings();
    void ShowAbout();

    void SleepModus();

private:
    int m_MenuXPosition;

    CAppHeader*         m_pAppHeader;
    QStackedLayout*     m_pMainWidgetStack;

    CMenuBar*           m_pMenuBar;

    CDeviceListView*    m_pDeviceView;
    CAboutView*         m_pAboutView;
    CSettings*          m_pSettingsView;

    QVBoxLayout*        m_pMainLayout;

    QPropertyAnimation* m_pAnimation;
};

#endif // MAINVIEW_H
