#include "closemenueventfilter.h"

CCloseMenuEventFilter::CCloseMenuEventFilter(QObject *parent) : QObject(parent)
{
    isMenuVisible = false;
}

void CCloseMenuEventFilter::setIsMenuVisible(bool _visible)
{
    isMenuVisible = _visible;
}

bool CCloseMenuEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->windowPos().x() > (qApp->activeWindow()->size().width() * 0.7) && isMenuVisible)
        {
            return true;
        }
        else
        {
            return QObject::eventFilter(obj, event);
        }
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->windowPos().x() > (qApp->activeWindow()->size().width() * 0.7) && isMenuVisible)
        {
            emit closeMenu();
            isMenuVisible = false;
            return true;
        }
        else
        {
            return QObject::eventFilter(obj, event);
        }
    }
    else
    {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
