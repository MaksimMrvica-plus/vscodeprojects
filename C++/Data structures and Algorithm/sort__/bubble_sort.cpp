// n个元素排n-1轮
// 每一轮  从左开始，i=0,依次与右侧arr[i+1]值比较
// 如果arr[i]小，继续下一轮
// 如果arr[i]大，那么交换arr[i]和arr[i+1]
// i++
// i的范围[0,n-i);
// 从右往左逐渐有序

#include <iostream>
#include <iomanip>

using namespace std;
// 数组打印
template <typename T>
void print_arr(T *arr, int n);
template <typename T>
void bubble_sort(T *arr, int n);
template <typename T>
void bubble_sort_ifswap(T *arr, int n);

int main()
{
    int arr[] = {25, 8, 1, 7, 3, 4, 111, 432, 5, 66, 21, 5};
    bubble_sort(arr, sizeof(arr) / sizeof(int));  //  原始
    bubble_sort_ifswap(arr, sizeof(arr) / sizeof(int));  //  优化

    return 0;
}



template <typename T>
void bubble_sort(T *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        // 输出
        cout << setw(2) << i + 1 << "  |  ";
        print_arr(arr, n);
    }
}

// 优化：用ifswap来标记，如果一轮中没有交换，代表已经有序，不需要再继续下去
template <typename T>
void bubble_sort_ifswap(T *arr, int n)
{
    int i, j;
    int ifswap; // 标记，如果一轮中没有交换，代表已经有序
    for (i = 0; i < n - 1; i++)
    {
        ifswap = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                ifswap = 1; // 发生交换
            }
        }

        // 输出
        cout << setw(2) << i + 1 << "  |  ";
        print_arr(arr, n);
        // 判断是否提前结束
        if(!ifswap)break;
    }
}


template <typename T>
void print_arr(T *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}