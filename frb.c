//
//  frb.c
//  FileReadBinary
//
//  Created by Mewlan Musajan on 10/29/17.
//  Copyright (c) 2017 Mewlan Musajan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DICT_LEN sizeof(struct AStruct)

unsigned int L;

struct AStruct
{
	char errorViewString[52];
	char dataInsertInstructionViewString[80];
	char dataUpdatedViewString[32];
	char searchViewString[32];
	char catalogViewString[32];
	char backViewString[32];
	char selectLanguageViewString[120];
	char functionDataInsertString[32];
	char functionSearchString[32];
	char functionCatalogString[32];
	char functionSelectLanguageString[32];
} SStruct;

typedef enum Language
{
	english,
	chinese,
	uyghur
} LANG;

LANG CurrentLanguage;

/******Model******/

void read()
{
	FILE *fp;
	if ((fp = fopen("iWillDictViewString.dat", "rb")) == NULL)
	{
		printf("can not open file.\n");
		exit(0);
	}
	switch (CurrentLanguage) {
		case english:rewind(fp);break;
		case chinese:fseek(fp, DICT_LEN, 0);break;
		case uyghur:fseek(fp, 2 * DICT_LEN, 0);break;
		default:break;
	}
	if (fread(&SStruct, DICT_LEN, 1, fp) != 1)
	{
		printf("struct write error\n");
	}
	printf(SStruct.errorViewString);
	putchar('\n');
	printf(SStruct.dataInsertInstructionViewString, '\n', '\n', '\n');
	putchar('\n');
	printf(SStruct.dataUpdatedViewString, '\0');
	putchar('\n');
	printf(SStruct.searchViewString);
	putchar('\n');
	printf(SStruct.catalogViewString);
	putchar('\n');
	printf(SStruct.backViewString);
	putchar('\n');
	printf(SStruct.selectLanguageViewString, '\t', '\n', '\t', '\n', '\t');
	putchar('\n');
	printf(SStruct.functionDataInsertString, '\t');
	putchar('\n');
	printf(SStruct.functionSearchString, '\t');
	putchar('\n');
	printf(SStruct.functionCatalogString, '\t');
	putchar('\n');
	printf(SStruct.functionSelectLanguageString, '\t');
	putchar('\n');
	fclose(fp);
}

/******Model******/


int main(int argc, char const *argv[])
{
	CurrentLanguage = english;
	read();
	return 0;
}