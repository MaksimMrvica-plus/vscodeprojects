// 从第2个元素开始，从左往右
// 对于每一个元素，与左侧比较，如果小于就交换，向前循环，直至不小或前面无元素
//
// 问题
// 1 查找插入位置
// 2 移动元素（从插入位置到原本位置）
// 优化
// 1 对前面已经排好的使用二分查找
// 2 携带多个元素
// 3 数据链表化
// 4 希尔排序

#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
void print_arr(T *arr, int n);
template <typename T>
void insert_sort(T *arr, int n);

int main()
{
    int arr[] = {25, 8, 1, 7, 3, 4, 111, 432, 5, 66, 21, 5};
    insert_sort(arr, sizeof(arr) / sizeof(int));
    print_arr(arr, sizeof(arr) / sizeof(int));  // 打印结果
    return 0;
}

template <typename T>
void insert_sort(T *arr, int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        while (j >= 0)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                j--;
            }
            else
                break;
        }
        // print_arr(arr, n);  // 打印每一轮结果
    }
}

template <typename T>
void print_arr(T *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
