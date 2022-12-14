#include<stdio.h>

int add(int var1, int var2) { return var1+var2; }
int sub(int var1, int var2) { return var1-var2; }
int mul(int var1, int var2) { return var1*var2; }
int div(int var1, int var2) { return var1/var2; }

/*
int main(void)
{
	int var1, var2, result;
	char ch;
	printf("Enter the choice\n");
	scanf("%c", &ch);
	printf("Enter the inputs\n");
	scanf("%d %d", &var1, &var2);
	switch(ch)
	{
		case '+' : result = add (var1, var2); break;
		case '-' : result = sub (var1, var2); break;
		case '*' : result = mul (var1, var2); break;
		case '/' : result = div (var1, var2); break;
		default : printf("Enter proper choice\n");
	}
	printf("the result of %d %c %d = %d\n",var1, ch, var2, result);
	return 0;
}
*/
void switch_fun(int var1, int var2, int (*ptrfun)(int,int))
{
	int result = ptrfun(var1, var2);
	printf("result = %d" ,result);
}

int main(void)
{
	int var1, var2;
	char str[10];
	printf("Enter the number\n");
	scanf("%d %d", &var1,&var2);
	switch_fun(var1, var2, add);
	return 0;
}
