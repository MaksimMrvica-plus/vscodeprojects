#include <bits/stdc++.h>

using namespace std;
/*


*/
void make_n_random_vector(int n, int begin, int end, int loop = 1)
{
    /**
     * 生成一个包含n个随机整数的向量，输出数组格式 [ , , , , ] 
     *
     * @param n 随机整数的数量
     * @param begin 随机整数的最小值
     * @param end 随机整数的最大值
     * @param loop 循环生成的批数，默认为1
     */
    int sep = end - begin + 1;
    int epoch = loop;
    int m = n;

    srand(time(nullptr));
    for (int i = 0; i < epoch; i++)
    {
        cout<<'[';
        for (int j = 0; j < m; j++)
        {
            if(j)cout << ','<< rand() % sep + begin ;
            else     cout << rand() % sep + begin ;
        }
        cout <<']'<< endl;
    }
}
int main()
{
    make_n_random_vector(10, 1, 20, 5);
}
