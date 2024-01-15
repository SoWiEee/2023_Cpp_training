#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char scan_OP();
void scan_fraction(int* nump, int* denomp);
void OP_2fractions(char op, int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp);
void fraction_reduction(int numerator, int denominator, int *n_ansp, int *d_ansp);

int main() {
	int nump1;			/*		input - numerator of the first input fraction						*/
	int denomp1;		/*		input - denominator of the first input fraction						*/
	int nump2;			/*		input - numerator of the second input fraction						*/
	int denomp2;		/*		input - denominator of the second input fraction					*/
	int resultNump;		/*		output - numerator of the result fraction							*/
	int resultDenomp;	/*		output - denominator of the result fraction							*/
	char op;			/*		the operation of a fraction computation								*/
	char again;			/*		whether the user want to do another fraction computation or not		*/

	/*	call functions to read the operation and two fractions
		print result after computation and ask user do another fraction computation or not	*/
	do {
		op = scan_OP();
		scan_fraction(&nump1, &denomp1);
		scan_fraction(&nump2, &denomp2);
		OP_2fractions(op, nump1, denomp1, nump2, denomp2, &resultNump, &resultDenomp);
		if (resultDenomp < 0) {
			resultNump *= -1;
			resultDenomp *= -1;
		}
		printf("The result of %d/%d %c %d/%d is: %d/%d.\n", nump1, denomp1, op, nump2, denomp2, resultNump, resultDenomp);
		printf("Do another fraction computation? (y/n)\n");
		scanf(" %c", &again);
	} while (again == 'y' || again == 'Y');

	system("pause");
	return 0;
}

/*	read a valid operation(+, -, *, /)	*/
char scan_OP() {
	char op, discard;
	bool valid = false;

	do {
		printf("Input what operation you want to do(+, -, *, /).=>");
		scanf(" %c", &op);
		if (op == '+' || op == '-' || op == '*' || op == '/')
			valid = true;
		else
			printf("Input invalid!!\n");
		do
			scanf("%c", &discard);
		while (discard != '\n');
	} while (!valid);
	
	return op;
}

/*	read a valid fraction	*/
void scan_fraction(int* nump, int* denomp) {
	char slash, discard;
	bool valid = false;

	do {
		printf("Input a fraction as two integers separated by a slash.=>");
		scanf("%d%c%d", nump, &slash, denomp);
		if (slash == '/'&&*denomp != 0)
			valid = true;
		else
			printf("Input invalid!!\n");
		do
			scanf("%c", &discard);
		while (discard != '\n');
	} while (!valid);
}

/*	do a fraction computation	*/
void OP_2fractions(char op, int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp) {
	switch (op)
	{
	case '+':
		fraction_reduction(n1*d2 + n2*d1, d1*d2, n_ansp, d_ansp);
		break;
	case '-':
		fraction_reduction(n1*d2 - n2*d1, d1*d2, n_ansp, d_ansp);
		break;
	case '*':
		fraction_reduction(n1*n2, d1*d2, n_ansp, d_ansp);
		break;
	case '/':
		if (n2 == 0) {
			printf("Division by zero.\n");
			system("pause");
			exit(1);
		}
		else
			fraction_reduction(n1*d2, d1*n2, n_ansp, d_ansp);
		break;
	default:
		printf("Operation invalid!!\n");
		system("pause");
		exit(1);
	}
}

/*	do a fraction reduction		*/
void fraction_reduction(int numerator, int denominator, int *n_ansp, int *d_ansp) {
	int gcd = 0, remainder = 0, n1 = numerator, n2 = denominator;

	remainder = n1 % n2;
	while (remainder != 0) {
		n1 = n2;
		n2 = remainder;
		remainder = n1 % n2;
	}
	gcd = n2;

	*n_ansp = numerator / gcd;
	*d_ansp = denominator / gcd;
}