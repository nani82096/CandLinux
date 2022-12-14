#include    "head.h"

void swap_links(NODE **head_ref, int x, int y)

{
   // Nothing to do if x and y are same
   if (x == y) return;
 
   // Search for x (keep track of prevX and CurrX
   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->link;
   }
 
   // Search for y (keep track of prevY and CurrY
   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->link;
   }
 
   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->link = currY;
   else // Else make y as new head
       *head_ref = currY; 
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->link = currX;
   else  // Else make x as new head
       *head_ref = currX;
 
   // Swap link pointers
   struct node *temp = currY->link;
   currY->link = currX->link;
   currX->link  = temp;
}
