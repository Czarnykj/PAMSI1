/*****************
 * Konrad Czarny *
 * 235778        *
 * PAMSI 1       *
 * ***************/
#include "algorithms.h"

/***********************
 *      QUICK SORT     *
 ***********************/

template<typename T>
void quickSort(T *tab,int leftPointer, int rightPointer)
{
    if(leftPointer < rightPointer)
    {
        int partitionPointer = partition(tab,leftPointer,rightPointer);

        quickSort(tab,leftPointer,partitionPointer);
        quickSort(tab,partitionPointer+1,rightPointer);
    }
}

template<typename T>
int partition(T *tab,int leftPointer,int rightPointer)
{
    int pivot =tab[(leftPointer+rightPointer)/2];

    while(true)
    {
        while(tab[rightPointer] > pivot) rightPointer--;
        while(tab[leftPointer] < pivot) leftPointer++;
        if(leftPointer < rightPointer) std::swap(tab[leftPointer++],tab[rightPointer--]);
        else return rightPointer;
    }
}
/***********************
 *      MERGE SORT     *
 ***********************/
template<typename T>
void merge(T *tab,int leftPointer,int middlePointer,int rightPointer)
{
    int leftSize = middlePointer - leftPointer + 1;
    int rightSize = rightPointer - middlePointer;
    T* leftTab = new T[leftSize];
    T* rightTab = new T[rightSize];
    int left = 0, right  = 0,k;

    for(left = 0; left < leftSize;left++)
        leftTab[left] = tab[leftPointer+left];
    for(right = 0; right < rightSize;right++)
        rightTab[right] = tab[middlePointer+1+right];
    left = 0; right = 0;
    for(k = leftPointer;left < leftSize && right < rightSize;k++)
    {
        if(leftTab[left] <= rightTab[right])
        {
            tab[k] = leftTab[left];
            left++;
        }
        else
        {
            tab[k] = rightTab[right];
            right++;
        }
    }
    for(;left < leftSize;k++)
    {
        tab[k] = leftTab[left];
        left++;
    }

    for(;right<rightSize;k++)
    {
        tab[k] = rightTab[right];
        right++;
    }

    delete[] leftTab;
    delete[] rightTab;
}
template<typename T>
void mergeSort(T *tab,int leftPointer,int rightPointer)
{
    if(leftPointer >= rightPointer) return;
    int middlePointer = (leftPointer+rightPointer)/2;
    mergeSort(tab,leftPointer,middlePointer);
    mergeSort(tab,middlePointer+1,rightPointer);

    merge(tab,leftPointer,middlePointer,rightPointer);
}

/***********************
 *      INTRO SORT     *
 ***********************/
template<typename T>
void insertionSort(T *tab,int left,int right)
{

    for (int i = left+1; i <= right; i++)
    {
        int key = tab[i];
        int j = i;

        while (j > left && tab[j-1] > key)
        {
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = key;
    }
}

template<typename T>
void introSortMain(T *tab,T *begin, T *end,int depth)
{
    int size = end - begin;

    if (size < 16)
    {
        insertionSort(tab, begin-tab, end-tab);
        return;
    }

    if (depth == 0)
    {
        std::make_heap(begin, end+1);
        std::sort_heap(begin, end+1);
        return;
    }

    int pivot = partition(tab,begin-tab,end-tab);
    introSortMain(tab,begin,tab+pivot,depth-1);
    introSortMain(tab,tab+pivot+1,end,depth-1);

}
template<typename T>
void introSort(T *tab,int *begin, int *end)
{
    int depth = 2 * log(end-begin);

    introSortMain(tab, begin, end, depth);
}

template<typename T>
void printTab(T *tab,int size)
{
    for(int i = 0; i < size; i++)
    {
        if(i%10) std::cout << "\t";
        else std::cout << "\n";
        std::cout << tab[i];
    }
}
template<typename T>
void loadTab(T *tab,int size, int range)
{
    for(int i = 0; i < size; i++) tab[i] = rand()%range+1;
}
template<typename T>
void isSorted(T *tab,int size)
{
    for(int i = 0; i < size-1;i++)
    {
        if(tab[i]>tab[i+1])
        {
            std::cout << "table is not sorted!";
            std::cin.get();
            exit(1);
        }
    }
}

template void quickSort<int>(int*,int, int);
template int partition<int>(int*,int,int);
template void merge<int>(int*,int,int,int);
template void mergeSort<int>(int*,int,int);
template void insertionSort<int>(int*,int,int);
template void introSortMain<int>(int*,int*, int*,int);
template void introSort<int>(int*,int*, int*);
template void printTab<int>(int*,int);
template void loadTab<int>(int*,int, int);
template void isSorted<int>(int*,int);