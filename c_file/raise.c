#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_catchfunc(int);
int main()
{

   if( signal(SIGINT, signal_catchfunc) == SIG_ERR) 
   {
      printf("错误：不能设置信号处理程序。\n");
      exit(0);
   }
   printf("开始生成一个信号\n");
   if( raise(SIGINT) !=0 ) 
   {
      printf("错误：不能生成 SIGINT 信号。\n");
      exit(0);
   }
   printf("退出...\n");
   return(0);
}
void signal_catchfunc(int signal)
{
   printf("!! 信号捕获 !!\n");
}
