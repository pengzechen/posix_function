#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[] = "Geeks for Geeks"; 
    char* token; 
    char* rest = str; 
  
    while ((token = strtok_r(rest, " ", &rest))) 
        printf("%s\n", token); 
  
    return (0); 
}
