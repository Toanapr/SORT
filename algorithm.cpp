#include "headers/Algorithm.h"

void bubbleSort(std::vector<int> &arr, unsigned long long &countComparisons)
{
    int n = arr.size();
    for (int i = 0; ++countComparisons && i < n - 1; i++)
    {
        for (int j = 0; ++countComparisons && j < n - i - 1; j++)
        {
            if (++countComparisons && arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void countingSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();
    int max = arr[0];

    for (int i = 1; ++countComparison && i < n; i++)
    {
        if (++countComparison && arr[i] > max)
            max = arr[i];
    }

    std::vector<int> count(max + 1, 0);
    for (int i = 0; ++countComparison && i < n; i++)
        count[arr[i]]++;
    for (int i = 1; ++countComparison && i <= max; i++)
        count[i] += count[i - 1];

    std::vector<int> res(n);
    for (int i = n - 1; ++countComparison && i >= 0; i--)
    {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = std::move(res);
}
void flashSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();
    long long min = arr[0], max = arr[0];

    for (int i = 0; ++countComparison && i < n; i++)
    {
        if (++countComparison && min > arr[i])
            min = arr[i];
        if (++countComparison && max < arr[i])
            max = arr[i];
    }

    if (++countComparison && min == max)
        return;

    long long m = 0.45 * n;
    std::vector<int> l(m, 0);

    for (int i = 0; ++countComparison && i < n; i++)
    {
        long long k = floor((m - 1) * (arr[i] - min) * 1.0 / (max - min));
        l[k]++;
    }

    for (int i = 1; ++countComparison && i < m; i++)
    {
        l[i] += l[i - 1];
    }

    int move = 0;
    int flash = 0;
    int hold = 0;
    long long k = 0;
    int i = 0;

    while (++countComparison && move < n - 1)
    {
        while (++countComparison && i > l[k] - 1)
        {
            i++;
            if (++countComparison && i >= n) break;
            k = floor((m - 1) * (arr[i] - min) / (max - min));
        }

        if (++countComparison && i >= n) break;

        flash = arr[i];
        if (++countComparison && k < 0)
            break;

        while (++countComparison && i != l[k])
        {
            k = floor((m - 1) * (flash - min) / (max - min));
            if ((++countComparison && k < 0) || (++countComparison && k >= m)) break;
            --l[k];
            hold = arr[l[k]];
            arr[l[k]] = flash;
            flash = hold;
            move++;
        }
    }

    insertionSort(arr, countComparison);
}

void heapify(std::vector<int> &arr, int n, int i, unsigned long long &countComparison)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++countComparison && left < n && ++countComparison && arr[largest] < arr[left])
        largest = left;

    if (++countComparison && right < n && ++countComparison && arr[largest] < arr[right])
        largest = right;

    if (++countComparison && largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, countComparison);
    }
}

void heapSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();

    for (int i = n / 2 - 1; ++countComparison && i >= 0; i--)
    {
        heapify(arr, n, i, countComparison);
    }

    for (int i = n - 1; ++countComparison && i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, countComparison);
    }
}

void insertionSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();
    for (int i = 1; ++countComparison && i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (++countComparison && j >= 0 && ++countComparison && arr[j] > key)
        {

            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void merge(std::vector<int> &arr, int left, int mid, int right, unsigned long long &countComparison)
{
    int n = mid - left + 1;
    int m = right - mid;

    std::vector<int> b(n), c(m);

    for (int i = 0; ++countComparison && i < n; i++)
    {
        b[i] = arr[left + i];
    }

    for (int i = 0; ++countComparison && i < m; i++)
    {
        c[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (++countComparison && i < n && ++countComparison && j < m)
    {
        if (++countComparison && b[i] < c[j])
        {
            arr[k++] = b[i++];
        }
        else
        {
            arr[k++] = c[j++];
        }
    }

    while (++countComparison && i < n)
    {
        arr[k++] = b[i++];
    }

    while (++countComparison && j < m)
    {
        countComparison++;
        arr[k++] = c[j++];
    }
}

void mergeSortRecur(std::vector<int> &arr, int left, int right, unsigned long long &countComparison)
{
    if (++countComparison && left < right)
    {
        int mid = (left + right) / 2;

        mergeSortRecur(arr, left, mid, countComparison);
        mergeSortRecur(arr, mid + 1, right, countComparison);

        merge(arr, left, mid, right, countComparison);
    }
}

void mergeSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int left = 0;
    int right = arr.size() - 1;

    mergeSortRecur(arr, left, right, countComparison);
}

int partition(std::vector<int> &arr, int left, int right, unsigned long long &countComparison)
{
    int pivot_value = arr[left + (right - left) / 2];
    int i = left, j = right;
    while (++countComparison && i <= j)
    {
        while (++countComparison && arr[i] < pivot_value)
        {
            i++;
        }

        while (++countComparison && arr[j] > pivot_value)
        {
            j--;
        }

        if (++countComparison && i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSortRecursive(std::vector<int> &arr, int left, int right, unsigned long long &countComparison)
{
    if (++countComparison && left >= right)
    {
        return;
    }

    int pivot = partition(arr, left, right, countComparison);

    quickSortRecursive(arr, left, pivot - 1, countComparison);
    quickSortRecursive(arr, pivot, right, countComparison);
}

void quickSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    quickSortRecursive(arr, 0, arr.size() - 1, countComparison);
}

void countSort(std::vector<int> &arr, int n, int pos, unsigned long long &countComparison)
{
    std::vector<int> count(10, 0);

    for (int i = 0; ++countComparison && i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; ++countComparison && i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    std::vector<int> ans(n);
    for (int i = n - 1; ++countComparison && i >= 0; i--)
    {
        ans[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; ++countComparison && i < n; i++)
    {
        arr[i] = ans[i];
    }
}

void radixSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();
    int k = arr[0];
    for (int i = 1; ++countComparison && i < n; i++)
    {
        k = std::max(k, arr[i]);
    }

    for (int pos = 1; ++countComparison && (k / pos) > 0; pos *= 10)
    {
        countSort(arr, n, pos, countComparison);
    }
}

void selectionSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();

    for (int i = 0; ++countComparison && i < n - 1; ++i)
    {
        int min_idx = i;

        for (int j = i + 1; ++countComparison && j < n; ++j)
        {
            if (++countComparison && arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        std::swap(arr[i], arr[min_idx]);
    }
}

void shakerSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();

    int l = 0;
    int r = n - 1;
    int k = 0;
    int i;

    while (++countComparison && l < r)
    {
        for (i = l; ++countComparison && i < r; i++)
        {
            if (++countComparison && arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        r = k;
        for (i = r; ++countComparison && i > l; i--)
        {
            if (++countComparison && arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        l = k;
    }
}

void shellSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();

    for (int gap = n / 2; ++countComparison && gap > 0; gap /= 2)
    {
        for (int i = gap; ++countComparison && i < n; i++)
        {
            int temp = arr[i];

            int j;
            for (j = i; ++countComparison && j >= gap && ++countComparison && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
