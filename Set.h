#ifndef SET_H
#define SET_H
#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Set
{
    private:
        vector<int> set;

    public:
        Set();
        Set(vector<int> theSet);
        void add(int num);
        vector<int> getSet();
        void contains(Set theSet, int num);
        static Set Union(Set set1, Set set2);
        static Set Intersection(Set set1, Set set2);
        static Set Compliment(Set set1);
        void toString(Set mySet);
        void printSet(Set set1);
};


#endif

