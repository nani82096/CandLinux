#include	<stdio.h>

void add ( int a, int b)
{
	printf ("add = %d\n", a+b);
}

void mul ( int a, int b)
{
	printf ("Multiplication = %d\n", a*b);
}

void div ( int a, int b)
{
	printf ("Div = %d\n", a/b);
}

void sub ( int a, int b)
{
	printf ("Diff = %d\n", a-b);
}


int main(int argc, char *argv[])
{
	
	int choice;
	if ( argc == 3) {
		printf ("\n\n----------Options----------\n0.Addition\n1.Subtraction\n2.Multiplication\n3.Division\n\tEnter You choice");
		scanf ("%d",&choice);
	
		void (*fp[4])(int, int) = {add,sub,mul,div};
		fp[choice]( atoi (argv[1]), atoi (argv[2]) );
	} else {
		printf ("Go To Hell \n");
	}
	return 0;

}
