/*
 * BST.cpp
 * created on june 2 2015
 * author: sheaim
 *
 */

 #include "BST.h"

BSTree::BSTree()
{
    root = NULL;

}

BSTree::~BSTree()
{
    clear();
}

void BSTree::push(const int n)
{
    push(n,root);
}

int BSTree::max(int v1, int v2)
{
    return ((v1 > v2) ? v1 : v2);
}

int BSTree::bstHeight(Node * h)
{
    int n;
    if( h == NULL)
    {
        return -1;
    }
    else
    {
        n = h->height;
        return n;
    }

}


bool BSTree::search(const int s, Node * & tree)
{
    if(tree == NULL)
    {
        return false;
    }
    else if(s < tree->data)
    {
        return search(s, tree->left);
    }
    else if(tree->data < s)
    {
        return search(s, tree->right);
    }
    else
    {
        ;
    }
}

bool BSTree::search(const int x)
{
    if (search(x, root)){
        return true;
    }
    else
        return false;
}

void BSTree::clear(Node* & tree)
{
    if(tree->left==NULL&&tree->right==NULL)
    {
        delete tree;
    }
    else
    {
        if(tree->left!=NULL)
        {
            clear(tree->left);
        }
        if(tree->right!=NULL)
        {
            clear(tree->right);
        }
    }
}

void BSTree::clear()
{
    clear(root);
    root = NULL;
}

void BSTree::push(const int n, Node* & v)
{
    if (v == NULL)
    {
        v = new Node(n , NULL, NULL, 0);
    }
    else
    {
        if ( n < v->data)
        {
            push(n, v->left);   // goes to left node
        }
        else if ( v->data < n)
        {
            push(n, v->right);  // goes to right node
        }
        else
        {
            ; // duplicate; do nothing.
        }
    }
    int a,b,c;
    a = bstHeight(v->left);
    b = bstHeight(v->right);
    c = max(a,b);
    v->height = c + 1;

}

void BSTree::printPreOrder() const
{
    preOrder(root);
}


void BSTree::preOrder(Node* pre) const
{
    if(pre != NULL)
    {
        std::cout << " " << pre->data << " ";
        preOrder(pre->left);
        preOrder(pre->right);
    }
}

Node* BSTree::getRoot()
{
    return root;
}

void BSTree::print(Node *node, int level)
{
    int i;
    if (node!=NULL)
    {
        print(node->right, level + 1);
        std::cout<<std::endl;
        if (node == root)
        std::cout<<"Root -> ";
        for (i = 0; i < level && node != root; i++)
        std::cout<<"        ";
        std::cout<<node->data;
        print(node->left, level + 1);
    }
}

