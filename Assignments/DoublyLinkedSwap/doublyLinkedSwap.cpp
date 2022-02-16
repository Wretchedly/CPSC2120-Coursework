/**********************************************************
 * Name: Chris Caldwell
 * Date Submitted: 2/15/22
 * Assignment Name: Swapping Nodes in a Doubly Linked List
 *********************************************************/
#include "doublyLinkedSwap.h"

void swapWithNext(Node * p){
    if(p->next == nullptr || p->next->next == nullptr) return;
    //Unsure of how to describe this...
    //Have the two "outer" nodes "latch" onto p and p after
    p->prev->next = p->next;
    p->next->next->prev = p;
    //have p after's prev point to p's prev
    p->next->prev = p->prev;
    //have p's next point to p after's next
    p->next = p->next->next;
    //finally, have p and p after point to each other
    p->prev->next->next = p;
    p->prev = p->prev->next;
}

int main(){
    int array[] = {2, 3, 5, 7, 11, 13, 17, 19};;
    Node* list = arrayToList(array, 8);
    printForwards(list);
    printBackwards(getTail(list));
    swapWithNext(getNode(list, 7));
    printForwards(list);
    printBackwards(getTail(list));

    return 0;
}