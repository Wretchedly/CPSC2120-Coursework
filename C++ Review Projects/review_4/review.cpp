#include "review.h"

#include <iostream>
#include <vector>

using namespace std;

void ReadWrite(){
    int i;
    string input = " ";
    bool run = true;
    vector<string> elements;
    
    while(run){
        cin>>input;
        
        if(input != "q"){
            elements.push_back(input);
        } else {
            for(i = 0; i < elements.size(); i++){
                cout<<elements[i]<<" ";
            }
            cout<<"\n";
            run = false;
        }
    }
}