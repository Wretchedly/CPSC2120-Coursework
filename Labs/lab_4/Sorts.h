/*
 * Name: Chris Caldwell
 * Date Submitted:
 * Lab Section: 003
 * Assignment Name: Lab 4 - Searching and Sorting
 */
#pragma once

#include <vector>
#include <cstdlib> //cstdlib & time to generate random index in quickSort();
#include <time.h>
#include <iostream>

//helper function to swap elements
template <class T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

//helper function to return sub-vectors
template <class T>
std::vector<T> subVector(std::vector<T> lst, int lowBound, int highBound){
    std::vector<T> subLst((highBound - lowBound) + 1);

    if(lowBound == 0){
        copy(lst.begin(), lst.begin() + highBound + 1, subLst.begin());
    } else {
        copy(lst.begin() + lowBound, lst.begin() + highBound + 1, subLst.begin());
    }

    return subLst;
}

//Helper function to concatenate vectors
template <class T>
std::vector<T> concat(std::vector<T> lstA, std::vector<T> lstB){
    lstA.insert(lstA.end(), lstB.begin(), lstB.end());

    return lstA;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    std::vector<T> subLstA, subLstB, temp;
    T pivotVal, curVal;
    int pivotI, i;

    //base case: lst has one value
    if(lst.size() == 1) return lst;

    //seed and create random number between 0 and (size-1)
    srand(time(NULL));
    pivotI = rand() % lst.size();

    pivotVal = lst[pivotI];
    swap(lst[pivotI], lst[0]);
    pivotI = 0;

    //iterate through the vector
    for(i = 1; i < lst.size(); i++){
        curVal = lst[i];
        //increment pivot index, and swap current val with val at pivot index
        //if less than that val
        if(curVal <= lst[pivotI]) swap(lst[i], lst[++pivotI]);
        
    }

    //move pivot value to pivot index
    swap(lst[0], lst[pivotI]);

    temp.push_back(lst[pivotI]);
    
    if(pivotI == 0){
        return concat(temp, quickSort(subVector(lst, pivotI + 1, lst.size() - 1)));
    } else if(pivotI == lst.size() - 1){
        return concat(quickSort(subVector(lst, 0, pivotI - 1)), temp);
    }

    subLstA = subVector(lst, 0, pivotI - 1);
    subLstB = subVector(lst, pivotI + 1, lst.size() - 1);
    
    return concat(concat(quickSort(subLstA), temp), quickSort(subLstB));
}