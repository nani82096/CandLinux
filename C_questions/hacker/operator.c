#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float meal_cost;
    int tip_per;
    int tax_per;
    scanf ("%f", &meal_cost);
    scanf ("%d", &tip_per);
    scanf ("%d", &tax_per);
    float tip = meal_cost * ((float)tip_per/100);
    float tax = meal_cost * ((float)tax_per/100);
    meal_cost = meal_cost + tip + tax;
    printf ("The total meal cost is %d dollars.\n", (int)round(meal_cost));
    
    return 0;
}
