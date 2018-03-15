#include "time_thread.h"

time_thread::time_thread()
{

}
void time_thread:: counter()
{   
    int i = 0;
   for (;;)
   {      
    QThread::msleep(1000);
    i++;
    emit send(i);
   }

}



