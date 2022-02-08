#include "review.h"

int Fibonacci(int a){
    if(a == 0 || a == 1){
        return 1;
    } else {
        return Fibonacci(a - 1) + Fibonacci(a - 2);
    }
    
    return 0;
}