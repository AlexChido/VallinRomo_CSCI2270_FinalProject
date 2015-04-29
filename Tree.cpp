#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stdio.h>

using namespace std;

/*
Function Prototype:
Tree::Tree(int)

Function Description:
This function initializes the Tree that we are going to use to calculates the probabilities. Initializes all important variables, and calls the buildTree function.

Example:
Tree *DadTree;
DadTree=new Tree(number);

Precondition:
There is no required precondition, because you just initialize the Tree

Post condition:
A new Tree object with the variable name of your choice will be made. size of the Tree is determinated, counters are set to 0, and we make a Tree with the number of layers equal to the size of the Tree.
*/

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
        return;
    }
}

void Tree::reset(){
    tracker=root;
    flipCounter = 0;
    numOfHeads = 0;
    numOfTails = 0;
}
//needs to be fixed
void Tree::printTree(Node* node, int indent=0){
     if(node != NULL) {
        cout<< node->head << " \n";
        if(node->left) printTree(node->left, indent+4);
        if(node->right) printTree(node->right, indent+4);
        /*if (indent) {
            std::cout << std::setw(indent) << ' ';
        }*/
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
            numOfHeads++;
            prevFlipWasHeads = true;
        }
        else{ //at the leaf
            cout<<"No more available flips"<<endl;
            return;
        }
    }
    else{ //tails
        if(tracker->left!=NULL){
            cout<<"Tails"<<endl;
            tracker=tracker->right;
            numOfTails++;
            prevFlipWasHeads = false;
        }
        else{ //at the leaf
            cout<<"No more available flips"<<endl;
            return;
        }
    }
    flipCounter++;
}

void Tree::initializeAllPoss(){
//helper function for allPossibilities
//new pointer so we don't lose track of the tracker pointer position
Node *x=tracker;
counters=0;
Probabilities=allPossibilities(x);
if(counters==1)
    counters=0;
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
    if(flipCounter==0){
        cout<<"You haven't flipped a coin yet."<<endl;
        return;
    }

    Node *x=tracker;
    queue <string> Outcomes;
    cout<<"  ";
    while(x!=root){
        if(x->head==true)
            cout<<"Head <- ";
        else
            cout<<"Tail <- ";
        x=x->parent;
    }
    cout<<endl;
}

void Tree::undoFlip(){
    if(tracker->parent != NULL){
        tracker=tracker->parent;
        //tracker->head = NULL;
        cout<<"Flip has been undone!"<<endl;
    }
    else{
        cout<<"You haven't flipped a coin yet."<<endl;
        return;
    }
    if(prevFlipWasHeads)
        numOfHeads--;
    else
        numOfTails--;

    flipCounter--;
}

void Tree::countFlips(){
    cout<<"You have flipped "<<flipCounter<<" times."<<endl;
    cout<<numOfHeads<<" were heads, "<<numOfTails<<" were tails."<<endl;
    //2
    //cout<<"wut"<<endl;
}

Tree::~Tree()
{
}

void Tree::forceFlip(bool isHeads){
    if (isHeads){ //heads
        if(tracker->left!=NULL){
            tracker=tracker->left;
            numOfHeads++;
            prevFlipWasHeads = true;
        }
        else //at the leaf
            cout<<"No more available flips"<<endl;
    }
    else{ //tails
        if(tracker->right!=NULL){
            tracker=tracker->right;
            numOfTails++;
            prevFlipWasHeads = false;
        }
        else //at the leaf
            cout<<"No more available flips"<<endl;
    }
    flipCounter++;
}

void Tree::probability(int head, int tail){
    int actualHeads = head - numOfHeads;
    int actualTails = tail - numOfTails;
    //Node *x=tracker;
    int h=Tree::height();
    cout<<"Height: "<<h<<endl;
    if((actualHeads+actualTails)!=h){
        cout<<"0% probability"<<endl;
        return;
        }

       Tree::initializeAllPoss();
       //cout<<"Prob: "<<Probabilities<<endl;
       vector <int> P=Tree::Paschal(h);
       double paths=P[P.size()-actualHeads];
       //cout<<"Path: "<<paths<<endl;
       double prob=(paths/Probabilities);
       cout<<(prob*100)<<" % chance of getting "<<
       actualHeads<<" more heads and "<<actualTails<<" more tails."<<endl;
}

int Tree::height(){
    counters=1;
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
    for(int i =0;i<P.size();i++){
        //cout<<P[i];
        //cout<<endl;
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


void Tree::compareProbabilities(double chanceR){
    if (chanceR > 100){
        cout<<"Nothing is that certain, young one."<<endl;
        return;
    }
    double chances[10];
    double bowling300 = (1.0/11500.0)*100;
    chances[0] = bowling300;
    double holeInOne = (1/5000.0)*100;
    chances[1] = holeInOne;
    double beingAstronaut = (1/13200000.0)*100;
    chances[2] = beingAstronaut;
    double murder = (1/2.0)*100;
    chances[3] = murder;
    double celebrityM = (1/3.0)*100;
    chances[4] = celebrityM;
    double hemmorrhoids = (1/25.0)*100;
    chances[5] = hemmorrhoids;
    double marriage = (1/1.3)*100;
    chances[6] = marriage;
    double victim = (1/20.0)*100;
    chances[7] = victim;
    double presHarvard = (1/3.58)*100;
    chances[8] = presHarvard;
    double beingAsian = (2.0/3.0)*100;
    chances[9] = beingAsian;

    double closestChance = 100;
    int chanceNum;
    string chanceMsg = "That is approximately the same chance of ";
    for(int i = 0; i<10;i++){
        double tempChance = fabs(chanceR-chances[i]);
        if(tempChance<closestChance){
            closestChance = tempChance;
            chanceNum = i;
        }
    }
    switch(chanceNum){
    case 0:
        cout<<chanceMsg<<"bowling a perfect 300 game."<<endl;
        break;
    case 1:
        cout<<chanceMsg<<"getting a hole in one."<<endl;
        break;
    case 2:
        cout<<chanceMsg<<"being an astronaut."<<endl;
        break;
    case 3:
        cout<<chanceMsg<<"getting away with murder."<<endl;
        break;
    case 4:
        cout<<chanceMsg<<"a celebrity marriage lasting forever."<<endl;
        break;
    case 5:
        cout<<chanceMsg<<"getting a hemorrhoid."<<endl;
    case 6:
        cout<<chanceMsg<<"a marriage lasting at least 15 years."<<endl;
        break;
    case 7:
        cout<<chanceMsg<<"being a victim of a serious crime."<<endl;
        break;
    case 8:
        cout<<chanceMsg<<"a president having gone to Harvard."<<endl;
        break;
    case 9:
        cout<<chanceMsg<<"being born Asian."<<endl;
        break;

    }

}
