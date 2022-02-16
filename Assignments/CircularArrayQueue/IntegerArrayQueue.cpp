#include "IntegerArrayQueue.h"

using namespace std;

bool IntegerArrayQueue::enqueue(int value){
    if(back < size){
        array[back] = value;
        return true;
    }

    return false;
}

int IntegerArrayQueue::dequeue(){
    if(size != 0){
        
        return array[front];
    }

    return 0;
}