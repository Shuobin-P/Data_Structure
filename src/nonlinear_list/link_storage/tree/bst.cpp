/********************************************************************************
* @author: Shuobin
* @date: 2024/4/12 18:37
* @version: 1.0
* @description:  二叉排序树的实现
********************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "bst.h"

void insertIntoBST(BST &bst, DATA_TYPE val) {
    //非递归实现插入操作
    //找到待插入节点的父节点
    //再判断插入左子树还是右子树
    if (bst.root == NULL) {
        bst.root = (TreeNode *) malloc(sizeof(TreeNode));
        bst.root->data = val;
    }
    TreeNode *slow = NULL;
    TreeNode *fast = bst.root;
    while (fast) {
        slow = fast;
        if (fast->data > val) {
            fast = fast->left;
        } else {
            fast = fast->right;
        }
    }
    if (slow->data > val) {
        slow->left = (TreeNode *) malloc(sizeof(TreeNode));
        slow->left->data = val;
    } else if (slow->data < val) {
        slow->right = (TreeNode *) malloc(sizeof(TreeNode));
        slow->right->data = val;
    }
}

