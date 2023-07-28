#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
constexpr int TOTALBOOK_COUNT = 1000;



typedef pair<int,int> PII;
struct cmp{
    bool operator()(PII a, PII b){
        return a.second < b.second;
    }
};

class Assistant {
public:
    Assistant(int bookshelfCapacity);

    bool get(int bookNo);
    bool put(int bookNo);

    void store(int bookNo);
    void archive(int bookNo);
    
private:
    int shelfcnt;
    int storecnt;
    int bookshelfCapacity;
    priority_queue<PII,vector<PII>,cmp > pqueue;
    unordered_map<int,int>bookshelf;
    unordered_map<int,int>bookstore;
    unordered_map<int,int>temp;
};
Assistant::Assistant(int bookshelfCapacity){
    this->bookshelfCapacity = bookshelfCapacity;
    shelfcnt = 0;
    storecnt = 0;
}
bool Assistant::get(int bookNo){
    if(bookshelf.find(bookNo)!=bookshelf.end()){//书架上有
        shelfcnt--;
        bookshelf[bookNo]++;
        temp[bookNo]=bookshelf[bookNo]; // 移除书架
        bookshelf.erase(bookNo);
    }
    else if(bookstore.find(bookNo)!=bookstore.end()){
        storecnt--;
        bookstore[bookNo]++;
        temp[bookNo]=bookstore[bookNo];
        bookstore.erase(bookNo);
    }
    else cout<<"No book!"<<endl;
}
bool Assistant::put(int bookNo){
}

void Assistant::store(int bookNo){
    if(shelfcnt>=bookshelfCapacity)cout<<"shelf full"<<endl;
    else{
        pqueue.push(PII(bookNo,0));
        shelfcnt++;
        bookshelf[bookNo]=0;
    }
}
void Assistant::archive(int bookNo){
    if(shelfcnt+storecnt>=TOTALBOOK_COUNT)cout<<"total book full"<<endl;
    else{
        storecnt++;
        bookstore[bookNo]=0;
    }
}