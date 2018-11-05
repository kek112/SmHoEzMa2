#include "custombutton.h"

CCustomButton::CCustomButton(QWidget *parent) : QPushButton(parent)
{
    setupButton();
}

CCustomButton::CCustomButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    setupButton();
}

CCustomButton::CCustomButton(const QIcon &icon, const QString &text, QWidget *parent) : QPushButton(icon, text, parent)
{
    setupButton();
}

void CCustomButton::setupButton()
{
    setIconSize(QSize(125,125));
    setFocusPolicy(Qt::NoFocus);
}
