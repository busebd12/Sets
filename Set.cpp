#include "Set.h"

Set::Set()
{

}

Set::Set(vector<int> theSet)
{
    set=theSet;
}

void Set::add(int num)
{
    set.push_back(num);
}

vector<int> Set::getSet()
{
    return set;
}

void Set::contains(Set theSet, int num)
{
    //store the set in a temp
    vector<int> tempSet=theSet.getSet();

    cout << "Searching the set for " << num << "..." << endl;

    //loop through the set looking for the number
    for(auto number : tempSet)
    {
        if(number==num)
        {
            cout << "Found the number you were looking for -> " << num << endl;
        }
        else
        {
            cout << "Couldn't find the number you were searching for" << endl;
        }
    }
}

//creates the union set by adding numbers from both sets to the union
Set Set::Union(Set set1, Set set2)
{
    vector<int> tempSet1=set1.getSet();
    vector<int> tempSet2=set2.getSet();
    Set unionSet;

    for(auto number1 : tempSet1)
    {
        unionSet.add(number1);
    }  

    for(auto number2 : tempSet2)
    {
        unionSet.add(number2);
    }

    vector<int>Union=unionSet.getSet();
    cout << "The union of the two sets is:" << endl;
    for(auto integer : Union)
    {
        cout << integer << endl;
    }  

    return unionSet;
}

Set Set::Intersection(Set set1, Set set2)
{
    vector<int> tempSet1=set1.getSet();
    vector<int> tempSet2=set2.getSet();
    Set intersectionSet;

    for(auto num : tempSet1)
    {
        for(auto number : tempSet2)
        {
            //if the number appears in both vectors (Sets), then we want to add it to the intersection
            if(num==number)
            {
                intersectionSet.add(num);
            }
        }
    }

    vector<int> Intersection=intersectionSet.getSet();
    cout << "The intersection of the two sets is:" << endl;
    for(auto integer : Intersection)
    {
        cout << integer << endl;
    }
    return intersectionSet;
}

Set Set::Compliment(Set set1)
{
    //limiting the "rest of the integers" part of the complement definition to the numbers 1-20
    vector<int> restOfIntegers={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<int> tempSet=set1.getSet();
    Set compliment;

    //sort the set passed into the function
    sort(tempSet.begin(),tempSet.end());

    //goes through both the vector and the set, setting the values that match to zero
    for(auto itr1=restOfIntegers.begin();itr1!=restOfIntegers.end();++itr1)
    {
        for(auto itr2=tempSet.begin();itr2!=tempSet.end();++itr2)
        {
            //if the two numbers pointed to by the iterators are 0
            if(*itr1==*itr2)
            {
                *itr1=0;
                *itr2=0;
            }
        }
    }
    
    //combine the vector restOfIntegers with the sorted set passed into the function
    restOfIntegers.insert(restOfIntegers.end(),tempSet.begin(),tempSet.end());

    //sort the combined vector
    sort(restOfIntegers.begin(),restOfIntegers.end());

    //go through the complement set and remove all zeros
    for(auto number : restOfIntegers)
    {
        if(number==0)
        {
           //reomve the zero
           restOfIntegers.erase(remove(restOfIntegers.begin(),restOfIntegers.end(),0),restOfIntegers.end());
        }
    }

    cout << "The complement set is:" << endl;
    for(auto num : restOfIntegers)
    {
        cout << num << endl;
    }

    return compliment;
}

void Set::toString(Set aSet)
{
    vector<int> stringSet=aSet.getSet();

    cout << "The set written in words is:" << endl;
    
    //limit this set to 20 since we are only using random numbers between 1 and 20
    string numbers[] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty" };
                    
    for(auto num : stringSet)
    {
        if(num > 0 && num <=20)
        {
            cout << numbers[num] << endl;
        }
    }
}

void Set::printSet(Set set1)
{
    vector<int> temp=set1.getSet();

    cout << "The set contains:" << endl;
    for(auto num : temp)
    {
        cout << num << endl;
    }
}

