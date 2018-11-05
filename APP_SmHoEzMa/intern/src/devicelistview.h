#ifndef DEVICELISTVIEW_H
#define DEVICELISTVIEW_H

#include "adddeviceview.h"
#include "custombutton.h"
#include "devicestructure.h"
#include "deviceview.h"
#include "mapthread.h"

#include <QGridLayout>
#include <QLabel>
#include <QStackedLayout>
#include <QToolBox>
#include <QWidget>

class CDeviceListView : public QWidget
{
    Q_OBJECT
public:
    explicit CDeviceListView(QWidget *parent = nullptr);

signals:
    void startThread();

public slots:
    void SleepDevices();
    void SetHomeCoordinate(QGeoCoordinate _coordinate);

private slots:
    void OpenAddDevice();
    void RemoveDevice();
    void CancelAddDevice();
    void AddDevice(CDeviceStructure::Device _toAdd);
    void ReachedHome(int _device);
    void DeviceUpdated();

private:
    void LoadDeviceList();

    QStackedLayout*     m_pMainStackLayout;
    QGridLayout*        m_pDeviceListLayout;

    QToolBox*           m_pDeviceToolBox;
    CCustomButton*      m_pAddDeviceButton;
    CCustomButton*      m_pRemoveDeviceButton;
    CAddDeviceView*     m_pAddDeviceView;

    CDeviceStructure*   m_pDevices;
    CMapThread*         m_pMapThread;
    QThread             m_WorkerThread;
};

#endif // DEVICELISTVIEW_H
