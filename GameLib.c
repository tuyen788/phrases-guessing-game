/* Tuyen Hoang 1001746220*/
#include "GameLib.h"

void StartGame(char ChosenPhrase[])
{
	#include "PhraseBank.txt"
	printf("Welcome to %d strikes - YOU'RE OUT - the CSE version",STRIKES);
	printf("\nPlease pick a phrase from the following menu");
	int i=0;
	int choice;
	while((PhraseBank[i])!="")
	{
		CheckPhrase(PhraseBank[i]) ;
		char DashPhrase[81]={};
		DashIt(PhraseBank[i],DashPhrase);
		printf("\n%d.\t%s",i+1,DashPhrase);
		i++;
	}
	printf("\nEnter choice: ");
	scanf("%d",&choice);
	while((choice < 1)||(choice > ((sizeof(PhraseBank)/8 )- 1 )))
	{
		printf("\nPlease choose one of the numbers shown. Enter choice: ");
		scanf("%d",&choice);
	}
	
	strcpy(ChosenPhrase,PhraseBank[choice-1]);
	
}

// this function checks Phrase to see if it contains a dash, if yes exit the program
void CheckPhrase(char *Phrase)
{
	int position;
	char *DashCheck=NULL;
	DashCheck=strchr(Phrase,'-');
	if (DashCheck!=NULL)
	{
		position=abs(DashCheck-Phrase);
		printf("\n%s contains a dash position %d!!\nYou broke the rules. We can't play. BYE!!",Phrase,position);
		exit(0);
	}
}

// this function asks for a letter, checks if it's in the chosen phrase
// and replaces dashes with the appropriate letters.
int GuessALetter(char Phrase[], char DashedPhrase[], char UpperPhrase[])
{
	char Guess;
	char *FindGuess=NULL;
	char UpperPhraseCopy[81];
	int FoundALetter=0;
	int distance;
	strcpy(UpperPhraseCopy,UpperPhrase);
	printf("\n\nGuess a letter: ");
	scanf(" %c",&Guess);
	Guess=toupper(Guess);
	FindGuess=strchr(UpperPhraseCopy,Guess);
	while(FindGuess!=NULL)
	{
		FoundALetter=1;
		*FindGuess='-';
		distance=abs(UpperPhraseCopy-FindGuess);
		DashedPhrase[distance]=Phrase[distance];
		FindGuess=strchr(UpperPhraseCopy,Guess);	
	}
	if(FoundALetter==0)
	{
		FindGuess=strchr(UpperPhrase,Guess);
		if(FindGuess!=NULL)
		{
			FoundALetter=1;
		}
		
	}
	
	return FoundALetter;
}

// this function takes in a phrase to create a dashes version of it
void DashIt(char *Phrase, char DashPhrase[])
{
	int i=0;
	for(i=0;i<=strlen(Phrase);i++)
	{
		DashPhrase[i]=toupper(*(Phrase+i));
	}
	
	char *findLetter=NULL;
	char Alphabets[27]="QWERTYUIOPASDFGHJKLZXCVBNM";
	findLetter=strpbrk(DashPhrase,Alphabets);
	while(findLetter!=NULL)
	{
		*findLetter='-';
		findLetter=strpbrk(DashPhrase,Alphabets);
	}
}
