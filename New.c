#include <stdio.h>

int main()
{
	// variables in which to store data
	char name[15];
	char unit[15];
	int amount;

	// taking input and storing in variables
	// a sampleinput string would be:
	// "Faraz owns 500 acres of land"
#ifdef __STDC_LIB_EXT1__ // only use swscanf_s if __STDC_LIB_EXT1__ is already defined
	scanf_s("%s %*s %d %s", name, &amount, unit);
#endif
	// use normal scanf_s
	scanf("%s %*s %d %s", name, &amount, unit);
	// print out new string using the extracted values
	printf("% d %s of land is owned by %s\n", amount, unit, name);

	return 0;
}
//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