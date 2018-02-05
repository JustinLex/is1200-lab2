#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define COLUMNS 6
int columncount = 1;

void print_number(int num)
  {
    if(columncount==6)
      {
        printf("%10d \n", num);
        columncount=1;
      }
    else
    {
      printf("%10d ", num);
      columncount++;
    }
  }

void print_sieves(int n)
{
  _Bool array [n];
  for(int i=0; i<n-1; i++)
    array[i]=1;
  for(int j=2; j<sqrt(n); j++)
    if(array[j]==1)
      for(int k=j*j; k<n; k+=j)
        array[k]=0;
  for(int l=2; l<n-1; l++)
    if(array[l]==1)
      print_number(l);
}


int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
