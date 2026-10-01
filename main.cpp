// main.cpp

#include <QApplication>
#include "widget_events.hpp"

int main(int argc, char **argv)
{
      QApplication app(argc, argv);

      WidgetEvent widg;
      widg.show();

      return app.exec();
}
