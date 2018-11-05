#include "mapview.h"

#include <QHBoxLayout>

CMapView::CMapView(QWidget *parent) : QWidget(parent)
{
    m_pMapView = new QQuickView();
    m_pMapView->setSource(QUrl("qrc:/map.qml"));
    m_pMapView->setResizeMode(QQuickView::SizeRootObjectToView);
    QWidget *MapContainer = QWidget::createWindowContainer(m_pMapView, this);
//    MapContainer->show();
//    MapContainer->resize(200, 200);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(MapContainer);

    setLayout(mainLayout);
}
