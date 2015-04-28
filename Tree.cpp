#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;

Tree::Tree(int sze)
{
    root->parent=NULL;
    sizer=sze;
    counters=0;
    tracker=root;
    Tree::buildTree(root, 0);
}

void Tree::buildTree(Node *x, int current){
    if(current<sizer){
        Node *newHead=new Node;
        newHead->head=true;
        Node *newTail=new Node;
        newTail->head=false;
        x->left=newHead;
        x->right=newTail;
        newHead->parent=x;
        newHead->left=NULL;
        newHead->right=NULL;
        newTail->parent=x;
        newTail->left=NULL;
        newTail->right=NULL;
        current++;
        buildTree(newHead, current);
        buildTree(newTail, current);
    }
    else{
        //Tree::printTree(root, 0);
        return;
    }
}

void Tree::reset(){
    tracker=root;
}
//this is mainly for debugging the build tree, but we can use it as another function if we want
void Tree::printTree(Node* node, int indent=0){
    if(node != NULL) {
        if(node->right) {
            printTree(node->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< node->head << "\n ";
        if(node->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            printTree(node->left, indent+4);
        }
    }
}

void Tree::flipcoin(){
//0 is Tails and 1 is Heads
//random number generator indicates heads or tails
int flip=rand() % 2;
if (flip==1){ //heads
    if(tracker->right!=NULL){
        cout<<"Heads"<<endl;
        tracker=tracker->left;
    }
    else //at the leaf
        cout<<"No more available flips"<<endl;
}
else{ //tails
    if(tracker->left!=NULL){
        cout<<"Tails"<<endl;
        tracker=tracker->right;
    }
    else //at the leaf
        cout<<"No more available flips"<<endl;
}

}

void Tree::initializeAllPoss(){
//helper function for allPossibilities
//new pointer so we don't lose track of the tracker pointer position
Node *x=tracker;
counters=0;
int counters=allPossibilities(x);
if(counters==1)
    counters=0;
cout<<counters<<" total possible outcomes"<<endl;
}


int Tree::allPossibilities(Node *x){
//count the leaves of the subtree recursively
if(x->right!=NULL)
    allPossibilities(x->right);
if(x->left!=NULL)
    allPossibilities(x->left);
//count all leaves
else if(x->left==NULL&&x->right==NULL)
    counters++;
return counters;
}

void Tree::printPastFlips(){
    Node *x=tracker;
    queue <string> Outcomes;
    while(x!=root){
        if(x->head==true)
            cout<<"Head ";
        else
            cout<<"Tail ";
        x=x->parent;
    }
    cout<<endl;
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
}

void Tree::forceFlip(bool isHeads){
    if (isHeads){ //heads
        if(tracker->left!=NULL)
            tracker=tracker->left;
        else //at the leaf
            cout<<"No more available flips"<<endl;
    }
    else{ //tails
        if(tracker->right!=NULL)
            tracker=tracker->right;
        else //at the leaf
            cout<<"No more available flips"<<endl;
    }

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

void Tree::DeleteAll(Node *node){
    if(node->left!=NULL)
        DeleteAll(node->left);
    if(node->right!=NULL)
        DeleteAll(node->right);
    delete node;
}
