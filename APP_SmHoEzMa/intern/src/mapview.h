#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QQuickView>
#include <QWidget>

class CMapView : public QWidget
{
    Q_OBJECT
public:
    explicit CMapView(QWidget *parent = nullptr);

signals:

public slots:

private:
    QQuickView* m_pMapView;
};

#endif // MAPVIEW_H
