// widget_events.cpp

#include "widget_events.hpp"

WidgetEvent::WidgetEvent(QWidget *parent) : QWidget(parent)
{
    // Set size of the window
    setFixedSize(500, 500);
}

bool WidgetEvent::event(QEvent *event)
{
    qDebug() << ToString(event->type());
    return true;
}

template <typename EnumType>
QString WidgetEvent::ToString(const EnumType &enumValue)
{
    const char *enumName = qt_getEnumName(enumValue);
    const QMetaObject *metaObject = qt_getEnumMetaObject(enumValue);
    if (metaObject)
    {
        const int enumIndex = metaObject->indexOfEnumerator(enumName);
        return QString("%1::%2::%3").arg(metaObject->className(), enumName, metaObject->enumerator(enumIndex).valueToKey(enumValue));
    }

    return QString("%1::%2").arg(enumName).arg(static_cast<int>(enumValue));
}