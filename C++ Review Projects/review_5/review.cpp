#include "review.h"

#include <vector>

using namespace std;

vector<int> InitializeArray(int size){
    int i;
    vector<int> vect;
    
    for(i = 0; i < size; i++){
        vect.push_back(0);
    }
    
    return vect;
}