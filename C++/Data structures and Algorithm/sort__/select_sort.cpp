//  n个元素重复n-1轮
//  每一轮挑选一个最小值，与本轮最开始位置元素交换
//  轮数 i [0,n-1)
//  每轮 j [i+1,n) , 借助 temp 和 cur 记录 最小值 和 位置 , 最后与 arr[i] 交换。 
// 从左往右开始有序

#include<iostream>
using namespace std;
template <typename T>
void print_arr(T *arr, int n);

template<typename T>
void select_sort(T *arr,int n);

template<typename T>
void select_sort_double(T *arr,int n);

int main(){
    int arr[] = {52,15,152,10,634,23,21,5,1,6,34,2};
    // select_sort(arr,sizeof(arr)/sizeof(int));
    select_sort_double(arr,sizeof(arr)/sizeof(int));
    return 0;
}


template <typename T>
void print_arr(T *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}



template<typename T>
void select_sort(T *arr,int n){
    int i,j;
    int cur;
    T temp;
    for(i=0;i<n-1;i++){
        temp = arr[i];
        cur = i;
        for(j = i+1;j<n;j++){
            if(arr[j]<temp)
            {
                temp = arr[j];
                cur = j;
            }
        }
        swap(arr[i],arr[cur]);
        // 输出每一轮结果
        print_arr(arr, n);
    }
}

// 优化，每一轮中不仅选出最小值，同时选出最大值，将最小值放在左侧，最大值放在右侧
template<typename T>
void select_sort_double(T *arr,int n)
{
    int i,j,mincur,maxcur;
    T minval,maxval;
    for(i=0;i<n/2;i++){
        mincur = maxcur = i;
        minval = maxval = arr[i];
        for(j=i+1;j<n-i;j++){
            if(arr[j]<minval){
                minval = arr[j];
                mincur = j;
            }
            if(arr[j]>maxval){
                maxval = arr[j];
                maxcur = j;
            }
        }
        // 注意 用两次swap会导致错误，因为中途会导致最值改变
        // 所以需要先将 边界值放入 最值位置，又因为minval和maxval已经记录了下来。最后赋予边界 最大值 和 最小值。
        arr[mincur] = arr[i];
        arr[maxcur] = arr[n-i-1];
        arr[i] = minval;
        arr[n-i-1] = maxval;
        print_arr(arr,n);
    }
}