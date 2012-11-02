#include <iostream>
#include <cstring>

using namespace std;

const int int_array[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
const int key = 5;

int search (const int a[], const int k, int min, int max)
{
    int mid = (min + max) / 2;
    int ret;

    if (a[mid] == k)
        return mid;

    if (max - min <= 1)
        return -1;

    cout << "min, max: " << min << ", " << max << endl;
    if (a[mid] > a[min]) {
        if (a[mid] > k)
            ret = search(a, k, min, mid);
        else
            ret = search(a, k, mid, max);
    }
    else {
        ret = search(a, k, min, mid);
        if (ret >= 0)
            return ret;
        ret = search(a, k, mid, max);
    }

    if (ret >= 0)
        return ret;
}

int main(void)
{
    int ret = search(int_array, key, 0, 11);
    cout << "result: " << ret << endl;
}
