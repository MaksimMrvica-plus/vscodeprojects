
#pragma execution_character_set("utf-8")

#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // �ַ�������ʼ��
    string str1 = "letme";
    string str2("fuck you and me");
    string str3(5, 'a');
    string str4(str1);

    cout << "��ʼ����" << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;


// ��ֵ���� assign
    // char* ȫ����ֵ
    // char* ǰ n ���ַ���ֵ
    // string ��ֵ
    // string �� start ��ʼ��ǰ n ���ַ���ֵ
    // �� n �� �ַ� c ��ֵ
    cout << "��ֵ��" << endl;
    str1.assign(str2, 2, 6); // �� str2 ��λ��2��ʼ��6���ַ���ֵ��str1��
    cout << str1 << endl;


// ׷�� 
    // append
    // ׷�� string
    // ׷�� string �� pos ��ʼ�� n ���ַ�
    // ׷�� char*
    // ׷�� char* ǰ n ���ַ�
    // ׷�� n �� �ַ� c
    // ׷�� ���������� [begin,end)
    str1.append(str1);  
    str1.append(str2, 2, 4);
    str1.append("kkkk");
    str1.append("apedsf",2);
    str1.append(5,'a');
    str1.append(str2.begin(),str2.end());
    // push_back �������һ���ַ�
    str1.push_back('c');  //  �൱�� str1.append(1, 'c');
    // ��������� +=
    str1 += str2;   // string
    str1 += "fsaf"; // c-style
    str1 += 'A';    // char


// ɾ�� 
    // erase
    str1.erase(3, 2); // ɾ����3��ʼ��2���ַ�
    // pop_back ɾ�����һ���ַ�
    str1.pop_back();  

// �滻 replace
    // ��pos λ�ÿ�ʼ �� n ���ַ��滻Ϊstring
    // ��pos λ�ÿ�ʼ �� n ���ַ��滻Ϊchar*
    str1.replace(5, 2, str2); // ��5λ�ÿ�ʼ��ȡ2λ���ȣ� �滻Ϊ str2�� �ַ��������Գ���str2���ȣ�ȡstr2.size()
    cout << str1 << endl
         << str2 << endl;


// ���� insert
    // ��posλ�ò����ַ���string
    // ��posλ�ò����ַ�����char*
    // ��posλ�ò���n���ַ�c
    str1.insert(0, 4 , 'b');  // ��ͷ���� "bbbb"





// �Ƚ������ַ�����С
    // �ַ���str1��str2֮��Ĵ�С���� �� ����ֵ��-1��0��1���� 0 ֮��Ĵ�С������ͬ
    // str1 < str2     return -1
    // str1 == str2    return 0
    // str1 > str2     return 1
    // ��дA��Сдa ��С
    str1 = "ABC";
    str2 = "abc";
    cout << str1 << " �� " << str2 << " ��С�Ƚϣ�" << endl;
    cout << str1.compare(str2) << endl;
    // ��������� <  >  <=  >=  ==  !=
    cout << (bool)(str1 <= str2) << endl;


// ���� find
    // ���� string , �� pos=0 λ�ÿ�ʼ
    // ���� char* , �� pos=0 λ�ÿ�ʼ
    //  char* , �� pos λ�ÿ�ʼ , ������ǰ n ���ַ���
    // �����ַ� c , �� pos=0 λ�ÿ�ʼ
    str1.find("hello", 0, 3); // �� str1 �� �� 0 λ�ÿ�ʼ ���� "hel"


//  �Ӵ� substr(int n = 0, int pos = npos)
    str1 = str2.substr(1,4);  // ����str2�Ӵ��� 1 ��ʼ������ 4 ���ַ�����


// ����find��substrʵ���ַ����ָ�����ṹ���浽vector��;
    str3 = "www.fuck.you.com.cn";
    vector<string> vstr;
    int pos = 0;
    string tmp;
    while (1)
    {
        int ret = str3.find('.', pos);
        if (ret < 0)
        {
            tmp = str3.substr(pos, str3.size());
            vstr.push_back(tmp);
            break;
        }
        else
        {
            tmp = str3.substr(pos, ret - pos);
            vstr.push_back(tmp);
            pos = ++ret;
        }
    }
    cout << "��ȡ�ַ����£�" << endl;
    for (string str : vstr)
    {
        cout << str << endl;
    }


// string �� c-style ת��
    // string -> c-style
    char *c = (char *)str1.c_str(); // c_str()����const char* , ������Ҫת��һ��
    // c-style -> string
    str1 = string(c);



    // system("pause");

    return 0;
}