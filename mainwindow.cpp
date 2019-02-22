#include "mainwindow.h"
#include<QtWidgets>
#include<QSize>





mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent)
{
    QAction *easy = new QAction(style()->standardIcon(QStyle::SP_MessageBoxWarning), "Easy", this);
    easy->setShortcut(QKeySequence(Qt::Key_E));
    easy->setStatusTip("Choose easy level");
   // MENU->connect(easy, SIGNAL(triggered()), SLOT(speedUp()));

    QAction *hard = new QAction(style()->standardIcon(QStyle::SP_FileDialogStart), "Hard", this);
    hard->setShortcut(QKeySequence(Qt::Key_H));
    hard->setStatusTip("Choose hard level");


  /*  QWidget *widget = new QWidget;
    widget->setLayout(pol);
    setCentralWidget(widget);
 */
    QMenu *me = menuBar()->addMenu("&Options");
    me->addAction(easy);
    me->addAction(hard);


    QToolBar *t = addToolBar("level");
    t->addAction(easy);
    t->addAction(hard);



h = 20;
w = 20;
int k = 0;
m = 0;
statusBar()->showMessage("Ready",m);
QGridLayout *pol = new QGridLayout;
pol->setSpacing(0);

btn = new MyQPushButton*[h*w];

for(int i =0; i< h; i++)
    for(int j =0; j< w; j++)
    {

        btn[k] = new MyQPushButton;
        btn[k]->buttonID = k;
        btn[k]->setStyleSheet("QPushButton{background:#2f65bc;}");
        btn[k]->setMinimumSize(23,23);

        connect(btn[k], SIGNAL(lClicked()), btn[k], SLOT(MyPressed()));
        connect(btn[k],SIGNAL(rClicked()),btn[k],SLOT(BombPressed()));
        connect(btn[k],SIGNAL(EmptyClicked()),this,SLOT(doEmpty()));
        btn[k]->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        pol->addWidget(btn[k],i,j);

        if (rand() % 10 < 2) // Расстановка бомб
        {
            btn[k]->setState(-1);
            //btn[k]->MyPressed();
            //btn[k]->setState(11);
            m++;
        }
        else
        {
            btn[k]->setState(0);
        }
       // btn[k]->MyPressed();
        k++;

    }


for(int i = 0; i < h; i++) // заполняем кнопки значениями
    for(int j = 0; j < w; j++)
    {
        int mine_count = 0;
        if (btn[i*h+j]->getState() != -1)
        {
             for(int i1 = i-1; i1<= i+1; i1++)
                 for(int j1 =j-1; j1<= j+1; j1++)
                 {
                    if ((i1<h) && (i1>=0) && (j1<w) && (j1>=0) && (btn[i1*h+j1]->getState() == -1))
                        mine_count++;
                 }
             btn[i*h+j]->setState(mine_count);
        }
        if (btn[i*h+j]->getState() == 0)
        {
            btn[i*h+j]->MyPressed();
            //btn[i*h+j]->turn = false;
        }
    }

for(int i = 0; i < h; i++) //открываем все пустые (не нужно)
    for(int j = 0; j < w; j++)
    {
        if (btn[i*h+j]->getState() == 0)
        {
            for(int i1 = i-1; i1 <= i+1; i1++)
                for(int j1 = j-1; j1 <= j+1; j1++)
                {
                   if ((i1<h) && (i1>=0) && (j1<w) && (j1>=0))
                       btn[i1*h+j1]->MyPressed();
                }
             //btn[i*h+j]->turn = false;
        }
    }


QWidget *widget = new QWidget;

//pol->minimumSize();
widget->setLayout(pol);
//widget->resize(100,100);
setCentralWidget(widget);



  /*void doEmpty()
  {
    btn[k]->MyPressed();
  }*/
}

/*void mainwindow::easy()
{

}
*/

/*
void window::mouseGrabber(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        btn[k]->setStyleSheet(QString::fromUtf8(
                          "QPushButton{background:#5385d6;}"));
    }
}
*/
mainwindow::~mainwindow()
{
    delete[] btn;
}
