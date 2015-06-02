/*
 * AVL.cpp
 * created on may 18 2015
 * author: sheaim
 *
 */

 #include "AVL.h"

AVLTree::AVLTree()
{
    root = NULL;

}

AVLTree::~AVLTree()
{
    clear();
}

void AVLTree::push(const int n)
{
    push(n,root);
}

void AVLTree::singleRightRotate(Node * & n)
{
    Node * temp;
    temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n = temp;
    n->height = max(avlHeight(n->left),avlHeight(n->right)) + 1;
    temp->height = max(n->height,avlHeight(temp->right)) + 1;


}

void AVLTree::singleLeftRotate(Node * & n)
{
    Node * temp;
    temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n = temp;
    n->height = max(avlHeight(n->left),avlHeight(n->right)) + 1;
    temp->height = max(avlHeight(temp->left),n->height) + 1;
}

void AVLTree::doubleRightRotate(Node * & n)
{
    singleLeftRotate(n->right);
    singleRightRotate(n);
}

void AVLTree::doubleLeftRotate(Node * & n)
{
    singleRightRotate(n->left);
    singleLeftRotate(n);
}

int AVLTree::max(int v1, int v2)
{
    return ((v1 > v2) ? v1 : v2);
}

int AVLTree::avlHeight(Node * h)
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


bool AVLTree::search(const int s, Node *& tree)
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

bool AVLTree::search(const int x)
{
    if (search(x, root)){
        return true;
    }
    else
        return false;
}

void AVLTree::clear(Node* tree)
{
    if(tree != NULL)
    {
        clear(tree->left);
        clear(tree->right);
        delete tree;

    }
    tree = NULL;
}

void AVLTree::clear()
{
    clear(root);
    root = NULL;
}

void AVLTree::push(const int n, Node* & v)
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

            if ((avlHeight(v->left) - avlHeight(v->right))==2)
            {
                if (n < v->left->data)
                {
                    singleLeftRotate(v);
                }
                else
                {
                    doubleLeftRotate(v);
                }
            }
        }
        else if ( v->data < n)
        {
            push(n, v->right);  // goes to right node
            if ((avlHeight(v->right) - avlHeight(v->left))==2)
            {
                if (n > v->right->data)
                {
                    singleRightRotate(v);
                }
                else
                {
                    doubleRightRotate(v);
                }
            }
        }
        else
        {
            ; // duplicate; do nothing.
        }
    }
    int a,b,c;
    a = avlHeight(v->left);
    b = avlHeight(v->right);
    c = max(a,b);
    v->height = c + 1;

}

void AVLTree::printPreOrder() const
{
    preOrder(root);
}


void AVLTree::preOrder(Node* pre) const
{
    if(pre != NULL)
    {
        std::cout << " " << pre->data << " ";
        preOrder(pre->left);
        preOrder(pre->right);
    }
}

Node* AVLTree::getRoot()
{
    return root;
}

void AVLTree::print(Node *node, int level)
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

