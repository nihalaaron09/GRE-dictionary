#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node * createNode(char[], char[]);

struct node{
  char key[20];
  char value[200];
}; 

int main()
{

// file handing error check
FILE *fWord, *fMeaning, *fout;
fWord=fopen("/home/nihal/CodingPractice/Projects/main_word.txt", "r");
fMeaning=fopen("/home/nihal/CodingPractice/Projects/meaning.txt", "r");
if (fWord==NULL){
	printf("File could not be read\n"); exit(1);}
if (fMeaning==NULL){
	printf("File could not be read\n"); exit(1);} 

char word[20];
char meaning[200];

//calculate number of words in file
int num_of_words=0;
while (fgets(meaning, sizeof(meaning),fMeaning))
    num_of_words++;

fclose(fMeaning);
fMeaning=fopen("/home/nihal/CodingPractice/Projects/meaning.txt", "r");

int i=0;
int code;



struct node * HastTable[10000];   //table for storing key-values

while (i<num_of_words){
 fscanf(fWord,"%s",word);     // fscanf because it reads a single word doesn't save new line
 fgets(meaning,sizeof(meaning),fMeaning);  // fgets becasue for fscanf reads onyl until blank space
 code = hashGenerator(word);
 HashTable[code]->key=word;
 HashTable[code]->value=meaning;
 i++;
}



} // main


