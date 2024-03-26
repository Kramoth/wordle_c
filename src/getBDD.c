#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"getBDD.h"

void generateBDD(char* input_file_name, char* output_file_name){
	FILE* file=NULL;
	FILE* output_file=NULL;
	output_file=fopen(output_file_name,"w");
	char line[MAX_LINE_LEN];
	char tmpWord[6];
		for(char letter='A';letter<='Z';letter++)
		{
			char str[35];
			sprintf(str,"Wordle Words List Starting With %c\n",letter);
			file=fopen(input_file_name,"r");
			while(fgets(line, MAX_LINE_LEN,file)!=NULL)
			{
				if(!strcmp(str, line))
				{
					fgets(line, MAX_LINE_LEN,file);
					fgets(line, MAX_LINE_LEN,file);

					char* token=strtok(line," ");

					while(token!=NULL)
					{
						if(strcmp(token,"\n"))
						{
							if(output_file!=NULL)
								fprintf(output_file,"%s\n",token);
							else
								printf("no output file");
						}
						token=strtok(NULL," ");
					}
				}
			}
			fclose(file);

		}
			fclose(output_file);
}

void getWord(char* bddName, char words[TOTAL_WORDS][MAX_WORD_LENGTH]){
	/*int randomIndex;
	srand(time(NULL));
	randomIndex=rand()%2310;*/
	FILE* bdd_file=NULL;
	bdd_file=fopen(bddName,"r");
	if(bdd_file==NULL)
	{
		printf("not able to open File");
		exit(0);
	}
	char word[MAX_WORD_LENGTH];
	int numWord=0;
	while(fgets(word,6,bdd_file)!=NULL && numWord<TOTAL_WORDS)
	{
		if (word[strlen(word) - 1] == '\n')
		{
            word[strlen(word) - 1] = '\0';
        }
    	if(strlen(word)>=MAX_WORD_LENGTH-1)
    	{
    		strcpy(words[numWord], word);
    		numWord++;
    	}
    }
}




