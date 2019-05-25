#include <setjmp.h>
#include<stdio.h>
#include<stdlib.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int main()
{
	int autoval;
	static int statval;
	volatile int volval;
	register int regval;

	autoval = 1; statval = 2; volval = 3; regval = 4; globval = 5;
	printf("\nInitially: ");
	printf("\nautoval = %d", autoval);
	printf("\nstatval = %d", statval);
	printf("\nvolval = %d", volval);
	printf("\nregval = %d", regval);
	printf("\nglobval = %d", globval);

	if(setjmp(jmpbuffer)!=0)
	{
		printf("\n\nInside if-condition: ");
		printf("\nautoval = %d", autoval);
		printf("\nstatval = %d", statval);
		printf("\nvolval = %d", volval);
		printf("\nregval = %d", regval);
		printf("\nglobval = %d", globval);
		return 0;
	}

	autoval = 10; statval = 20; volval = 30; regval = 40; globval = 50;
	f1(autoval, statval, volval, regval);
	return 0;
}

static void f1(int autoval, int statval, int volval, int regval)
{
	printf("\n\nIn f1(): ");
	printf("\nautoval = %d", autoval);
	printf("\nstatval = %d", statval);
	printf("\nvolval = %d", volval);
	printf("\nregval = %d", regval);
	printf("\nglobval = %d", globval);
	globval = 100;
	f2();
}


static void f2()
{
	longjmp(jmpbuffer, 1);
}
