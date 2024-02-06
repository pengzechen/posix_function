#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <utime.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  struct stat st; 
  stat(argv[1], &st);
  printf("最近修改时间 %s\n",ctime(&st.st_mtime)); 
  printf("最近访问时间 %s\n",ctime(&st.st_atime)); 


  struct utimbuf utb = {st.st_atime - 24*3600, st.st_mtime - 24*3600};

  utime(argv[1], &utb);
  stat(argv[1], &st);
  printf("执行 utime 后(时间减去一天)\n");
  printf("最近修改时间 %s\n",ctime(&st.st_mtime)); 
  printf("最近访问时间 %s\n",ctime(&st.st_atime)); 

  return 0;
}

