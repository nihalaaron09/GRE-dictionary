#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node * createNode(char[], char[]);

struct node{
  char Word[20];
  char definition[200];
  struct node *next;
  struct node *prev;
};

int main()
{

FILE *fWord, *fMeaning, *fout;

int num_of_words=0;
fWord=fopen("/home/nihal/CodingPractice/Projects/main_word.txt", "r");
fMeaning=fopen("/home/nihal/CodingPractice/Projects/meaning.txt", "r");

// file handing error check
if (fWord==NULL){
	printf("File could not be read\n"); exit(1);}
if (fMeaning==NULL){
	printf("File could not be read\n"); exit(1);} 

//fout=fopen("/home/nihal/CodingPractice/Projects/out.txt", "w");
char word[20];
char meaning[200];

//calculate number of words in file
while (fgets(meaning, sizeof(meaning),fMeaning))
    num_of_words++;
fclose(fMeaning);
fMeaning=fopen("/home/nihal/CodingPractice/Projects/meaning.txt", "r");

int i=0;

struct node * head;
while (i<num_of_words){
 fscanf(fWord,"%s",word);     // fscanf because it reads a single word doesn't save new line
 fgets(meaning,sizeof(meaning),fMeaning);  // fgets becasue for fscanf reads onyl until blank space
 struct node * new_node=createNode(word, meaning);
 if (i==0){
        head=new_node;
        new_node->next=NULL;
	new_node->prev=NULL;
        }
 else{
      new_node->next=head;
      head->prev=new_node;
      head=new_node;
  } //if-else

 //printf("%s : %s", word,meaning);
 //fprintf(fout,"%s : %s", word, meaning);
 i++;
}
 i=0;
 struct node *iter=head;
 while(i<num_of_words)
 {
  printf("%s : %s", iter->Word, iter->definition);
  iter=iter->next;
  i++;	
 }


} // main


// takes in a word and its meaning and returns its equivalent node
struct node *createNode(char word[], char meaning[])
{
 struct node *new_node = malloc(sizeof(struct node));
 strcpy(new_node->Word, word);
 strcpy(new_node->definition, meaning);
 return new_node;
}//createNode


