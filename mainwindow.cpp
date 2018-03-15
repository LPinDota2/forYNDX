#include "mainwindow.h"
#include "time_thread.h"
#include <windows.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Centr = new QWidget();
    Osnova = new QVBoxLayout ();
    score = new QHBoxLayout();
    button_l = new QHBoxLayout();
    competition = new QTextEdit(tr("Соревнование"));
    pl1_time_pl2 = new QHBoxLayout();
    player1 = new QTextEdit(tr("Игрок"));
    player2 = new QTextEdit(tr("Игрок"));
    score1 = new QTextEdit("0");
    score2 = new QTextEdit("0");
    min = new QTextEdit("00:00");
    timer = new QTimer();
    Quit = new QPushButton (tr("Выход"));
    start = new QPushButton (tr("Старт"));
    pause = new QPushButton (tr("Пауза"));
    stop = new QPushButton (tr("Стоп"));


    setCentralWidget(Centr); // установил центральный виджет
    Centr->setLayout(Osnova);// основное (вертикальное) расположение виджетов
    Osnova->addWidget( competition ); // строка названия соревнования
    Osnova->addLayout(pl1_time_pl2); // строка с игроками и таймером
    Osnova->addLayout(button_l); // строка кнопок
    Osnova->addLayout(score); // строка счета
    Osnova->addWidget(Quit); // установка кнопки выхода



    pl1_time_pl2->addWidget( player1 );
    pl1_time_pl2->addWidget( min );    
    pl1_time_pl2->addWidget( player2 );

    button_l->addWidget(start);
    button_l->addWidget(pause);
    button_l->addWidget(stop);

    score->addWidget( score1 );
    score->addWidget( score2 );

    competition->setAlignment( Qt::AlignCenter );
    player1->setAlignment( Qt::AlignCenter );
    min->setAlignment( Qt::AlignCenter );    
    player2->setAlignment( Qt::AlignCenter );
    score1->setAlignment( Qt::AlignCenter );
    score2->setAlignment( Qt::AlignCenter );

    QSize a = QMainWindow::size();
    my_font_label = QFont("Times", a.height()/15, QFont::Bold);
    my_font_lost = QFont("Times", a.height()/7, QFont::Bold);
    competition->setFont(my_font_label);
    player1->setFont(my_font_label);
    min->setFont(my_font_label);
    player2->setFont(my_font_label);
    score1->setFont(my_font_lost);
    score2->setFont(my_font_lost);

    min->setReadOnly(true);
// ------------------------------
    QThread * Thread = new QThread;
    time_thread * intime = new time_thread;
    intime->moveToThread(Thread);

    connect(intime, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(Thread, SIGNAL(started()), intime, SLOT(counter()));
    time0.setHMS(0,0,0,0);

    Thread->start();
// ------------------------------

connect (start, SIGNAL(clicked(bool)), this, SLOT(flag1()));
connect (pause, SIGNAL(clicked(bool)), this, SLOT(flag0()));
connect (stop, SIGNAL(clicked(bool)), this, SLOT(flag_1()));
connect (Quit, SIGNAL(clicked(bool)), this, SLOT(close()));// закрытие приложения кнопкой в окне

}

MainWindow::~MainWindow()
{

}



void MainWindow :: update(int i)
{
j = i;
if (flag == 1)
{
   k = j - prom + m ;
}
if (flag == 0)
{
   m = k;
}
if (flag == -1)
{

}

time = time0.addSecs(k);
min->setText(time.toString("mm:ss"));
min->setAlignment( Qt::AlignCenter );
}

void MainWindow :: flag1()
{
    flag = 1;
    prom = j;
}

void MainWindow :: flag0()
{
    flag = 0;
    prom = j;
    start->setText("Продолжить");
}

void MainWindow :: flag_1()
{
    flag = -1;
    prom = j;
    m1 = m;
    m = -1;
    start->setText("Старт");
}

void MainWindow::resizeEvent(QResizeEvent* e)
{
    QSize a = QMainWindow::size();
    my_font_label = QFont("Times", a.height()/15, QFont::Bold);
    my_font_lost = QFont("Times", a.height()/7, QFont::Bold);
    competition->setFont(my_font_label);
    player1->setFont(my_font_label);
    min->setFont(my_font_label);
    player2->setFont(my_font_label);
    score1->setFont(my_font_lost);
    score2->setFont(my_font_lost);
}
