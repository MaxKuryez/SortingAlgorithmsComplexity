#include "Algoritms.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;


void HeapSort(int *ptr, int num)
{
for (int i = 0; i < num; i++){
        HeapInsert(ptr,i);
}

for (int i = 0; i < num; i++){
            HeapDelete(ptr,num-i);
}
}

void HeapDelete(int *ptr, int num){
swap(ptr[0], ptr[num - 1]);
int child = 0;
int par = 0;
while (num > 2 ){
    child = 2 * par + 1;
    if (2*par + 2 < num && ptr[2*par + 1] < ptr[2 * par + 2] && num > 3)
        child = 2 * par + 2;
    if ( 2 * par + 1 < num - 1 ){
    if (ptr[par] < ptr[child] && child < num - 1){
        swap(ptr[par], ptr[child]);
    } else break;
    } else break;
    par = child;
}
}


void HeapInsert(int *ptr, int num){

int par = num;
while (par > 0){
    par = (num-1)/2;
    if (ptr[par] < ptr[num])
        swap(ptr[par], ptr[num]);
    num = par;
}
}

void MergeSort(int* ptr, int num)
{
    MergeSortHelper( ptr, 0, num - 1);
}

void MergeSortHelper( int* ptr,int left,int right)
{
    if (right - left > 1)
    {
        MergeSortHelper(ptr, left, (right - left)/2 + left );  ///changed from (right - left)/2 to (right - left)/2 + left
        MergeSortHelper(ptr, (right - left)/2 +1  +left, right);
    }

    int * Buff = new int[right - left + 1];
    int i = 0; ///counter for buffer


    int * ptr2 = ptr +  (right - left)/2 + 1 +left;   /// dividing an array into 2 parts which are already sort it in order to merge them
    int * ptr1 = ptr + left;

     /*int a = left;
     for ( int j =0; j < right - left +1; j++){
            std::cout<<ptr[a]<<" ";                   //this thing is for checking the steps of array division
            a++;
     }
     std::cout<<std::endl;*/

    if ( right != left)                ///if the part is bigger than 1 element
    {
        while ( ptr1 != ptr + (right - left)/2 + left +1 && ptr2 != ptr + right + 1)  /// until any of pointers points at the last element
        {                                                                       /// of that smaller part which is sorted
            if  ((*ptr1) > (*ptr2))
            {
                Buff[i] = (*ptr2);      ///put in the buffer array and increment it's counter
                ptr2 += 1;
                i++;
            }
            else
            {
                Buff[i] = (*ptr1);
                ptr1 += 1;
                i++;
            }

        }
       int* _ptr1 = ptr1;
       int* _ptr2 = ptr2;
       if (ptr1 == ptr + (right - left)/2 + left +1){   /// the case of left part being finished first
        for (int j = 0; j < ptr +  right - ptr2 +1; j++){
            Buff[i] = (*_ptr2);
            _ptr2++;
            i++;
        }
       }
       if (ptr2 == ptr + right + 1){    /// case of the right part being finished first
        for (int j = 0; j < ptr +( right - left)/2 + 1 +left - ptr1; j++){
            Buff[i] = (*_ptr1);
            _ptr1++;
            i++;
        }
       }
      for ( int j = 0; j < i; j++){
            ptr[left + j] =   Buff[j];
      }
    }
    delete Buff;
}

void QuickSort(int *ptr, int num)
{
int pivot = ptr[0];
int left  = 1;
int right = 1;
while ( right < num ){
 if ( ptr[right] < pivot ){
    swap (ptr[right], ptr[left]);
    left++;
 }
  right++;
}
swap(ptr[0], ptr[left - 1] );
if ( num - left > 1)
    QuickSort(ptr + left, num - left);
if ( left > 1 && ptr[0] != ptr[left - 1])
      QuickSort(ptr , left);

}
