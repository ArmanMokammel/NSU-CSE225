#include "dynarr.h"
#include <iostream>

using namespace std;

template <class T>
dynArr <T>::dynArr()
{
    data = NULL;
    size = 0;
}

template <class T>
dynArr <T>::dynArr(int s)
{
    data = new T[s];
    size = s;
}

template <class T>
dynArr <T>::~dynArr()
{
    delete [] data;
}

template <class T>
T dynArr <T>::getValue(int index)
{
    return data[index];
}

template <class T>
void dynArr <T>::setValue(int index, T value)
{
    data[index] = value;
}

template <class T>
void dynArr <T>::allocate(int s)
{
    T *temp = new T[5+s];
    for(int i = 0; i < 5; i++)
    {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
}
