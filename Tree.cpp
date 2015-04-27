#include "Tree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Tree::Tree(int number)
{
    //ctor

}

Tree::Tree()
{
    //2nd ctor

}
//checking merge capabilities

void Tree::flipcoin(){
//0 is Tails and 1 is Heads
//random number generator indicates heads or tails
int flip=rand() % 1+0;
if (flip==1) //heads
    if(tracker->left!=NULL)
        tracker=tracker->left;
    else //at the leaf
        cout<<"No more available flips"<<endl;
else //tails
    if(tracker->right!=NULL)
        tracker=tracker->right;
    else //at the leaf
        cout<<"No more available flips"<<endl;

}

void Tree::initializeAllPoss(Node *tracker){
//helper function for allPossibilities
//new pointer so we don't lose track of the tracker pointer position
Node *x=tracker;
allPossibilities(x);
counter=0;
}


void Tree::allPossibilities(Node *x){
//count the leaves of the subtree recursively
while(x->right!=NULL)
    allPossibilities(x->right);
while(x->left!=NULL)
    allPossibilities(x->left);
//count all leaves
if(x->left==NULL&&x->right==NULL)
    counter++;
}

void Tree::printPastFlips(){
    Node *x=tracker;
    while(x!=root){
        if(x->head==true)
            cout<<"Heads ";
        else
            cout<<"Tails ";
        x=x->parent;
    }
}

void Tree::undoFlip(){
tracker=tracker->parent;
}

Tree::~Tree()
{
    //dtor
}

void Tree::forceFlip(bool isHeads){
    if (isHeads) //heads
        if(tracker->left!=NULL)
            tracker=tracker->left;
        else //at the leaf
            cout<<"No more available flips"<<endl;
    else //tails
        if(tracker->right!=NULL)
            tracker=tracker->right;
        else //at the leaf
            cout<<"No more available flips"<<endl;

}
