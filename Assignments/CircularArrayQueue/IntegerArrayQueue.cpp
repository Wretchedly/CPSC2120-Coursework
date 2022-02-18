/***************************************************************
 * Name: Chris Caldwell
 * Date Submitted: 2/15/22
 * Assignment Name: Queue Implementation Using a Circular Array
 **************************************************************/
#include "IntegerArrayQueue.h"
#include <iostream>

using namespace std;
bool first = true;

bool IntegerArrayQueue::enqueue(int value){
    //if first element, put back behind front
    if(first){
        back = -1;
        first = false;
    }

    //check if full
    if(back == front - 2 || front == 0 && back == size - 1) return false;
    
    back = (back + 1) % size;
    array[back] = value;

    return true;
}

int IntegerArrayQueue::dequeue(){
    int dequeued = array[front];

    //check if not empty
    if((back + 1) % size != front || first != 0 && back != size - 1){
        array[front] = 0;
        front = (front + 1) % size;
        return dequeued;
    }

    first = true;

    return 0;
}