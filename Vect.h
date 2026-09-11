/*
   Filename: Vect.h
   Author:  Jingnan Xie
   Course: CSCI 362
   Description: An integer vector class with random access and dynamic resizing

*/

/*************************************************************/
//macro guard to prevent multiple inclusions
#ifndef VECT_H
#define VECT_H
#include <algorithm>
#include <cstdlib>
#include <iterator>

/*************************************************************/

class Vect{

 
//member variables  
private:
    int* m_vect; //the array holding the vector   
    unsigned m_size; // size of the current vector
    unsigned m_capacity; //the max capacity of the vector

public:
    //some standard container type aliases
    //iterators in this class are just integer pointers
    using iterator = int*; //


    //const_interators are read-only iterators
    using const_iterator = const int*;

    //constructors
    //default constructor
    //member initializer list
    //similar to std::vector<int> v1;
    Vect(): m_size(0), m_capacity(0), m_vect(nullptr) {

    }

    //A constructor for vectors with initial size
    //similar to std::vector<int> v1(5);
    Vect(unsigned size): m_size(size), m_capacity(size), m_vect(new int[size]){
       
    }

    //A constructor for vectors with initial size and value
    //similar to std::vector<int> v1(3,5);
    Vect(unsigned size, const int& value): m_size(size), m_capacity(size), m_vect(new int[size]){
        std::fill(this->begin(), this->end(), value);
    }

    // Range ctor.
    // Initialize an Array from the range [first, last).
    // "first" and "last" must be Array iterators or pointers
    //   into a primitive array.
    Vect (const_iterator first, const_iterator last)
        : m_size (std::distance (first, last))
        , m_capacity (m_size)
        , m_vect (m_size == 0 ? nullptr : new int[m_capacity])
    // remember to use a member initializer list!
    {
      std::copy (first, last, this->begin ());
    }


    // Copy ctor.
    // Initialize this object from "a".
    Vect (const Vect& a){
        //use copy algorithm
        //leave for readers
    }
    

    //destructor
    // Release allocated memory. How?
    ~Vect(){
        //delete the array m_vect
        //leave for readers
    }

    iterator begin(){
        return ;  //array name is also a pointer's name pointing to the first element of the array
    }

    iterator end(){
        return ;
    }

    const_iterator begin() const{
        return ;
    }

    const_iterator end() const{
        return ;
    }








    //member functions
    //size-related member functiosn
    //return size of the vector
    //nums.size()
    unsigned size() const{
        return m_size;
    }

    //test empty
    bool empty() const{
        //leave it to the readers
        return true;
    }

    //return capacity of a vector
    unsigned capacity() const{
        return m_capacity;
    }

    //reserve capacity for "space" elements
    //v1.reserve(30);  this means the vector v1's capacity is at least 30
    //size must reamin unchanged
    void reserve(unsigned space){
        if(space > capacity()){

            //create a new array of size space
            //std::copy the current vector to the new array
            //delete m_vect
            //reset m_vect = new array
            //reset m_capacity

        }

    }

    //resize m_size to be "newSize"
    //if newSize < m_size, delete the extra elements
    //if newSize > m_size, insert elements with "value" at the end
    void resize(unsigned newSize, const int& value){
        if(m_size < newSize){

            //reserve certain amount of space
            //use algorithm fill  OR  fill_n 

        }

        //reset m_size
    }

    //operators member functions
    //swap(int a, int b)  vs  swap(int&a , int& b)
    //v1[2] = 10;
    //v1[2] = 20;
    int& operator[](unsigned index){
        //return one line of code. Hint: you can use array m_vect
    }


    //std::vector<int> v2 = v1;
    Vect& operator=(const Vect& a){
        //the key word this. In C++, this is a pointer, pointing to the Vect (object)
        //this stores address
        if( &a != this ){  
            //reserve some capacity
            //std::copy a to begin()
            //reset m_size

        }

    }

    //insert and delete member functions
    //delete the last element
    void pop_back(){

        //delete last element  
    }

    //insert value at the end
    void push_back(const int& value){

        if(size() == capacity()){
            if(m_size == 0)  reserve(1);
            else  //double the size

        }

        //to insert element, you can use [], i.e.  m_vect[index] = the one you want to insert
        //reset m_size
    }

    //erase element at "pos" and return an iterator pointing to the next element
    //   1   2   3   4   5   6    we should return a pointer pointing to 4
    //        pos^
    iterator erase(iterator pos){

        //std::copy range to an iterator
        //reset m_size
        //return the iterator

    }

    //isert "item" before "pos" and return an iterator pointing to "item"
    // 1   2   3   4   5   6   7 
    //         ^
    //1    2  10   3   4   5   6   7
    //         ^    
    iterator insert(iterator pos, const int& item){
        if(size() == capacity()){
            //reserve will invalidate the pos iterator
            //so store the index of pos, using distance
            if(m_size == 0)  reserve(1);
            else  //double the size
            //rebuild pos here  pos = something + index    
        }

        //std::copy_backward(range_first, range_last,  find the new end)

        // ? = item find the postition 

        //reset m_size

        //return the iterator pointing to item

    }
    
};
#endif