#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

struct node{
	// Data
	char msg[5];
	// refer to the bottom for why this int exist
	// Pointer to next node
	struct node * nextNode;
	// to be used for 
	struct node * previousNode;
};

struct node * createNode(struct node * pointer,char leftChar,int leftNumber,char op,char rightChar,int rightNum){
	struct node * newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->msg[0]=leftChar;
	newnode->msg[1]=leftNumber+'0';
	newnode->msg[2]=op;
	newnode->msg[3]=rightChar;
	newnode->msg[4]=rightNum+'0';
	newnode->nextNode=pointer;
	return newnode;
}

void printLinklist(struct node * node){
	int x;
	while(node!=0){
		for(x=0;x<5;x++){
			printf("%c",node->msg[x]);	
		}
		printf(" %c ",',');
		node=node->nextNode;
	}
	printf("\n");
}




char * message;

//Function prototypes
void Write_JM_DataToFile(char * outputfile);
void Read_JM_DataFromFile(char * inputfile);

void main(){

	//Write_JM_DataToFile("out.txt");
	Read_JM_DataFromFile("out.txt");
}

void Write_JM_DataToFile(char * outputfile){

	//Open file for writing
	FILE * file = fopen(outputfile, "w"); 
	
	//Write text to file
	
	// a1<b1,b1<c1,c1<d1.
	fprintf(file, "%c%d%c%c%d,", 'a',1,'<','b',1);   //fprintf is to print values into file
	fprintf(file, "%c%d%c%c%d,", 'b',1,'<','c',1); 
	fprintf(file, "%c%d%c%c%d.", 'c',1,'<','d',1); 
	//Close file
	fclose(file);
}  

void Read_JM_DataFromFile(char * inputfile){

	//Open a file for reading
	FILE * file= fopen(inputfile, "r");
	
	//Read a file character and integers
	//a1<b1,b1<c1,c1<d1.
	int x;
	char leftChar;
	int leftNumber;
	char op;
	char rightChar;
	int rightNum;
	char comma;
	struct node * lastnode;
	struct node * firstnode;
	int i;
	int count;
	//to note that it is the last node;
	i=1;
	struct node * conductor;
	while( !feof(file) && comma != '.'){
		//Use fscanf to read one pair of J&M data
		fscanf(file, "%c%d%c%c%d%c", &leftChar, &leftNumber, &op, &rightChar, &rightNum, &comma);
		
		//Print on screen to check if has been read correct
		
		//printf("%c%d%c%c%d\n", leftChar, leftNumber, op, rightChar, rightNum);
		if(i==1){
			lastnode=(struct node *) malloc( sizeof(struct node) );
			lastnode->msg[0]=leftChar;
			lastnode->msg[1]=leftNumber+'0';
			lastnode->msg[2]=op;
			lastnode->msg[3]=rightChar;
			lastnode->msg[4]=rightNum+'0';
			lastnode->nextNode=0;
			conductor=lastnode;
			count=0;
			i=i+1;
		}
		else{
			conductor=createNode(conductor,leftChar,leftNumber,op,rightChar,rightNum);
			count=count+1;
		}
		
	}
	firstnode=conductor;
	while(conductor!=0){
		char temp;
		char temp1;
		
		if(conductor->msg[2]=='>'){
			conductor->msg[2]='<';
			temp = conductor->msg[0];
			temp1 = conductor->msg[1];
			conductor->msg[0]=conductor->msg[3];
			conductor->msg[1]=conductor->msg[4];
			conductor->msg[3]=temp;
			conductor->msg[4]=temp1;
		}
		conductor=conductor->nextNode;
	}
	


	for(x=strlen(rearrangearray);x!=-1;x--){
		printf("%c",rearrangearray[x]);
	}
*/
	//Close the file
	fclose(file);
	
}