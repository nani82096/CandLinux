#include	"hdr1.h"

void main(void)

{
	printf("\n\nWill set the bits from pos1 to pos2 in a number\n\n");
	int num1;
	int pos1;
	int i;
	int num2;
	int pos2;
	int choice;
	printf("\n\nEnter 1 to find max and min\nEnter 2 to clear rightm ost bit\nEnter 3 to Set bits from pos1 to pos2\nEnter 4 to toggle bits from pos1 to pos2\n\n");
	choice = integervalidation();
	switch (choice) {
		case 1:
			printf("\n\nEnter the number1 \n\n");
            num1 = integervalidation();
            printf("\n\nThe number in binary representation \n\n");
            show_bits(num1);
            printf("\n\nEnter the number2\n\n");
			num2 = integervalidation();
            printf("\n\nThe number in binary representation \n\n");			
            show_bits(num2);
            printf("\n\nMaximum number in above two is \n\n");
			show_bits(FINDINGMAX(num1, num2));
			printf("\n\nMinimum of number is \n\n");
			show_bits(FINDINGMIN(num1, num2));
			break;
		case 2:
			printf("\n\nEnter the number \n\n");
		    num1 = integervalidation();
			printf("\n\nThe number in binary representation \n\n");
			show_bits(num1);
			CLEARRIGHTMOST(num1);
			printf("\n\nClearing the right most set bit\n\n");
			show_bits(num1);
			break;
		case 3:
			printf("\n\nEnter the number \n\n");
			num1 = integervalidation();
			printf("\n\nEnter the position 1\n\n");
			pos1 = integervalidation();
			printf("\n\nEnter the position 2\n\n");
			pos2 = integervalidation();

			printf("\n\nThe number in binary representation \n\n");
			show_bits(num1);
			if ( pos1 > 31 || pos2 > 31)
				printf("\n\nNot valid\n\n");
			else {
				num1 = SET(num1, pos1, pos2);
				printf("\n\nAfter setting from pos1 to pos2 binary representation is \n\n");	
				show_bits(num1);
			}
			break;
		case 4:

			printf("\n\nEnter the number \n\n");
            num1 = integervalidation();
            printf("\n\nEnter the position 1\n\n");
            pos1 = integervalidation();
            printf("\n\nEnter the position 2\n\n");
            pos2 = integervalidation();

            printf("\n\nThe number in binary representation \n\n");
            show_bits(num1);
            if ( pos1 > 31 || pos2 > 31)
                printf("\n\nNot valid\n\n");
            else {

				num1 = TOGGLE(num1, pos1, pos2);
		        printf("\n\nAfter Toggline from pos1 to pos2 binary representation is \n\n");    
        	show_bits(num1);
			}
			break;
		default:
			printf("\nEnter 1 to 4 only\n");
	}
}
