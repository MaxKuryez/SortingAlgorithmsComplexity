#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <random>
#include "Algoritms.h"
#include <fstream>

using namespace std;

int main()
{

LARGE_INTEGER seed;
QueryPerformanceCounter(&seed);
std::mt19937 gen(seed.QuadPart);

ofstream fin("C:\\Users\\admin\\Desktop\\DATA.txt");

double freq = 0.0;
    LARGE_INTEGER x;
    QueryPerformanceFrequency(&x);
    freq = x.QuadPart/1000.0;

    int times = 1000;

    for (std::size_t size : {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000}) {// 10000000}) {
        std::uniform_int_distribution<> dis(-2*size, 2*size);

        std::int64_t sum(0);
        std::int64_t sum1(0);
        std::int64_t sum2(0);

        int *arr = new int[size];
        int *arr1 = new int[size];
        int *arr2 = new int[size];

        for (int j = 0 ; j < times ; j++) {


            for (int i = 0; i < size; i++) {
                arr[i] = dis(gen);
                arr1[i] = arr[i];
                arr2[i] = arr[i];
            }



            QueryPerformanceCounter(&x);
            std::int64_t start = x.QuadPart;

            QuickSort(arr,size);

            QueryPerformanceCounter(&x);
            std::int64_t end = x.QuadPart;

            std::int64_t taken = end - start;
            sum += taken;

            ///

             QueryPerformanceCounter(&x);
            start = x.QuadPart;

            MergeSort(arr,size);

            QueryPerformanceCounter(&x);
            end = x.QuadPart;

            taken = end - start;
            sum1 += taken;

            ///

            QueryPerformanceCounter(&x);
            start = x.QuadPart;

            HeapSort(arr,size);

            QueryPerformanceCounter(&x);
            end = x.QuadPart;

            taken = end - start;
            sum2 += taken;

        }
        fin <<"QuickSort: "<< std::setw(8) << std::fixed << size << " " << " " << sum / freq / times << std::endl;
        fin<<"MergeSort: "<< std::setw(8) << std::fixed << size << " " << " " << sum1 / freq / times << std::endl;
        fin <<"HeapSort: "<< std::setw(8) << std::fixed << size << " " << " " << sum2 / freq / times << std::endl;
        fin<<endl;
        delete arr;
        delete arr1;
        delete arr2;
    }


}



//MergeSort(Arr, n);
//HeapSort(Arr, n);




