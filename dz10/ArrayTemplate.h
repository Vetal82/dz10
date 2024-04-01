
#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// fill the array with random numbers from 1 to 10
template <typename T>
void randArray(T arr[], int size, int a = 1, int b = 10) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (b - a + 1) + a;
    }
}

// print the array in the console
template <typename T>
void printArray(T arr[], int size, int w_cout = 5) {
    for (int i = 0; i < size; i++) {
        cout.width(w_cout);
        cout << arr[i];
    }
    cout << endl;
}

//знаходження індексу максимального елемента масиву
template <typename T>
int indexMaxElement(T arr[], int size)
{
    T max_elem = arr[0];
    int i_max = 0;
    for (int i = 0; i < size; i++) {
        if (max_elem < arr[i]) {
            max_elem = arr[i];
            i_max = i;
        }
    }
    return i_max;

}

//знаходження індексу мінімального елемента масиву
template <typename T>
int indexMinElement(T arr[], int size)
{
    T min_elem = arr[0];
    int i_min = 0;
    for (int i = 0; i < size; i++) {
        if (min_elem > arr[i]) {
            min_elem = arr[i];
            i_min = i;
        }
    }
    return i_min;
}

float addFractions(float a, float b) {
    return a + b;
}
float addFractions(int a1, int b1, int a2, int b2) {
    return (float)a1 / b1 + (float)a2 / b2;
}
//Додавання нового елементу масиву
template <typename T>
void addItemtoBack(T*& arr, int& size, int item)
{
    // 1. Створюємо нову память на +1 ел-т більше
    T* tmp = new T[size + 1];

    //2. Переносимо дані зі старого масиву до нового
    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }

    //3.Вносимо нове значення в остатню клітинку
    tmp[size] = item;

    //4.Звільнити стару пам'ять
    if (arr != nullptr) delete[] arr;

    //5.Перепрев'зуємо вказівник в нову пам'ять
    arr = tmp;

    //6 .Оновлюємо розмірність масиву

    size++;

}
//Кіл-ть ул-тів по критерію
template <typename T>
int my_count_if(T* arr, int size, bool (*fP)(T)) {
    int amount = 0;
    for (int i = 0; i < size; i++)
    {
        if (fP(arr[i]) == true) {
            amount++;
        }
    }
    return amount;
}

template <typename T>
T my_sum_if(T* arr, int size, bool (*fp)(T)) {
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (fp(arr[i]) == true){
            sum += arr[i];

        }
    }
    return sum;
}

template <typename T>
T my_find_if(T* arr, int size, bool (*fp)(T)) {
    T find = 0;
    for (int i = 0; i < size; i++)
    {
        if (fp(arr[i]) == true) {
            return i;

        }
    }
    return -1;

}
template <typename T>
 void my_remove_if(T* &arr, int &size, bool (*fp)(T)) {
    int amount = my_count_if(arr, size, fp);
    int new_size = size - amount;
    T* tmp = new T[new_size];
    for (int i = 0, j = 0; i < size; i++) {
        if (fp(arr[i]) == false) {
            tmp [j] = arr[i];
            j++;
        }
    }
    if (arr != nullptr)
        delete[]arr;
    arr = tmp;
    size = new_size;
}
 template <typename T>
 void my_replace_if(T*& arr, int& size, bool (*fp)(int), T value) {
     for (int i = 0; i < size; i++)
     {
         if (fp(arr[i]) == true) {
             arr[i] = value;
         }
     }
 }
 template <typename T>
 void my_copy_if(T* arr, int size, T*& arr_copy, int& size_copy, bool (*fp)(T))
 {
     size_copy = my_count_if(arr, size, fp);
     arr_copy = new T[size_copy];
     for (int i = 0, j = 0; i < size; i++)
     {
         if (fp(arr[i]))
         {
             arr_copy[j++] = arr[i];
         }
     }

 }
 template <typename T>
 void sort(T* arr, int size, bool (*cmp)(T, T)) {
     for (int i = 0; i < size - 1; ++i) {
         for (int j = 0; j < size - i - 1; ++j) {
             if (!cmp(arr[j], arr[j + 1])) {
                 T temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = temp;
             }
         }
     }
 }
 template<typename T>
 int findLast_if(T* arr, int size, bool (*fP)(T)) {
     for (int i = size - 1; i >= 0; --i) {
         if (fP(arr[i])) {
             return i;
         }
     }
     return -1;
 }
