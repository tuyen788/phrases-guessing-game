/* Tuyen Hoang 1001746220*/
#include "GameLib.h"

int main(void)
{
	char Phrase[MAX_INPUT]={};
	char DashedPhrase[MAX_INPUT]={};
	char UpperPhrase[MAX_INPUT]={};
	int strikes=0;
	int i=0;
	StartGame(Phrase);
	DashIt(Phrase,DashedPhrase);
	printf("\nHere's the phrase you need to guess");
	printf("\n%s",DashedPhrase);
	// capitalize and save each letter in Phrase into UpperPhrase
	for(i=0;i<strlen(Phrase);i++)
	{
		UpperPhrase[i]=toupper(Phrase[i]);
	}
	
	do
	{
		if (GuessALetter(Phrase,DashedPhrase, UpperPhrase)==0)
		{
			strikes++;
			printf("Strike %d\n",strikes);
		}
		if(strchr(DashedPhrase,'-')!=NULL)
			printf("%s",DashedPhrase);
		
	}
	while(strchr(DashedPhrase,'-')!=NULL && strikes<STRIKES);
	
	if(strikes<STRIKES)
	{
		printf("\n\nYou figured it out!\nThe phrase was:\n%s",DashedPhrase);
		
		printf("\n\nYOU WIN!!!\n");
	}
	else
	{
		printf("\n\n%d strikes - YOU'RE OUT!!!\n",strikes);
	}
	

}
