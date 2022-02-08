#include "review.h"

#include <iostream>

using namespace std;

int WriteOut(std::string output){
    cout<<output;
    
    return 1;
}

int WriteOut(int output){
    cout<<output;
    
    return 2;
}

int WriteOut(double output){
    cout<<output;
    
    return 3;
}