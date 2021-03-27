/* Tuyen Hoang 1001746220*/
#ifndef _GAMELIB_H
#define _GAMELIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 81
#define STRIKES 3

void StartGame(char ChosenPhrase[]);
void CheckPhrase(char *Phrase);
int GuessALetter(char Phrase[], char DashedPhrase[], char UpperPhrase[]);
void DashIt(char *Phrase, char DashPhrase[]);

#endif
