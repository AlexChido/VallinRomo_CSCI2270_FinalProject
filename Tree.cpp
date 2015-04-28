#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

Tree::Tree(int sizer)
{
    Node *root=new Node;
    root->parent=NULL;
    root->left=NULL;
    root->right=NULL;
    Node *x=root;
    for(int i=0; i<sizer; i++){
        buildTree(x->right);
        buildTree(x->left);
    }
}


void Tree::buildTree(Node *x){
    Node *leftChild=new Node;
    Node *rightChild=new Node;
    leftChild->left=NULL;
    leftChild->right=NULL;
    rightChild->left=NULL;
    rightChild->right=NULL;
    x->left=leftChild;
    x->right=rightChild;
    leftChild->parent=x;
    rightChild->parent=x;
}

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
counter=0;
allPossibilities(x);
}


int Tree::allPossibilities(Node *x){
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
    if(tracker->parent != NULL){
        tracker=tracker->parent;
        tracker->head = NULL;
        cout<<"Flip has been undone!"<<endl;
    }
    else{
        cout<<"You haven't flipped a coin yet."<<endl;
    }
}

int Tree::countFlips(Node * root){
    counter = root;
    int flipCount = 0;
    if(counter->head != NULL){
        flipCount++;
    }
    else{
        return flipCount;
    }

    while(counter->left != NULL ||counter->right != NULL){
        if(counter->left!=NULL){
            counter = counter->left;
            flipCount++;
        }
        else if(counter->right!=NULL){
            counter = counter->right;
            flipCount++;
        }
        else{
            return flipCount;
        }
    }
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

void Tree::probability(int head, int tail){
    int existingHeads=0;
    int existingTails=0;
    int futureHeads=0;
    int futureTails=0;
    Node *x=tracker;
    while (x!=root){
        if (x->head==true)
            existingHeads++;
        else
            existingTails++;
        x=x->parent;
    }
    if(existingHeads==head&&existingTails==tail){
        cout<<"100% probability of "<<head<<"heads and "<<tail<<"tails"<<endl;
        return;
    }
    else{
       head-=existingHeads;
       tail-=existingTails;
       int possibilities= Tree::allPossibilities(tracker);
        int height=Tree::height();
        if(head+tail>height||head+tail<height){
            cout<<"0% probability"<<endl;
            return;
        }
        else{
            vector <int> P=Tree::Paschal(height);
            int paths=P[P.size()-head];
            cout<<(paths/possibilities)<<"% chance"<<endl;
        }
    }
}

int Tree::height(){
    counters=0;
    if(tracker->right!=NULL)
        counter=tracker->right;
    else
        return 0;
    while(counter->right!=NULL){
        counters++;
        counter=counter->right;
    }
return counters;
}

vector <int> Tree::Paschal(int height){
    vector <int> P;
    for (int i = 0; i < height; i++)
    {
        int val = 1;
        for (int k = 0; k <= i; k++)
        {
            P.push_back(val);
            val = val * (i - k) / (k + 1);
        }
    }
    return P;
}
