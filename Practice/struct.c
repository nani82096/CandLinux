#include	<stdio.h>
#if 0
struct point
{
	int a;
	int b;
}p1,p2;
struct point add(struct point , struct point);
struct point makepoint(int , int );
void main(void)
{
	//struct point p1,p2;
	p1 = makepoint(5,100);
	p2 = makepoint(10,200);
	printf("p1.a = %d and p1.b = %d \n", p1.a, p1.b);
	printf("p2.a = %d and p2.b = %d \n", p2.a, p2.b);
	p1 = add(p1,p2);
	printf("p1.a = %d and p1.b = %d \n", p1.a, p1.b);
	
}
struct point makepoint( int x, int y)
{
	struct point temp;
	temp.a = x;
	temp.b = y;

	return temp;
}
struct point add(struct point p1, struct point p2)
{
	struct point temp;
	temp.a = p1.a + p2.a;
	temp.b = p1.b + p2.b;
	return temp;
}
#endif
#if 0
struct ABC{
	int a;
	int b;
	int c;
	short int d;
	char e;
	};
int main(void)
{
	printf("%d\n",(int )&((struct ABC*)0)->c);
	return 0;
}


#endif


# if 1
 struct D { 
    			char b; 
    			char d;
				char s; 
 		}s4; 
int main(void)
{
	printf("%d", sizeof(s4));
	return 0;
}
# endif


