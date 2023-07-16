#ifndef ARRAY_ADT
#define ARRAY_ADT

#include <iostream> 

using namespace std;

class Array{
    int size;
    int current_length;
    int *array;

    public:
        Array(int size);

        void add(int);
        void insert(int,int);
        void deleteElement(int);
        void search(int);
        void get(int);
        void set(int,int);
        int max();
        void reverse();
        void rotate();
};

#endif