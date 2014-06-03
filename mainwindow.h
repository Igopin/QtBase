#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newprobdialog.h"

class MAINWINDOW : public QMainWindow
{
  Q_OBJECT
public:
  explicit MAINWINDOW(QWidget *parent = 0);

signals:
  void NeedProblemsList(PROBLEM_TYPE, QString, QString, QString, QString);

public slots:

  /* Hide/show opened problem browser */
  //void StateOpenedProbBrowser( void );

};

#endif // MAINWINDOW_H
