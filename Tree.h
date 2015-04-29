#ifndef TREE_H
#define TREE_H
#include <vector>

using namespace std;

struct Node{
    bool head;
    Node *right;
    Node *left;
    Node *parent;
};

class Tree
{
    public:
        Tree(int);
        void buildTree(Node*, int); //1
        void flipcoin(); //finished //2
        void forceFlip(bool); //9
        int allPossibilities(Node*); //finished
        void probability(int head, int tail);
        void initializeAllPoss(); //finished helper function
        void printPastFlips(); //finished
        void reset(); //finished
        void printCounter();
        void compareProbabilities(double);
        void undoFlip();
        void countFlips();
        int Probabilities;
        Node *root=new Node;
        Node *tracker;
        void DeleteAll(Node*);
        void printTree(Node*, int);
        virtual ~Tree();
        int flipCounter = 0;
    protected:
    private:
        //oid addCount();
        int numOfHeads=0;
        int numOfTails=0;
        bool prevFlipWasHeads;
        int counters;
        vector <int> Paschal(int);
        int height();
        int sizer;
        Node *counter;

};
//Sync test

#endif // TREE_H
