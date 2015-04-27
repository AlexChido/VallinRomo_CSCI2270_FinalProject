#ifndef TREE_H
#define TREE_H


struct Node{
    bool head;
    Node *right;
    Node *left;
    Node *parent;
    Node() {};

    Node(bool face){
    face=head;
    }
};

class Tree
{
    public:
        Tree();
        void buildTree(int,Node*); //1
        void flipcoin(); //finished //2
        void forceFlip(bool); //9
        void allPossibilities(Node *); //finished
        void probability(int head, int tail);
        void initializeAllPoss(Node*); //finished helper function
        void printPastFlips(); //finished
        void reset(); //finished
        void printCounter();
        void compareProbabilities(int);
        void undoFlip();
        int countFlips(Node*);
        int Probabilities;
        virtual ~Tree();
    protected:
    private:
        int counters;
        Node *tracker;
        Node *counter;
        Node *root;

};
//Sync test

#endif // TREE_H
