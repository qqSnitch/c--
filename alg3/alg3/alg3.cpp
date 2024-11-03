#include <iostream>
using namespace std;

void quicksort(int* a, int start, int end, long long& counter)
{
    int mid, temp;
    int i = start;
    counter += 1;
    int j = end;
    counter += 1;
    mid = a[(i + j) / 2];
    counter += 3;
    while (i <= j)
    {
        counter += 1;

        while (a[i] < mid)
        {
            i += 1;
            counter += 2;
            counter += 1;
        }
        counter += 1;

        while (a[j] > mid)
        {
            j -= 1;
            counter += 2;
            counter += 1;
        }
        counter += 1;

        if (i <= j)
        {
            temp = a[i];
            counter += 1;
            a[i] = a[j];
            counter += 1;
            a[j] = temp;
            counter += 1;
            i += 1;
            counter += 2;
            j -= 1;
            counter += 2;
        }
        counter += 1;
    }
    counter += 1;
    if (start < j) quicksort(a, start, j, counter);
    counter += 1;
    if (i < end) quicksort(a, i, end, counter);
}

void print(int* ar, int n)
{
    for (int k = 0; k < n; k++)
    {
        std::cout << ar[k] << " ";
    }
    std::cout << std::endl;
}

int n = STEP_VALUE;
// n от 100 до 10000 с шагом 100
int main()
{
    double mean[NUMBER_ITERATIONS];
    int min[NUMBER_ITERATIONS];
    int max[NUMBER_ITERATIONS];
    for (int i = 0; i < NUMBER_ITERATIONS; i++, n += STEP_VALUE)
    {
        long long counter = 0;
        int* ar = new int[n];

        for (int k = 0; k < n; k++)
        {
            ar[k] = k;
        }
        quicksort(ar, 0, n - 1, counter);
        min[i] = counter;

        counter = 0;
        int* v = new int[n];
        for (int k = 0; k < n; k++)
        {
            v[k] = k;
        }
        for (int k = 0; k < n; k++)
        {
            int pivot = (n - 1 + k) / 2;
            ar[v[pivot]] = k;
            int temp = v[pivot];
            v[pivot] = v[k];
            v[k] = temp;
        }
        delete[]v;
        quicksort(ar, 0, n - 1, counter);
        max[i] = counter;


        long long sum = 0;
        counter = 0;
        for (int e = 0; e < NUMBER_EX; e++)
        {
            counter = 0;
            for (int k = 0; k < n; k++)
            {
                ar[k] = rand();
            }
            quicksort(ar, 0, n - 1, counter);
            sum += counter;
        }
        mean[i] = double(sum) / double(NUMBER_EX);
        std::cout << "n=" << n << ":{min=" << min[i] << ";max=" << max[i] << ";mean=" << std::fixed << mean[i] << "}" << std::endl;
    }

    return 0;
}