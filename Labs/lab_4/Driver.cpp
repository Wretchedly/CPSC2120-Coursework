//For test purposes only, not submitting
#include "Searches.h"
#include "iostream"

using namespace std;

int main(){
    vector<int> intVec = {8, 6, 7, 5, 3, 0, 9};
    vector<char> charVec = {'H', 'e', 'l', 'l', 'o', '!'};

    cout<<"linearSearch(intVec, 5) = "<<linearSearch(intVec, 5);
    cout<<"\nlinearSearch(intVec, -2) = "<<linearSearch(intVec, -2);
    cout<<"\nlinearSearch(charVec, e) = "<<linearSearch(charVec, 'e');
    cout<<"\nlinearSearch(charVec, B) = "<<linearSearch(charVec, 'B');

    return 0;
}