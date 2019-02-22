#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
//#include <phonon/MediaObject>
//#include <phonon/AudioOutput>
//#include <QSound>
#include <QMouseEvent>
#include <QFont>
#include <QPalette>

//class QPushButton;
class QLineEdit;
class MyQPushButton : public QPushButton
{
    Q_OBJECT

public:

    bool turn_bomb; // нажата/не нажата (true - не нажата ; false -нажата)
    bool turn = true;
    int buttonID;

    //MyQPushButton(QWidget *parent = 0) : QPushButton(parent){};
    void setState(int a) // -1=mine; 0=empty; 1-8=state; 9=flag; 10=question; 11=opened
    {
        if((a >= -1)&&(a <12))
            state = a;
    }

    int getState()
    {
        return state;
    }

    //MyQPushButton(int k)
    //{
    //    buttonID = k;
    //    QPushButton();
    //}

    /*bool eventFilter(QObject *obj, QEvent *event)
    {
        if (event->type() == QEvent::MouseButtonPress) {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                if(mouseEvent->button() == Qt::RightButton)
                {
                    qDebug("MouseButtonPress == Qt::RightButton");
                    emit rClicked();
                }
                 return true;
             }
             else {
                 // standard event processing
                 return QObject::eventFilter(obj, event);
             }
    }*/

    void mousePressEvent(QMouseEvent *event)
    {
    if(event->button() == Qt::RightButton)
            {
            emit rClicked();
            }
    if(event->button() == Qt::LeftButton)
            {
            emit lClicked();
            }
    }

signals:

    void rClicked();
    void lClicked();
    int EmptyClicked();

    void MineClicked();

/*protected:
        void mouseReleaseEvent(QMouseEvent *event)
        {
        if(event->button() == Qt::RightButton)
                {
                emit rClicked();
                }
        }
*/

public slots:
    void MyPressed()
    {
        QFont newFont("Courier", 15, QFont::Black, false);
        setFont(newFont);
        QSize tmpSize;
        tmpSize = size();
        char str[1] = "";


    if (turn_bomb) // Проверка флага
      {
        if (turn) // Проверка нажата ли кнопка
        {
            if (state != -1)
            {
            switch (state) {
            case 0:
              //  emit EmptyClicked();
                setStyleSheet("QPushButton{background:#d4e1f7;}");
                turn = false;
                break;
            case 1:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#4d8cf2;}");
                turn = false;
                break;
            case 2:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#049b55;}");
                turn = false;
                break;
            case 3:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#b73e01;}");
                turn = false;
                break;
            case 4:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#6b0057}");
                turn = false;
                break;
            case 5:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#ff9205}");
                turn = false;
                break;
            case 6:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#d6ed0b}");
                turn = false;
                break;
            case 7:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#1dce06}");
                turn = false;
                break;
            case 8:
                itoa(state, str, 10);
                setText(str);
                setStyleSheet("QPushButton{background:#ad0ef2}");
                turn = false;
                break;

            default:
                break;
            }
            /*if (state == 0)
            {
                setStyleSheet("QPushButton{background:#d4e1f7;}");
                turn = false;
            }
            else if (state != -1)
                {

                    char str[1] = "";
                    itoa(state, str, 10);
                    setText(str);

                    setStyleSheet("QPushButton{background:#d4e1f7;}");
                    //resize(33,33);
                    //setFlat(0);
                    //setFlat(1);
                    //resize(tmpSize);
                    /*
                    if (state = -1)
                    {
                        setIcon(QIcon("mine.bpm"));
                    }

                //setMaximumSize(23,23);
                //setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
                 //state = 11;
                 // if (state = -1)
                // {
                 //     QSound *sound = new QSound("d:\\_Projects\\QT\miner\\mine.wav");
                 //     sound->play();
                 //}
                 //if (state == -1)
                  //   setStyleSheet("QPushButton{background:#d12604;}");
                    turn = false;
                }
        */
            }
           else
           {
               //emit MineClicked();

                setStyleSheet("QPushButton{background:#f24800;}");

               setIcon(QIcon("D:\\Ilya\\STUDY\\VS\\Qt\\miner\\qt\\mine.png"));
               turn = false;
           }


        }

      }
    }

/*    void EmptyPressed()
    {
        setStyleSheet("QPushButton{background:#d4e1f7;}");
        turn = false;
        for(int i1 = i-1; i1<= i+1; i1++)
            for(int j1 =j-1; j1<= j+1; j1++)
            {
               if ((i1<h) && (i1>=0) && (j1<w) && (j1>=0) && (state != -1))
               {
                   if (state == 0)
                   {
                       setStyleSheet("QPushButton{background:#d4e1f7;}");
                       turn = false;
                   }
                   else
                  // if (state != 11)
                       {
                           //int tmpSizeX, tmpSizeY;
                           QSize tmpSize;
                           tmpSize = size();
                           char str[1] = "";
                           itoa(state, str, 10);
                           setText(str);
                           setStyleSheet("QPushButton{background:#d4e1f7;}");
                           turn = false;
                       }
               }
            }
        EmptyPressed();
    }
*/
    void BombPressed()
    {
        if (turn)
        {
        if (turn_bomb)
        {
            setIcon(QIcon("D:\\Ilya\\STUDY\\VS\\Qt\\miner\\qt\\flag.png"));  //flag
            turn_bomb = false;


        }
        else
        {
            setStyleSheet("QPushButton{background:#2f65bc;}");
            setIcon(QIcon());
            turn_bomb = true;
        }
        }
    }


private:
    int state;


};

class mainwindow : public QMainWindow
{
    Q_OBJECT
    int h,w,m;
    MyQPushButton **btn;

public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();

signals:

public slots:
   // void doEmpty();

};



#endif // MAINWINDOW_H
