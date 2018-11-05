#ifndef APPHEADER_H
#define APPHEADER_H

#include "custombutton.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>

class CAppHeader : public QWidget
{
    Q_OBJECT
public:
    explicit CAppHeader(QWidget *parent = nullptr);

signals:
    void MenuButtonPressed();

public slots:
    void setNavigationMenu();
    void setNavigationBack();

private:
    QLabel*         m_pAppNameLabel;
    CCustomButton*    m_pNavigationButton;

    QHBoxLayout*    m_pMainLayout;
};

#endif // APPHEADER_H
