/* Main programm source file */

#include <QApplication>
#include <QtWidgets>
#include <QtSql>
#include "defines.h"
#include "mainwindow.h"
#include "problemmanager.h"
#include "probbrowser.h"

/* Main programm function */
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QMainWindow main_wnd;

  PROBLEMMANAGER pb_manager(&main_wnd);
  PROBBROWSER pb_browser(&main_wnd);

  main_wnd.setWindowTitle(QObject::tr("Qt Problem browser"));

  main_wnd.setCentralWidget(&pb_browser);
  main_wnd.setGeometry(100, 200, 600, 480);


  QObject::connect(&pb_browser, SIGNAL(NeedProblemsList(PROBLEM_TYPE)),
                   &pb_manager, SLOT(SetProblemsList(PROBLEM_TYPE)));

  QObject::connect(&pb_manager, SIGNAL(GetProblemsList(QStringList, QStringList)),
                   &pb_browser, SLOT(GetProblemsList(QStringList, QStringList)));

  QObject::connect(&pb_browser, SIGNAL(OpenProblem(PROBLEM_TYPE, QString, STATE)),
                   &pb_manager, SLOT(OpenProblem(PROBLEM_TYPE, QString, STATE)));

  QObject::connect(&pb_manager, SIGNAL(ProblemOpened(QString)),
                   &pb_browser, SLOT(ProblemOpened(QString)));

  QObject::connect(&pb_browser, SIGNAL(SaveProblem(PROBLEM_TYPE,QString)),
                   &pb_manager, SLOT(SaveProblem(PROBLEM_TYPE,QString)));

  QObject::connect(&pb_manager, SIGNAL(Saved(bool)),
                   &pb_browser, SLOT(Saved(bool)));

  QObject::connect(&pb_manager, SIGNAL(GetSolveDialog(QDialog *)),
                   &pb_browser, SLOT(SetDialog(QDialog *)));

  QMenu *file_menu = main_wnd.menuBar()->addMenu(QObject::tr("&File"));
  file_menu->addAction(QObject::tr("&Connect database"), &pb_browser, SLOT(Connect()));
  file_menu->addAction(QObject::tr("&Exit"), &app, SLOT(quit()));

  QMenu *help_menu = main_wnd.menuBar()->addMenu(QObject::tr("&Help"));
  help_menu->addAction(QObject::tr("&About this shit"), &pb_browser, SLOT(About()));

  pb_browser.hide();
  main_wnd.show();
  return app.exec();
} /* End of 'main' function */

/* END OF 'main.cpp' FILE */
