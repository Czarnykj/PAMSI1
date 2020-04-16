/*****************
 * Konrad Czarny *
 * 235778        *
 * PAMSI 1       *
 * ***************/
#ifndef PAMSI_1_ALGORITHMS_H
#define PAMSI_1_ALGORITHMS_H

#include<bits/stdc++.h>

//quicksort
template <typename T>
void quickSort(T *tab,int leftPointer, int rightPointer);
template <typename T>
int partition(T *tab,int leftPointer,int rightPointer);

//mergesort
template<typename T>
void merge(T *tab,int leftPointer,int middlePointer,int rightPointer);
template<typename T>
void mergeSort(T *tab,int leftPointer,int rightPointer);

//introsort
template<typename T>
void insertionSort(T *tab,int left,int right);
template<typename T>
void introSortMain(T *tab,T *begin, T *end,int depth);
template<typename T>
void introSort(T *tab,int *begin, int *end);


//
template<typename T>
void printTab(T *,int);

template<typename T>
void loadTab(T *,int, int);

template<typename T>
void isSorted(T *,int);
#endif //PAMSI_1_ALGORITHMS_H
