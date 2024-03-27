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
    char restart='c';
    int randomIndex;
	srand(time(NULL));
	while(restart!='q')
	{


		randomIndex=rand()%2310;
		printf("%s\n",listeMots[randomIndex]);

		char guess[6];
		
		int num_try=0;
		while(num_try<6)
		{
			num_try++;
			printf("this is try number: %d\n",num_try);
			printf("Please enter a 5-letter word: \n");
			scanf("%s",guess);
			int valid=0;
			while(!valid)
			{
				if(checkValidWord(guess, listeMots))
				{
					valid=1;
				}
				else
				{
					printf("Please enter a valid 5-letter word: \n");
					scanf("%s",guess);
				}
			}
			char try[]="xxxxx";
			checkLetters(listeMots[randomIndex],guess,try);
			printf("%s\n",try);
			printf("--------------------------\n");
			if(!strcmp(try,"vvvvv"))
			{
				printf("you have won\n");
				break;
			}
		}
		switch(num_try){
		case 1:
			printf("Fantastic, you made it in %d try\n",num_try);
			break;
		case 2:
			printf("Very good, you made it in %d tries\n",num_try);
			break;
		case 3:
			printf("Well done, you made it in %d tries\n",num_try);
			break;
		case 4:
			printf("Nice, you made it in %d tries\n",num_try);
			break;
		case 5:
			printf("Good, you made it in %d tries\n",num_try);
			break;
		case 6:
			printf("Oh, you made it in %d tries\n",num_try);
			break;
		default:
			printf("Oh no you should have guess %s\n",listeMots[randomIndex]);
			break;

		}
		printf("Do you want to restart? Press any key to restart or 'q' to quit\n");
		scanf(" %c",&restart);
		printf("%c\n",restart);
	}
}