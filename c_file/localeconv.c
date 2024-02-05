#include <locale.h>
#include <stdio.h>
int main ()
{
   struct lconv * lc;
   setlocale(LC_MONETARY, "it_IT");
   lc = localeconv();
   printf("当地货币符号: %s\n",lc->currency_symbol);
   printf("国际货币符号: %s\n",lc->int_curr_symbol);
   setlocale(LC_MONETARY, "en_US");
   lc = localeconv();
   printf("当地货币符号: %s\n",lc->currency_symbol);
   printf("国际货币符号: %s\n",lc->int_curr_symbol);
   setlocale(LC_MONETARY, "en_GB");
   lc = localeconv();
   printf ("当地货币符号: %s\n",lc->currency_symbol);
   printf ("国际货币符号: %s\n",lc->int_curr_symbol);
   printf("小数点 = %s\n", lc->decimal_point);
   
   return 0;
}