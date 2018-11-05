#ifndef ABOUTVIEW_H
#define ABOUTVIEW_H

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class CAboutView : public QWidget
{
public:
    CAboutView(QWidget *parent = nullptr);

private:
    QLabel*         m_pTextField;
    QHBoxLayout*    m_pMainLayout;
};

#endif // ABOUTVIEW_H
