/* Main programm source file */

#include <QApplication>
#include <QtWidgets>
#include <QtSql>
#include "probbrowser.h"

/* Main programm function */
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QMainWindow main_wnd;
  PROBBROWSER pbrowser(&main_wnd);

  main_wnd.setWindowTitle(QObject::tr("Qt Base"));
  main_wnd.setCentralWidget(&pbrowser);

  QMenu *file_menu = main_wnd.menuBar()->addMenu(QObject::tr("&File"));
  file_menu->addAction(QObject::tr("New &problem!"), &pbrowser, SLOT(NewProb()));
  file_menu->addAction(QObject::tr("&Exit"), &app, SLOT(quit()));

  QMenu *help_menu = main_wnd.menuBar()->addMenu(QObject::tr("&Help"));
  help_menu->addAction(QObject::tr("&About this shit"), &pbrowser, SLOT(About()));

  main_wnd.show();
  return app.exec();
} /* End of 'main' function */

/* END OF 'main.cpp' FILE */
