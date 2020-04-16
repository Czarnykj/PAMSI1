/*****************
 * Konrad Czarny *
 * 235778        *
 * PAMSI 1       *
 * ***************/

#include "algorithms.h"
#include <iostream>
#include <chrono>
#include <fstream>

#define DataType int

template<typename T>
T* createTable(int size)
{
    return new T[size];
}

template<typename T>
void destroyTable(T *table)
{
    delete[] table;
}

template<typename T>
void sortPercent(T *tab,int size,double percent)
{
    if(percent == 100)
    {
        std::sort(tab,tab+size,std::greater<T>());
        return;
    }
    std::sort(tab,tab+(int)((size*percent)/100));
}

void isOpened(std::ofstream &file)
{
    if(!file.is_open())
    {
        std::cout<<"File is not opened!";
        std::cin.get();
        exit(1);
    }
}

int main()
{
    std::ofstream file("Results.txt");
    isOpened(file);
    srand(time(NULL));

    int size = 0;
    double percentTable[8] = {0,25,50,75,95,99,99.7,100};
    int sizeTable[5] = {10000,50000,100000,500000,1000000};

    DataType **tablicaTablic = new DataType*[100];

    for (int j = 0; j < 5;j++)
    {
        size = sizeTable[j];
        file << "czasy dla sortowania 100 tablic o rozmiarze: " << size << "\n";
        std::cout << "czasy dla sortowania 100 tablic o rozmiarze: " << size << "\n";

        for (int percent = 0; percent < 8; percent++)
        {
            file << "posortowanie w " << percentTable[percent] << "%\n";
            std::cout << "posortowanie w " << percentTable[percent] <<"%\n";

            for (int k = 0; k < 3; k++)
            {
                for (int i = 0; i < 100; i++)
                {
                    tablicaTablic[i] = createTable<DataType>(size);
                    loadTab<DataType>(tablicaTablic[i], size, 100);
                }

                for (int i = 0; i < 100; i++)
                {
                    sortPercent<DataType>(tablicaTablic[i],size,percentTable[percent]);
                }

                if (k == 0)
                {
                    auto t_start = std::chrono::high_resolution_clock::now();
                    for (int quick = 0; quick < 100; quick++)
                    {
                        quickSort<DataType>(tablicaTablic[quick], 0, size);
                    }
                    auto t_stop = std::chrono::high_resolution_clock::now();
                    double duration = std::chrono::duration<double, std::milli>(t_stop - t_start).count();

                    file << "to jest wynik dla quicksort:\n";
                    std::cout << "to jest wynik dla quicksort:\n";
                    for (int i = 0; i < 100; i++)
                    {
                        isSorted<DataType>(tablicaTablic[i], size);
                    }
                    file << duration << "\n";
                    std::cout << duration << "\n";

                }

                if (k == 1)
                {
                    auto t_start = std::chrono::high_resolution_clock::now();
                    for (int merge = 0; merge < 100; merge++)
                    {
                        mergeSort<DataType>(tablicaTablic[merge], 0, size);
                    }
                    auto t_stop = std::chrono::high_resolution_clock::now();
                    double duration = std::chrono::duration<double, std::milli>(t_stop - t_start).count();

                    file << "to jest wynik dla mergesort:\n";
                    std::cout << "to jest wynik dla mergesort:\n";
                    for (int i = 0; i < 100; i++)
                    {
                        isSorted<DataType>(tablicaTablic[i], size);
                    }
                    file << duration << "\n";
                    std::cout << duration << "\n";

                }

                if (k == 2)
                {
                    auto t_start = std::chrono::high_resolution_clock::now();
                    for (int i = 0; i < 100; i++)
                    {
                        introSort<DataType>(tablicaTablic[i], &tablicaTablic[i][0], &tablicaTablic[i][size]);
                    }
                    auto t_stop = std::chrono::high_resolution_clock::now();
                    double duration = std::chrono::duration<double, std::milli>(t_stop - t_start).count();

                    file << "to jest wynik dla introsort:\n";
                    std::cout << "to jest wynik dla introsort:\n";
                    for (int i = 0; i < 100; i++)
                    {
                        isSorted<DataType>(tablicaTablic[i], size);
                    }
                    file << duration << "\n";
                    std::cout << duration << "\n";
                }
            }
        }
    }
    file.close();
    for(int i = 0; i < 100; i++)
    {
        destroyTable<DataType>(tablicaTablic[i]);
    }
    delete[] tablicaTablic;

    tablicaTablic = NULL;
    return 0;
}
