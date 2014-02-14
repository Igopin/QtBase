/* Problem browser QT class source file */

#include <QtWidgets>
#include "probbrowser.h"
#include "newprobdialog.h"

/* Main defualt QT construcror */
PROBBROWSER::PROBBROWSER( QWidget *parent ) : QWidget(parent)
{
} /* End of constructor */

/* Menu item "About" processing function */
void PROBBROWSER::About( void )
{
  QMessageBox::about(this, tr("About"), tr("Tambov's wolf is you brother!"));
} /* End of 'About' function */

/* Menu item "New Problem" processing function */
void PROBBROWSER::NewProb( void )
{
  NEWPROBDIALOG npd(this);

  npd.show();
  npd.exec();
} /* End of 'About' function */

/* END OF 'probbrowser.cpp' FILE */
