#include <string>
#include <iostream>
using namespace std;
enum class OrderType
{
    InOrder,
    PreOrder,
    PostOrder
};
struct BinTree
{
    string name;
    BinTree *left = nullptr;
    BinTree *right = nullptr;
    void inorder(BinTree *node);
    void preorder(BinTree *node);
    void postorder(BinTree *node);

};

struct Data
{
    void *memory;
    unsigned int size;
};
Data serialize(const BinTree &tree, OrderType order);
BinTree deserialize(const Data &data);

void BinTree::inorder(BinTree *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->name << endl;
    inorder(node->right);
}
void BinTree::preorder(BinTree *node)
{
    if (node == nullptr)
        return;
    cout << node->name << endl;
    inorder(node->left);
    inorder(node->right);
}
void BinTree::postorder(BinTree *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    inorder(node->right);
    cout << node->name << endl;
}

Data serialize(const BinTree &tree, OrderType order){
    if(order==InOrder)
}