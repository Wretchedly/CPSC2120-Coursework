/*
 * Name: Chris Caldwell
 * Date Submitted:
 * Lab Section: 003
 * Assignment Name: Lab 4 - Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target){
    for(int i = 0; i < data.size(); i++){
        if(target == data.at(i)) return i;
    }
    return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){
    return -1;
}
