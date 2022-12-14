union a{
        char  b;
        struct bit {
            char b0:1;
            char b1:1;
            char b2:1;
            char b3:1;
            char b4:1;
            char b5:1;
            char b6:1;
            char b7:1;
    	}aa;
}hello;

int main(void){
	hello.aa.b0 = 1;
	hello.aa.b1 = 0;
	hello.aa.b2 = 1;
	hello.aa.b3 = 0;
	hello.aa.b4 = 0;
	hello.aa.b5 = 1;
	hello.aa.b6 = 1;
	hello.aa.b7 = 0;

	printf ("%02x\n", hello.b);
	return 0;
}
