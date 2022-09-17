#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include "Card/Card.h"



int main()
{
	ST_cardData_t *user1=calloc(1,sizeof(ST_cardData_t));
	getCardHolderName(user1);
	getCardPAN(user1);
	getCardExpiryDate(user1);

	free(user1);
}




//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