
#include	<stdio.h>
void main(void)
{
	

union A {
    union S {
        int a;
        char b;
    };
    union T {
        union U {
            double c;
            double d;
        } watch1;
        struct V {
            int e;
            struct W {
                char f;
                double g;
            }watch2;
        }
    };
}s14;

	printf("%d\n",sizeof (s14));
	/*printf("%p\n", & ss.see.a);
	printf("%p\n", & ss.see.b);
	printf("%p\n", & ss.a);
	printf("%p\n", & ss.b);*/
}
