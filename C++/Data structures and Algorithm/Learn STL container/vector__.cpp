#include<iostream>
#include<vector>

using namespace std;
// 打印vector内容,函数重载
template<typename T>
void pr_vec(const vector<T>& v){  // 一维
    for(T x:v)cout<<x<<"\t";
    cout<<endl;
}
template<typename T>
void pr_vec(const vector<vector<T> >& v){  // 二维
    for(vector<T> y:v){
        for(T x:y){cout<<x<<"\t";}
        cout<<endl;
    }
}

int main(){

// 初始化
    vector<int> v1;
    vector<int> v2(5,100); // n 个 val
    vector<int> v3(v2);  //  拷贝构造函数，只会拷贝实际大小(size)的内容，而不受容量capacity的影响
    vector<int> v4(v2.begin(),v2.end());

    vector<vector<double>> vd1={{1.0,2.0},{3.0,4.0}};
    pr_vec(v1);
    pr_vec(v2);
    pr_vec(v3);
    pr_vec(v4);

    pr_vec(vd1);
// 赋值
    // assign(n,val)
    // assign(vector)
    // assign(begin,end)
    // 重载运算符
    v1.assign(v3.begin(),v3.end());
    v2 = v3;
    

// 大小
    v1.size();
    v1.empty();
    v1.resize(10);  // 大小重新设置为 10，多余删除，不足用默认值填充
    v1.resize(20,0);  // 大小重新设置为 20, 多余删除，不足用 0 填充
    v1.capacity();  
    v1.reserve(100);  // 预留 100 个空间，影响 capacity
    // 交换
    v1.swap(v2);
    // 利用 swap 实现缩小 capacity 以节省空间
    vector<int>(v1).swap(v1);  //  利用匿名对象，拷贝构造一个大小、容量 与原v1大小相同的新vector
                               //  然后与原v1进行交换，匿名对象存活周期为当前语句，会自动释放
    // 优化空间 shrink_to_fit
    v1.shrink_to_fit();  // 将 capacity 缩小到与 size 一样

//  存取
    v1.at(4);  //  越界抛出 out_of_range 异常
    v1[4];     //  越界编译错误
    v1.front();     //  第一个元素引用
    v1.back();      //  第最后一个元素引用

//  插入/删除
    // insert(iter, n, val)
    // insert(iter, begin, end)
    // insert
    v1.insert(v1.begin(),v2.begin(),v2.end());
    v1.push_back(6);
    v1.pop_back();
    // erase(iter)  erase()返回指向所删除内容下一个元素的迭代器
    // erase(begin, end)
    v1.clear();  //  影响size，并不会改变capacity
    
    return 0;
}   