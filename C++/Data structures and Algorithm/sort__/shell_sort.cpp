// 分组  step = n/2
// 每组对应位置 进行插入排序
// 循环直至 step = 1（最后一定会）
// 进行最后一次整体插入排序

#include <iostream>
#include <iomanip>

using namespace std;
// 数组打印
template <typename T>
void print_arr(T *arr, int n);
template <typename T>
void shell_sort(T *arr, int n);
template <typename T>
void group_sort(T *arr, int n,int pos,int step);


int main()
{
    int arr[] = {25, 8, 1, 7, 3, 4, 111, 432, 5, 66, 21, 5,7};
    shell_sort(arr,sizeof(arr)/sizeof(int));

    return 0;
}

template <typename T>
void shell_sort(T *arr, int n)
{
    int i;
    int step = n/2;
    while(step)
    {
        for(i=0;i<step;i++){
            group_sort(arr,n,i,step);
        }
        // 打印分组间隔，和每种间隔排序结果
        cout<<step<<endl;
        print_arr(arr,n);
        step/=2;
    }
}

template <typename T>
void group_sort(T *arr, int n,int pos,int step)
{
    T temp;  // 存放 正在排序的值
    int i;  // 正在排序位置
    int j;  // 正在比较的位置
    for(i = pos+step;i<n;i+=step){
        temp = arr[i];
        for(j = i - step;j>=0;j-=step){
            if(arr[j]<temp)break;
            arr[j+step] = arr[j];
        }
        arr[j+step] = temp;
    }
}


template <typename T>
void print_arr(T *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}