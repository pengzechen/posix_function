#include <locale.h>
#include <stdio.h>
#include <time.h>
 
int main ()
{
   time_t currtime;
   struct tm *timer;
   char buffer[80];
 
   time( &currtime );
   timer = localtime( &currtime );
 
   printf("语言环境为: %s\n", setlocale(LC_ALL, "en_GB.UTF-8"));
   strftime(buffer,80,"%c", timer );
   printf("日期是: %s\n", buffer);
 
  
   printf("语言环境为: %s\n", setlocale(LC_ALL, "de_DE.UTF-8"));
   strftime(buffer,80,"%c", timer );
   printf("日期是: %s\n", buffer);
 
   return(0);
}
