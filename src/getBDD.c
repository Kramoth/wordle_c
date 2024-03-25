#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_LEN 2200

int main(){
	char bdd[2309][6];
	FILE* fichier=NULL;
	fichier=fopen("ressource/bdd_wordle.txt","r");
	//2200 characters, longest line
	char line[MAX_LINE_LEN];
	char tok[MAX_LINE_LEN];
	char str[]="Wordle Words List Starting With A\n";

		for(char letter='A';letter<='Z';letter++)
		{
			char str[35];
			sprintf(str,"Wordle Words List Starting With %c\n",letter);
			printf("%s\n",str);
			fichier=fopen("ressource/bdd_wordle.txt","r");
			if(fichier!=NULL)
			{
				while(fgets(line, MAX_LINE_LEN,fichier)!=NULL)
				{
					if(!strcmp(line,str))
					{
						printf("found A");
						fgets(line, MAX_LINE_LEN,fichier);
						fgets(line, MAX_LINE_LEN,fichier);
						printf("%s",line);
					}
				}
				fclose(fichier);
			}
			else
			{
				printf("file not opened\n");
			}
	}
}