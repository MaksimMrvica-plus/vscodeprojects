//  取一个值为临界值（此例为 第一个）
//  将小于界值的放在左边
//  将大于界值的放在右边
//  对左右子序列分别重复上述过程（递归）

#include <iostream>
#include <string>

using namespace std;

// 接受一个序列首地址指针，一个元素数量，从小到大
template <typename T>
void quick_sort(T arr[], int n)
{
    if (n < 2)
        return; // 小于两个元素，无需再排序

    T mid = arr[0];
    int l = 0, r = n - 1;
    bool lor = 1; //  该检查右面还是左面，如果取第一个元素为中间值，那么arr[l]处为空，先从右面开始检查
    // arr[l]和 arr[r] 那边空着，就从另一边检查。
    while (l < r)
    {
        // 右侧检查
        if (lor)
        {
            if (arr[r] < mid)
            { //  arr[r]要移到左面，l右移，arr[r]为空，下一次从左面检查,所以lor=0
                arr[l] = arr[r];
                l++;
                lor = 0;
            }

            else
            { //  arr[r]本来就在右面，不需要对他操作，相当于跳过这次检查，r左移
                r--;
            }
        }
        // 左侧检查
        else
        {
            if (arr[r] > mid)
            { //  arr[l]要移到右面，r左移，arr[l]为空，下一次从右面检查,所以lor=1
                arr[r] = arr[l];
                r--;
                lor = 1;
            }
            else
            { //  arr[l]本来就在左面，不需要对他操作，相当于跳过这次检查，l右移
                l++;
            }
        }
    }
    // 到此处l==r ，这个位置是留给mid
    arr[l] = mid; // arr[r] = mid;
    // 递归左右两侧
    quick_sort(arr, l);
    quick_sort(arr + l + 1, n - l - 1);
}

int main()
{
    string arr[5]={"abc","afjsi","afjstt","szi","oijwf"};
    //int arr[] = {1, 2, 5, 7, 8, 2, 3, 4, 7, 8, 20};
    quick_sort(arr, 5);
    for (auto x : arr)
    {
        cout << x << endl;
    }
    cout << "why" << endl;

    return 0;
}