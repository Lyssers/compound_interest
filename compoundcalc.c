#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int parser(char * input, double * output){
	
	//This is to store the endptr for the string-to-double function
	char * endptr;	
	char * cpy = input;
	//While the value at input pointer is NOT equals to or more than 0 and is not equals to or less than 9, increment the input pointer
	//loops through input symbols until it's a digit, basically

	while (!(*input >= '0' && *input <= '9'))
	{
		input++;
	}
	
	//Converts string to double, stopping at first non-numeric digit	
	*output = strtod(input, &endptr);
	free(cpy);
	input = NULL;
	cpy = NULL;

	//debug
	//printf("\n%lf Result after conersion", *output);
	
	if (*output == 0.0){
		return 1;	
	}
	else return 0;
}

void buffflush(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
	//Input time in years, rate in % and principal (original sum)
	double rate, years, principal, frequency;
	printf("\nThis program calculates compound interest.\nPlease Enter the following information omitting currency symbols.");

	//Cleaning the principal of currency symbols
	printf("\nPlease Enter initial investment (principal): ");
	char * principal_s = malloc(sizeof(char)*256);
	scanf("%25s", principal_s);
	parser(principal_s, &principal);	
	principal_s = NULL;
	buffflush();
	
	//Clean up interest rate	
	printf("\nPlease Enter (simple) interest rate: ");
	char * rate_s = malloc(sizeof(char)*256);	
	scanf("%15s", rate_s);
	parser(rate_s, &rate);
	rate_s = NULL;
	buffflush();

	//Cleaning up frequency
	printf("\nPlease Enter frequency of interest payouts per year: ");
	char * frequency_s = malloc(sizeof(char)*256);
	scanf("%25s", frequency_s);
	parser(frequency_s, &frequency);
	frequency_s = NULL;
	buffflush();

	//Cleaning up years
	printf("\nPlease Enter time in years: ");
	char * years_s = malloc(sizeof(char)*256);
	scanf("%25s", years_s);
	parser(years_s, &years);
	years_s = NULL;
	buffflush();

	//Calculation
	double flat_interest = (principal * (1.0+ rate/100 * years));
	double end_amount = (principal * pow(1.0+(rate/100), frequency * years));
	double compound = (end_amount - principal);

	printf("\nStarting Balance: %.2f: ", principal);
	printf("\nFinal Balance with Flat (Simple) Interest: %.2f", flat_interest);

	printf("\n");

	printf("\nCompound interest: %.2f ", compound);
	printf("\nFinal Balance with Compound Interest: %.2f ", end_amount);

	return 0;
}
