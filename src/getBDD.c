#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

