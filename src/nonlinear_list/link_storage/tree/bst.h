/********************************************************************************
* @author: Shuobin
* @date: 2024/4/12 17:31
* @version: 1.0
* @description: 二叉排序树的实现
********************************************************************************/
#ifndef DATA_STRUCTURE_BST_H
#define DATA_STRUCTURE_BST_H
#define DATA_TYPE int
typedef struct TreeNode {
    DATA_TYPE data;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode *root;
} BST;

/**
 * 向二叉排序树中插入新的节点
 * @param root
 * @param val
 * @return BST的根节点
 */
void insertIntoBST(BST &bst, DATA_TYPE val);

#endif //DATA_STRUCTURE_BST_H
