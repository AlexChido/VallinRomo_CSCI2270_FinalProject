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
        int allPossibilities(Node *); //finished
        void probability(int head, int tail);
        void initializeAllPoss(Node*); //finished helper function
        void printPastFlips(); //finished
        void reset(); //finished
        void printCounter();
        void compareProbabilities(int);
        void undoFlip();
        int countFlips(Node*);
        int Probabilities;
        Node *root=new Node;
        void DeleteAll(Node*);
        void printTree(Node*, int);
        virtual ~Tree();
    protected:
    private:
        int counters;
        vector <int> Paschal(int);
        int height();
        Node *tracker;
        Node *counter;

};
//Sync test

#endif // TREE_H
