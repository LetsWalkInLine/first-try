#include <iostream>
using namespace std;

//little change
//¡ı»Û«‰

void sift(int a[], int root, int len)
{
    a[0] = a[root];
    int max_child_index = root * 2;
    while (max_child_index <= len)
    {
        if (max_child_index + 1 <= len && a[max_child_index + 1] > a[max_child_index])
            max_child_index++;
        if (a[max_child_index] > a[0])
        {
            a[root] = a[max_child_index];
            root = max_child_index;
            max_child_index *= 2;
        }
        else
            break;
    }
    a[root] = a[0];
}

void heap_sort(int a[], int len)
{
    for (int i = len / 2; i >= 1; i--)
        sift(a, i, len);

    for (int i = len; i >= 2; i--)
    {
        swap(a[i], a[1]);
        sift(a, 1, i - 1);
    }
}

int main()
{
    int a[] = {0, 12, 15, 30, 80, 100, 46, 78, 33, 90, 86, 64, 55, 120, 230, 45};
    int len = sizeof(a) / sizeof(int) - 1;

    heap_sort(a, len);
    for (int i = 1; i <= len; i++)
        cout << a[i] << " ";
    cout << endl;
}
