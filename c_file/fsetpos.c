#include <stdio.h>

int main ()
{
   FILE *fp;
   fpos_t position;

   fp = fopen("file.txt","w+");
   fgetpos(fp, &position);
   fputs("Hello, World!", fp);
  
   fsetpos(fp, &position);
   fputs("这将覆盖之前的内容", fp);
   fclose(fp);
   
   return(0);
}
