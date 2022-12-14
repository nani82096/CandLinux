

#include	 <stdio.h>

#if 0

void func(void);
   
static count; /* Global variable - static is the default */

void main()
{
	while (count++<=1) 
	{
		func();
	}
	

}

void func( void )
{
	/*static int i = 5;
	i++;
	printf("i is %d and count is %d\n", i, count);*/
	int x = 5;
	int y = 6;
	int z = ((x++) || (y--));
	printf("\n%d %d %d \n", x, y, z);
}

#endif

# if 0 
main(void)

{
	int a  = 3;
	printf("\n%d %d %d" , a++, ++a, a);
}
#endif

# if 0
main(void)
{
	int c;
	char s[50];
	int i = 0;
	int sum = 0;
	int n;
	int d;
	int length;
	while ( ( c = getchar() )!= EOF && c != '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	d = atoi(s);
	printf("\n%d\n", d);
	n = d;
	int temp;
	if ( n < 0)
		n = -1 * n;
	while (n > 0) {
		temp = n % 10;
		sum++;
		n = n / 10;
	}
	length = i;
	
	for ( i = 0; i < length ; i++) {

		if ( s[i] == ' ') {
			length --;
		}
	}
	i = 0;
	
	
	if ( s[i] == '+' || s[i] == '-' ) {
		
		length = length - 1;
		
		if ( length == sum )
			printf("\nAbove is Valid Integer \n");
		else
			printf("\nNot Valid Integer\n");
	}
	else {
		if ( length  == sum)
			printf(" \nAbove is Valid integer\n");
		else
			printf("\nNot Valid integer \n");
	}
}
#endif

# if 0
void main(void)

{

	int a;
	int b;
	scanf("%3d%4d", &a, &b);
	printf("%d %d", a, b);
}
#endif

#if 0

void main (void)

{
	 int i = 15;
	
	printf("\n%08x\n", i << 25);
	printf("\n%08x\n", i << 26);
	printf("\n%08x\n", i << 27);
	printf("\n%08x\n", i << 28);
	printf("\n%08x\n", i << 29);
	printf("\n%08x\n", i << 30);
	
	printf("i << 1\n%08x\n", i << 1);
	
	printf("\n%08x\n", i << 31);
	printf("\n%08x\n", i << 32);
	printf("\n%08x\n", i << 33);
}
#endif

# if 0
main()

{
	unsigned int a ;
	scanf("%d",&a);
	
	int i;
	for ( i = 31; i >=0; i--){
		printf("%d",a >> i & 1);
	}
	printf("\n");
	printf("\n%d\n",a);
	printf("\n%08x\n",a);;
}
#endif


# if 0
main()

{

	unsigned char a = -7;
	printf("%x",a);
}
#endif

#if 0 

void main(void)
{
	int a = 5;
	printf("%d %d %d %d %d", a++, ++a, a, ++a, a++);
	printf("\n");
}
#endif
#define MAX
#if 0
void main(void)
{

	printf(" \n%d\n", MAX);
}
#endif
#if 0
void main(void)

{

	int a = 3+
	printf("%dghik\n", 36);
	printf("%d\n", a);
}
#endif

# if 0
main (void)
{
	int a = 2*
//	while (1)
			printf("%d a\n",a);
	
}
#endif

#if 0
main(void)

{

	printf("HI"),
	printf("Hello"),
	printf("Hwo ru ");
}
#endif

#if 0

void main(void)
{

	int i = 0;
	int j = 5;
	switch (2) {

		case 1:
			printf(" hi how are u \n");
			for(i = 0; i < 10; i++) {
				printf(" i = %d j = %d\n", i, j);
				j++;
		case 2:
			i++;		
			}
			break;
		default: 
			printf(" out of loop\n");
	}
}
#endif

#if 0
main()
{
	char ch;
	scanf("%c",&ch);
	printf("%d\n",ch);
}
#endif



# if 0 
/*# ifndef A 
	#define A 203 */
main()

{
	printf("%d " ,A);
}
#endif

#if 0
void func(int a, int b);
main()
{
	int a = 2;
	int b = 3;
	func (a, b);
}
void func(register int a, register int b)
{
	printf("%d %d \n", a, b);
}

#endif
#if  0
void main()
{
	int a = 0;
	int b = 10;
	((a<b) && printf("b is bigger value is %d",b))||printf("a is bigger value is %d", a);
}
#endif
#include	<stdlib.h>
#include	<string.h>
#if 0
char *cstr = "UBIQUITIOUS";
char *str;
char *dstr;
void main()
{
	str = malloc (10);
	printf("0x%08x\n",str);
	str = "Gamut";
	printf("0x%08x\n",str);
	
	dstr = malloc(10);
	printf("0x%08x\n",dstr);
	strcpy(dstr,"oblation");
	printf("0x%08x\n,dstr");
	free(str);
	free(dstr);
}
#endif

#if 0

void main(void)
{
	int *aint[10];
	int i;
	for (i = 0 ; i < 10 ; i++) {

		aint[i] = malloc(sizeof(int));
	}
	for ( i = 0; i < 10 ; i++) {

		scanf("%d",aint[i]);
	}
	for ( i = 0; i < 10; i++)
		printf("%d----%p\n", *aint[i], aint[i]);
	

}
#endif

#if 0
void main()
{
	int i;
	char *cint[10];
	for ( i = 0 ; i < 10 ; i++)
		cint[i] = malloc(sizeof(char));
	for ( i = 0 ; i < 10 ; i++)
		scanf("%c",cint[i]);
	for ( i = 0 ; i < 10 ; i++)
		printf("%c --- %p----%p\n",*cint[i], cint[i],&cint[i]);

}
#endif

#if 0
void main()

{
	int i;
	char ch[] = "hello";
	for ( i = 0 ; i < 5; i++)
		printf("%c ---- %p \n", ch[i], &ch[i]);
	printf("%d",sizeof(char *));
	printf("\n0x%08x\n",ch[0]);
	printf("\n0x%08x\n",&ch[0]); 
	printf("\n%c\n",ch[1]); 
}
#endif

#if 0

void main()
{
	int a[2][3] = { 1,2,3,4,5,6};
	printf("%p----%p----%p----%d\n", &a, a, *a, **a);
	printf("%p----%p----%p----%d\n", &a+1, a+1, *a+1, *(*a+1));
}
#endif

#if 0
void main()
{
	char *s;
	int ch = 'i';
	s = strrchr("india",ch);
	printf("%s",s);
	printf("%d\n",strcspn("india","abc"));
}
#endif

#if 0
void main()
{
	char *p = NULL;
	p = (char *)malloc(sizeof(char)*5);
	strncpy(p,"india",5);
	*(p+5) = '\0';
	printf("%s\n",p);

}
#endif

#if 0

//#pragma pack(1)
struct stu
{
	char a;
	int b;

};
void main(void)
{
	struct stu c = { 'a', 8};

	printf("%d\n",sizeof(c));
	
	printf("0x%08x---\t---%p\n",&c.a , &c.b);

}
#endif

#if 0

struct stu1
{
	char a;
	int b;
};
struct stu2
{
	char a;
	int b;
};
void main(void)
{
	struct stu1 s1={'a',1};
	struct stu2 s2;
	s2.a = s1.a;
	printf("%d", s2.a);
}
#endif 

#if 0  
#include<stdio.h>

void india() __attribute__((constructor() ));
void usa() __attribute__((destructor()));
void india() 
{
printf("\nI am in india\n");
}

void usa()
{
printf("\nI am in usa\n");
}


int main(void)
{
	printf("\nI am in main\n");

    return 0;
}

/*void india(){
printf("\nI am in india\n");
}

void usa(){
printf("\nI am in usa\n");
}*/
#endif

#if 0 
#include<stdio.h>

int *call();
int main(){
	int *ptr;
	ptr=call();

//	fflush(stdin);
	printf("%d",*ptr);
	return 0;
}
	int * call(){

	static int x=25;
	++x;

	return &x;
}
#endif
#if 0
void main(void)
{
	char *p = "hello";

	printf("hai ");

	printf("mdb");
//	*p = "h";
	while ( *p++ != 'b'){
		printf("%c", *p);
	}
	printf("\n");

}
#endif

#if 0
struct {
	int a;
	struct *p;
	};
void main(void)
{
	struct AA;
}
#endif

#if 0

void sum ( int , int  );
int main ( void )
{

sum();
	
void sum ( void )
{
	int a = 1;
	int b = 1;
	int sum = a+b;
	printf ("sum: %d\n", sum );

}

return 0;

}

#endif

# if 0

#define my_sizeof(x) (char *)(&x+1)-(char*)&x
#define TYPE(type) typeof (type) newvar
int main()
{
    double YUY;
	TYPE(float);
    my_sizeof(typeof (char ) a));
    return 0;
}

#endif


# if 0

int main(void)

{
	int b;
	int c;
	int a = 10;
	b = sizeof(a);
	c = a;
	
	return 0;

}

#endif
#include <arpa/inet.h>
#if 1 
int main(void)
{
	unsigned char a[4] = {172,16,5,238};
	//unsigned char a[4] = {106,51,250,126};
	unsigned int ip = 0;
	memcpy(&ip,a,4);
	//ip = a[0] * (256*256*256 )+ a[1] * (256*256) + a[2] * (256) + a[3] ;
	ip = ntohl(ip);
	printf("%u \n", ip);
	unsigned char *ptr =(char *) &ip+3;
	//while (*ptr){
	//	printf ("%d",*ptr);
	///	ptr++;
	//	i++;
	//}
	printf ("%08X\n", ip);
	printf ("%d.", *ptr);
	ptr--;
	printf ("%d.", *ptr);
	ptr--;
	printf ("%d.", *ptr);
	ptr--;
	printf ("%d", *ptr);
	ptr--;
	printf ("\n");
	return 0;
}

#endif

#if 0
int main(void)

{
	unsigned  int a  = -10;
	printf("%u\n", a);

}
#endif

#if 0
struct n{

	int a:4;
	short int :0;
	char c;
	char d;
	};
int main(void)

{
	struct n val;
	printf("%d\n",sizeof(val));
	return 0;
}

# endif

#if 0
int main(void)
{
	typedef struct abc;
	return 0;
}
#endif

#if 0 
int main(void)
{
	(int);
		fi(1);
		auto void fi(int a) {
				printf("Enter\n");
		}
}

#endif
#if 0

int main ( void )
{

    char a[] = "Hello";
    char b[] = "go";

    strcat(a,b);       //Try for strcat(b,a); also
    printf("&a: %ua: %s\n",a, a );
    printf("&b: %ub: %s\n",b, b );

    strcat(a,b);       //Try for strcat(b,a); also
    printf("&a: %ua: %s\n",a, a );
    printf("&b: %ub: %s\n",b, b );
    return 0;

}


#endif
#if 0
int c;
int main ()
{
	//c = 10;
	int a[3] = {1,2,3};
	printf("%d\n",getpid());
	getchar();
	a[4] = 4;
//	printf("%s ",1);
}

#endif


#if 0 
#include	<stdio.h> 

int ptr(void); 
int main() 
{ 
	int *p = ptr(); 
	printf("%d\n", *p); 
	
} 

int ptr() 
{ 
	int i = 10; 
	return &i; 
}
#endif
#if 0
static int a = 300; 
static int b = 200; 
void func(void); 

int main() 
{ 
	func(); 
} 

void func() 
{ 
	static int a = 10; 
	static int b = 20; 
		
/*	printf ("function static\n");*/	
	printf ("Address a = %p\n", &a);
	printf ("Address b = %p\n", &b);
//	printf ("global static\n");	
	printf ("Address a = %p\n", (&b-3));
	printf ("Address b = %p\n", (&b-2));	
	printf ("A = %d\n", *(&b-3));
	printf ("B = %d\n", *(&b-2));
	
	return ; 
}

#endif 
