#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ConvertCharToInt(char input){
char input2[2];
input2[1]=input;
input2[2]='\0';
return (int) strtol(&input, NULL, 10);	
}

void main(){
char input;	
int input2;
printf("Enter a phrase");
scanf("%c",input);	
input2=ConvertCharToInt(input);
printf("%d",input2);

}