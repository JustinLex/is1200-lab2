/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int current_column = 1;

//written by Justin
int print_number(int number) {
  printf("%10d", number); //print number
  if(current_column == 6) {
    printf("\n"); // if we're in last column, print newline and reset
    current_column = 1;
  }
  else current_column++;
  return 0;
}

int is_prime(int n){
  for(int i=2; i<n; i++) {
    if(n%i == 0) return 0;
  }
  return 1;
}

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS

  for( int i = 2; i<= n; i++) {
    if(is_prime(i)) print_number(i);
  }

  printf("\n");
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
