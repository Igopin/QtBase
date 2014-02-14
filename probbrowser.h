/* Problem browser header file */

#ifndef _PROBBROWSER_H_
#define _PROBBROWSER_H_

#include <QWidget>

class PROBBROWSER: public QWidget
{
  Q_OBJECT
public:
  PROBBROWSER(QWidget *parent = 0);

public slots:
  /* Menu "About" item processing */
  void About( void );

  /* Menu "New problem" item processing */
  void NewProb( void );
};

#endif // _PROBBROWSER_H_

/* END OF 'probbrowser.h' FILE */
