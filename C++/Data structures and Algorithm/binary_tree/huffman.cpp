// 数组存储节点
// 用结构体表示，记录权值，父亲，左右孩子
// 过程: 填表（初始化），改表（建树），读表（读树）
//
// 输入
// 7  第一行n,节点个数，接下来n行，各个节点权值
// 2
// 3
// 4
// 5
// 6
// 2
// 4
//
// 输出
// weight:        2        parent:        7        left:       -1  right:       -1
// weight:        3        parent:        8        left:       -1  right:       -1
// weight:        4        parent:        8        left:       -1  right:       -1
// weight:        5        parent:       10        left:       -1  right:       -1
// weight:        6        parent:       10        left:       -1  right:       -1
// weight:        2        parent:        7        left:       -1  right:       -1
// weight:        4        parent:        9        left:       -1  right:       -1
// weight:        4        parent:        9        left:        0  right:        5
// weight:        7        parent:       11        left:        1  right:        2
// weight:        8        parent:       11        left:        6  right:        7
// weight:       11        parent:       12        left:        3  right:        4
// weight:       15        parent:       12        left:        8  right:        9
// weight:       26        parent:       -1        left:       10  right:       11
// WPL : 71
// 1110
// 100
// 101
// 00
// 01
// 1111
// 110

#include<iostream>
#include<vector>
using namespace std;

// weight    parent  leftchild   rightchild     value
struct Node{
    int weight;
    int parent;
    int leftchild;
    int rightchild;
    void print(){
        printf("weight: %8d\tparent: %8d\tleft: %8d\tright: %8d\n",weight,parent,leftchild,rightchild);
        //cout<<"weight: "<<weight<<"\t\t"<<"parent: "<<parent<<"\t\t"<<"left: "<<leftchild<<"\t\t"<<"right: "<<rightchild<<endl;
    }
};


int main(){
    int n;
    cin>>n;// n 个节点
    int max_size = 2*n-1;
    Node *arr = new Node[max_size];
    int i,j,k;

    // 初始化，输入处理
    for(i=0;i<max_size;i++){
        arr[i].weight = 0;
        arr[i].leftchild=arr[i].rightchild=arr[i].parent=-1;
    }
    for(i=0;i<n;i++){
        cin>>arr[i].weight;
    }

    // 构建数，填表
    int min1,min2,cur1,cur2;
    for(i=n;i<max_size;i++){
        //找出2个最小权重的节点与位置
        min1=min2 = 2147483647;
        for(j=0;j<i;j++){
            if(arr[j].parent!=-1)continue;//已经合并就跳过
            if(arr[j].weight<min1){
                min2 = min1;//
                cur2 = cur1;

                min1 = arr[j].weight;
                cur1 = j;
            }
            else if(arr[j].weight<min2){
                min2 = arr[j].weight;
                cur2 = j;
            }
        }
        // cout<<min1<<'\t'<<cur1<<'\t'<<min2<<'\t'<<cur2<<'\t'<<endl; // 输出两个节点的信息
        // 改动表格数据
        arr[cur1].parent = i;
        arr[cur2].parent = i;
        arr[i].weight = min1+min2;
        arr[i].leftchild = cur1;
        arr[i].rightchild = cur2;

    }
    for(i=0;i<max_size;i++)arr[i].print(); // 输出表格信息
    // 计算WPL
    int length = 0;
    for(i=0;i<n;i++){ // 只计算前n个节点，因为后面n-1个是新加节点
        int path = 0;
        int cur = i;
        while(arr[cur].parent!=-1){
            path++;
            cur = arr[cur].parent;
        }
        length += arr[i].weight*path;
    }
    cout<<"WPL : "<<length<<endl; // 输出WPL
    // 计算编码
    vector<char>v;
    for(i=0;i<n;i++){
        int cur = i;
        while(cur!=-1){
            Node par = arr[arr[cur].parent];
            if(par.leftchild == cur)v.push_back('0');
            else if(par.rightchild==cur)v.push_back('1');
            cur = arr[cur].parent;
        }
        while(!v.empty()){ //正向存入，反向输出
            cout<<*(v.end()-1);
            v.pop_back();
        }
        cout<<endl;
    }
    return 0;
}