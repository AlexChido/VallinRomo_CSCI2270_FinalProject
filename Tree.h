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
        Tree(int);
        void flipcoin(); //finished
        bool forceflip();
        void allPossibilities(Node *); //finished
        void probability(int head, int tail);
        void initializeAllPoss(Node*); //finished helper function
        void printPastFlips(); //finished
        void reset(); //finished
        void printCounter();
        void compareProbabilities(int);
        void undoFlip();
        int Probabilities;
        virtual ~Tree();
    protected:
    private:
        int counter;
        Node *tracker;
        Node *root;

};
//Sync test

#endif // TREE_H
