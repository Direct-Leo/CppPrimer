/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_27
 * my own HasPtr
 */ 

#ifndef EX_13_28_H
#define EX_13_28_H

#include <string>
using std::string;

class TreeNode{
public:
TreeNode(): 
value(""), count(new int(1)), left(nullptr), right(nullptr) {}

TreeNode(const TreeNode& rhs) :
value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right)
{ ++*count; }

TreeNode& operator=(const TreeNode& rhs);

~TreeNode()
{
    if(--*count == 0)
    {
        if(left)
        {
            delete left;
            left = nullptr;
        }
        if(right)
        {
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
}


private:
    string value;
    int* count;
    TreeNode* left;
    TreeNode* right;
};

class BinStrTree{
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree& bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree& operator=(const BinStrTree& bst);
    ~BinStrTree() { delete root; }

private:
    TreeNode* root;
};

#endif


