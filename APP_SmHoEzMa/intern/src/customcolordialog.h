#ifndef CUSTOMCOLORDIALOG_H
#define CUSTOMCOLORDIALOG_H

#include "custombutton.h"

#include <QSlider>
#include <QWidget>

class CCustomColorDialog : public QWidget
{
    Q_OBJECT
public:
    explicit CCustomColorDialog(QWidget *parent = nullptr);

signals:
    void ColorAccepted(QColor color);

private slots:
    void UpdateColor();

    void CancelDialog();
    void AcceptDialog();

private:
    QSlider*    m_pRedSlider;
    QSlider*    m_pBlueSlider;
    QSlider*    m_pGreenSlider;

    QWidget*    m_pDisplayColor;

    CCustomButton*  m_pAcceptButton;
    CCustomButton*  m_pCancelButton;
};

#endif // CUSTOMCOLORDIALOG_H
