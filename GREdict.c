#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

# define max_size 100000


struct node {
  char key[20];
  char value[200];
};
int hash (char[]);
void ViewList(struct node * []);
void FlashCard(struct node * []);
char * LowerCase(char[]);
void Search(struct node *[]);


/*----------Main----------*/
int main() {
	// file handing error check
	FILE *fWord, *fMeaning, *fout;
	fWord=fopen("/home/nihal/CodingPractice/Projects/main_word.txt", "r");
	fMeaning=fopen("/home/nihal/CodingPractice/Projects/meaning.txt", "r");
	if (fWord==NULL) {
		printf("File could not be read\n"); exit(1);}
	if (fMeaning==NULL) {
		printf("File could not be read\n"); exit(1);}

	char word[20];
	char meaning[200];

	//calculate number of words in file
	int num_of_words=0;
	while (fgets(meaning, sizeof(meaning),fMeaning))
		num_of_words++;

	fclose(fMeaning);
	fMeaning=fopen("/home/nihal/CodingPractice/Projects/meaning.txt", "r");

	// create hashlist
	int i=0;
	long int code;
	struct node *HashTable[max_size] = {0};		//table for storing key-values
	while (i<num_of_words) {
		fscanf(fWord,"%s",word);		// fscanf because it reads a single word doesn't save new line
		fgets(meaning,sizeof(meaning),fMeaning);		// fgets becasue for fscanf reads onyl until blank space
		code = hash(word);		// obtain hash code for current word
		struct node * new_node = malloc(sizeof(struct node));		//define temporary new_node
		strcpy(new_node->key,LowerCase(word));
		strcpy(new_node->value,LowerCase(meaning));
		HashTable[code] = new_node;		// assign new_node at the code position in HashTable
		i++;
	}

	int flag=0;
	while(1) {
		int option=0;
		printf("Hit 1.View List 2.Flash Card Mode 3. Search a word\n");
		scanf("%d",&option);
		switch(option) {
			case 1: ViewList(HashTable);break;
			case 2: FlashCard(HashTable);break;
			case 3: Search(HashTable); break;
			default: printf("Invalid Option Try Again\n");break;
		}
		printf("To exit the application press 0 or press 9 to continue\n");
		scanf("%d",&flag);
		if(flag == 0) break;
		else continue;
	}
	printf("Good Bye. All the best for GRE. P.S. Propriety software of Nihal and Yash Co.\n");
}


/*----------Functions----------*/
int hash(char str[]) {
	int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
	int length=strlen(str);
	int i=0;
	int code=0;
	while (i<length) {
		code = code + (str[i]-64)*primes[i];
		i++;
	}
	return code;
}


void ViewList(struct node * HashTable[]) {
	long int i=0, count=0;
	for (;i<max_size; i++) {
		if (HashTable[i]==NULL)
			continue;
		else {
			printf("%s : %s", HashTable[i]->key, HashTable[i]->value);
			count++;
		}
	}
}


void FlashCard(struct node * HashTable[]) {
	printf("Welcome to the FlashCard mode! You will view a random word from the list. Try to guess its meaning.\n");
	srand(time(0));
	int input=0;
	int score=0;
	int answer=0,r;
	int exit=0;
	while(1) {
		while(1) {
			r = rand() % (max_size+1);
			if (HashTable[r] != NULL) break;
		}
		printf("Your word is: %s\nPress any key [0-9] to see its meaning.\n", HashTable[r]->key);
		scanf("%d",&input);
		if (input >= 0 || input <= 9)
			printf("The meaning is: %s\nDid you guess right? Press 0 for wrong answer 1 for right answer\n", HashTable[r]->value);
		scanf("%d",&answer);
		score = score + answer;
		printf("Your Score is: %d\nPress 4 to exit or 9 to continue\n",score);
		scanf("%d", &exit);
		if(exit == 4) break;
		else continue;
	}
	printf("Your total score is %d. Thank You for using Flash Card mode :)\n", score);
}// end of FlashCard mode


char * LowerCase(char str[]) {
	for(int i = 0; str[i]; i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}


void Search(struct node * HashTable[]) {
	char word[20];
	printf("Enter a word you want to search in the list: \n");
	scanf("%s", word);
	int new_code=hash(word);
	if (HashTable[new_code]==NULL)
		printf("Sorry, the word is not present in the list\n");
	else
		printf("Meaning is: %s", HashTable[new_code]->value);
	}
