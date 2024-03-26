#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"getBDD.h"
#include<time.h>

int main()
{
	generateBDD("ressource/bdd_wordle.txt","ressource/bdd_wordle_clean.txt");
	char listeMots[TOTAL_WORDS][MAX_WORD_LENGTH];
    getWord("ressource/bdd_wordle_clean.txt",listeMots);

    int randomIndex;
	srand(time(NULL));
	randomIndex=rand()%2310;
	printf("%s\n",listeMots[randomIndex]);
}