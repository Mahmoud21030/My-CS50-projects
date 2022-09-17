
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
int main(){}
typedef struct ST_cardData_t
{
	char cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	OK,
	WRONG_NAME,
	WRONG_EXP_DATE,
	WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	char temp[25];
	printf("**Please Enter The CardHolder Name: ");
	scanf("%s",cardData->cardHolderName);

	/* Checking if the length of the string is between 19 and 25 characters. If it is, it assigns the
	adress of temp to cardData->cardHolderName. */
	if (strlen(temp) > 19 && strlen(temp) < 25)
	{

		printf("error %s", temp);
		return OK;
	}
	else
	{
		return WRONG_NAME;
	}
}
	/* Checking if the length of the string is between 19 and 25 characters. If it is, it assigns the
		adress of temp to cardData->cardHolderName. */
	if (strlen(temp) > 19 && strlen(temp) < 25 && s_isalpha(temp))
	{
		strcpy(cardData->cardHolderName, temp);
		printf("error %s", cardData->cardHolderName);
		return OK;
	}
	else
	{
		return WRONG_NAME;
	}


//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