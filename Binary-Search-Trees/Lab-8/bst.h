
#ifndef _BST_H_
#define _BST_H_

#include "bintree.h"

namespace LAB_08_ALUEBKE
{

template <typename T>
class bst
{
public:
    bst();
    // postcondition: empty bst has been created
    ~bst();
    // postcondition: all dynamic memory allocated to bst
    //   has been deallocated
    bst(const bst<T>& t);
    // postcondition: copy of t has been made
    bst<T>& operator==(const bst<T>& t);
    // postcondition: t has been assigned to current object
    unsigned int size() const;
    // postcondition: number of elements in the current bst
    //   has been returned
    bool is_empty() const;
    // postcondition: returned whether current bst is empty
    void insert(const T& item);
    // postcondition: item is in the current bst
    void remove(const T& item);
    // postcondition: item is not in the current bst
	//void print_bst(T& t);

    bool contains(const T& item);
    // postcondition: has returned whether item is in the
    //   current bst
    template <typename Process, typename U>
    friend void inorder(Process f, const bst<U>& t);
    // postcondition: f has been executed at every node during
    // an inorder traversal
    template <typename Process, typename U>
    friend void preorder(Process f, const bst<U>& t);
    // postcondition: f has been executed at every node during
    // a preorder traversal
    template <typename Process, typename U>
    friend void postorder(Process f, const bst<U>& t);
    // postcondition: f has been executed at every node during
    // a postorder traversal

private:
    binary_tree_node<T>* root;
    unsigned int count;
};

}

#include "bst.template"

#endif // _BST_H_
