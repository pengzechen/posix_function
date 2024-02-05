#include <stdio.h>
#include <stdlib.h>
 
 
int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
 
int values[] = { 5, 20, 29, 32, 63 };
 
int main ()
{
   int *item;
   int key = 32;
 
   /* 使用 bsearch() 在数组中查找值 32 */
   item = (int*) bsearch (&key, values, 5, sizeof (int), cmpfunc);
   if( item != NULL ) 
   {
      printf("Found item = %d\n", *item);
   }
   else 
   {
      printf("Item = %d could not be found\n", *item);
   }
   
   return(0);
}