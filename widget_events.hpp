// widget_events.hpp
#ifndef WIDGET_EVENTS_H
#define WIDGET_EVENTS_H

#include <QWidget>
#include <iostream>
#include <QString>
#include <QDebug>
#include <QEvent>
#include <QMetaEnum>

class WidgetEvent : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEvent(QWidget *parent = nullptr);
    virtual bool event(QEvent *event) override;

    template <typename EnumType>
    QString ToString(const EnumType &enumValue);
};

#endif
