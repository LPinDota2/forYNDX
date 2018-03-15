#ifndef TIME_THREAD_H
#define TIME_THREAD_H

#include <mainwindow.h>

class time_thread : public QObject
{
    Q_OBJECT
public:
    time_thread();


public slots:
void counter();

signals:
void send(int);
};

#endif // TIME_THREAD_H
