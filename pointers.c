


#include <stdio.h>
#include <stdlib.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";

int* list1;
int* list2;

char count = 0;


void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n",
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));

}

void copycodes(char* text, int* list, char* count) {
  while(*text) { //while *text points to something non-zero
    printf("textaddr %X listaddr%X\n",text, list);
    *list = *text; //copy what's at text to what's at list
    printf("copied %c -> %X\n", *text, *list);
    text++; //increment text position
    list++; //increment list position
    (*count)++; //increment counter (pointed at by *count)
    printf("new count: %d\n", *count);
  }
}

void work() {
   list1 = malloc(80);
   list2 = malloc(80);
  copycodes(text1, list1, &count);
  copycodes(text2, list2, &count);
}

int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
