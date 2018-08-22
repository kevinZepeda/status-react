#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>
#include <QDebug>

#include "reportpublisher.h"

const int MAIN_WINDOW_WIDTH = 1024;
const int MAIN_WINDOW_HEIGHT = 768;
const int INPUT_ARGUMENTS_COUNT = 8;

int main(int argc, char **argv) {

  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  qDebug() << argc << " args[1]: " << argv[1] << " args[2]: " << argv[2];

  if (argc != INPUT_ARGUMENTS_COUNT) {
      return 1;
  }

  app.setApplicationName("Crash Report");

  ReportPublisher reportPublisher(argv[1], argv[7]);

  QQuickView view;
  view.rootContext()->setContextProperty("reportPublisher", &reportPublisher);
  view.setSource(QUrl("qrc:///main.qml"));
  view.setResizeMode(QQuickView::SizeRootObjectToView);
  view.resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
  view.show();

  return app.exec();
}
