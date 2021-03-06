/*
 * Name: Chris Caldwell
 * Date Submitted: 2/2/22
 * Lab Section: 003
 * Assignment Name: Lab1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
    start = nullptr;
    mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    Node<T>* iterator = start;
    
    while(start != nullptr){
        iterator = start;
        start = start->next;
        delete iterator;
    }
}

//Return the size of this list
template <class T>
int List<T>::size(){
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if(start == nullptr){
        return true;
    }
    
    return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
    Node<T>* inNode = new Node<T>(value);
    inNode->next = start;
    start = inNode;
    
    mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
    Node<T>* inNode = new Node<T>(value);
    Node<T>* lastNode = start;
    
    inNode->next = nullptr;
    
    //if there are no other nodes, point to inserted node
    if(start == nullptr){
        start = inNode;
        mySize++;
    } else {
        //find last node
        while(lastNode->next != nullptr){
            lastNode = lastNode->next;
        }
    
        //have the last node point to the inserted node
        lastNode->next = inNode;
    
        mySize++;
    }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
    Node<T>* inNode = new Node<T>(value);
    Node<T>* tempNode = start;
    
    if(j == 0){
        inNode->next = start;
        start = inNode;
        mySize++;
    } else {
        for(int i = 0; i < j-1; i++){
            if(tempNode != nullptr){
                tempNode = tempNode->next;
            }
        }
        
        if(tempNode != nullptr){
            inNode->next = tempNode->next;
            tempNode->next = inNode;
            mySize++;
        }
    }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
    Node<T>* tempNode = start;
    
    if(start == nullptr){
        return;
    }
    
    start = start->next;
    
    delete tempNode;
    
    mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
    if(start == nullptr){
        return;
    }
    //remove first node if only node
    if(start->next == nullptr){
        start = nullptr;
        mySize--;
    } else {
        Node<T>* iterator = start;
        
        //find second-to-last node
        while(iterator->next->next != nullptr){
            iterator = iterator->next;
        }
        
        Node<T>* lastNode = iterator->next;
    
        iterator->next = nullptr;
        
        delete lastNode;
        mySize--;
    }
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
    
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
    if(start == nullptr){
        return T();
    }
    
    return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
    Node<T>* iterator = start;
    
    if(start == nullptr){
        return T();
    }
    
    while(iterator->next != nullptr){
        iterator = iterator->next;
    }
    
    return iterator->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
    Node<T>* iterator = start;
    
    if(start == nullptr){
        return T();
    }
    
    for(int i = 0; i < j-1; i++){
        iterator = iterator->next;
    }
    
    return iterator->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
    Node<T>* iterator = start;
    int pos;
    
    if(iterator == nullptr){
        return -1;
    } else {
        while(iterator != nullptr){
            if(iterator->value == key){
                return pos;
            }
            
            iterator = iterator->next;
            pos++;
        }
    }
    
    return -1;
}
