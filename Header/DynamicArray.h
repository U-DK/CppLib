//
// Created by ForeverDK on 10/8/21.
//

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H

#include <iostream>
using namespace std;

template<typename T>
class DynamicArray
{
public:
    DynamicArray();

    explicit DynamicArray(unsigned int i);

    ~DynamicArray();

    T& operator[](unsigned int i);

    T* Get(unsigned int i) const;

    unsigned int Size();

    unsigned int Capacity();

    void Add(const T& t);

    T* Remove(const T& t);

    void RemoveAt(unsigned int i);

    void Clear();

    void FormatPrint();

private:
    T* elements;
    unsigned int size;
    unsigned int capacity;

    void Resize();


};

template<typename T>
DynamicArray<T>::DynamicArray()
{
    elements = new T[1];
    elements[0] = T();
    size = 1;
    capacity = 1;
    cout<<"in constructor"<<endl;
}

template<typename T>
DynamicArray<T>::DynamicArray(unsigned int i)
{
    elements = new T[i];
    for (int j = 0; j < i; ++j)
    {
        elements[j] = T();
    }
    size = i;
    capacity = i;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] elements;
    elements = nullptr;
}

template<typename T>
T* DynamicArray<T>::Get(unsigned int i) const
{
    T* temp = nullptr;
    temp = &elements[i];
    return temp;
}

template<typename T>
T& DynamicArray<T>::operator[](unsigned int i)
{
    if(i>=size)
    {
        cerr<<"Index out of range"<<endl;
        throw exception();
    }
    return elements[i];
}

template<typename T>
unsigned int DynamicArray<T>::Size()
{
    return size;
}

template<typename T>
unsigned int DynamicArray<T>::Capacity()
{
    return capacity;
}

template<typename T>
void DynamicArray<T>::Add(const T& t)
{
    if (size >= capacity)
    {
        Resize();
    }
    elements[size] = t;
    ++size;
}

template<typename T>
void DynamicArray<T>::Resize()
{
    unsigned int newCapacity = capacity * 2;
    T* newElements = new T[newCapacity];
    for (int i = 0; i < size; ++i)
    {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

template<typename T>
T* DynamicArray<T>::Remove(const T& t)
{
    unsigned int index=0;
    T* temp= nullptr;
    for (int i = 0; i < size; ++i)
    {
        if(elements[i]==t)
        {
            index=i;
            temp=&elements[index];
            break;
        }
    }
    RemoveAt(index);
    return temp;
}

template<typename T>
void DynamicArray<T>::RemoveAt(unsigned int i)
{
    for (unsigned int j = i; j < size-1; ++j)
    {
        elements[j]=elements[j+1];
    }
    --size;
}

template<typename T>
void DynamicArray<T>::FormatPrint()
{
    if(size<=0)
    {
        cout<<"Error: There is no elements in data!"<<endl;
        return;
    }
    cout<<"size: "<<size<<", capacity: "<<capacity<<endl;
    for (int i = 0; i < size; ++i)
    {
        cout<<elements[i]<<", ";
    }
    cout<<endl;

}

template<typename T>
void DynamicArray<T>::Clear()
{
    delete[] elements;
    elements=new T[capacity];
    size=0;

}


#endif //DYNAMICARRAY_DYNAMICARRAY_H
