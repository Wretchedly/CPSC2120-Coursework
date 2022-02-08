#include "review.h"

#include <iostream>

using namespace std;

void ReadStdIn2(){
    int items = -1;
    string input = " ";
    bool run = true;
    
    while(run){
        if(input != "q"){
            cin>>input;
            items++;
        } else {
            run = false;
        }
    }
    
    cout<<items;
}