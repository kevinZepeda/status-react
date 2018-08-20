#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>

#include "reportpublisher.h"

const int MAIN_WINDOW_WIDTH = 1024;
const int MAIN_WINDOW_HEIGHT = 768;

int main(int argc, char **argv) {

  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  app.setApplicationName("reportApp");

  ReportPublisher reportPublisher;

  QQuickView view;
  view.rootContext()->setContextProperty("reportPublisher", &reportPublisher);
  view.setSource(QUrl("qrc:///main.qml"));
  view.setResizeMode(QQuickView::SizeRootObjectToView);
  view.resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
  view.show();

  return app.exec();
}
