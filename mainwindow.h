#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <QTextEdit>
#include <QComboBox>
#include <QTimer>
#include <QTime>
#include <QThread>
#include <QFont>


QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int flag = -1;
    int j = 0;
    int prom = 0;
    int k = 0;
    int m = 0;
    int m1 = 0;
    QWidget * Centr; // указатель на центральное поле
    QVBoxLayout * Osnova ; //указатель на главное распределение виджетов
    QPushButton * Quit; //  указатель на кнопку выхода
    QHBoxLayout * CheckAndWorkEdit; // распределние поля на чекбоксовое и рабочее
    QVBoxLayout * CheckLayout; // указатель на компановку чекбоксов
    QVBoxLayout * NetLayout; //указатель на компановку для сетевых данных
    QTextEdit * EditNetInterfs; // указатель на виджет, где печатается происходящее с сетевыми устройствами
    QComboBox * NetCombo; // указатель на виджет  выпадающего списка сетевых устройств

    QTextEdit * competition; //  название соревнования
    QTextEdit * player1; // имя первого игрока
    QTextEdit * player2; // имя второго игрока
    QTextEdit * min; // минуты счетчика
    QTextEdit * sec; // секунды счетчика
    QTextEdit * score1; // счет 1
    QTextEdit * score2; // счет 2
    QHBoxLayout * pl1_time_pl2; // строка имен и времени
    QHBoxLayout * score; // строка счета
    QHBoxLayout * button_l; // строка кнопок
    QPushButton * start;
    QPushButton * pause;
    QPushButton * stop;
    QTimer * timer;
    QTime time0 ;
    QTime time ;
    QThread * thread_t;
    QFont my_font_label;
    QFont my_font_lost;
protected:
    virtual void resizeEvent(QResizeEvent *);
private slots:
   void update(int);
   void flag1();
   void flag0();
   void flag_1();

};

#endif // MAINWINDOW_H
