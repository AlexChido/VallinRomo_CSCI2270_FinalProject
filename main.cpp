#include <iostream>
#include "Tree.h"
#include <string>
#include <stdlib.h>

using namespace std;

void displayMenu(){
    cout<<"======Main Menu======\n";
    cout<<"1. Build Probability Tree\n";
    cout<<"2. Flip Coin\n";
    cout<<"3. Calculate Probabilities\n";
    cout<<"4. Reset Tree\n";
    cout<<"5. Count Total Possible Outcomes\n";
    cout<<"6. Show Previous Flip Outcomes\n";
    cout<<"7. Undo Flip\n";
    cout<<"8. Show Number Of Flips\n";
    cout<<"9. Force Flip\n";
    cout<<"10. Compare Odds\n";
    cout<<"11. Quit\n";
}



int main()
{
    string input;
    Tree *DadTree;//I don-t know if this is the correct way to inititallize the tree
    Node *root = new Node;

    displayMenu();
    while(getline(cin,input)){
        if(input == "1"){
            string num;
            cout<<"How many tosses do you want to make?\n";
            getline(cin, num);
            int number=atoi(num.c_str());
            DadTree=new Tree(number);
             //If we construct tree here I get an error in future functions
            displayMenu();
        }
        if(input == "2"){
            DadTree->flipcoin();
            displayMenu();
        }
        if(input == "3"){
            displayMenu();
        }
        if(input == "4"){
            DadTree->reset();
            displayMenu();
        }
        if(input == "5"){
            DadTree->initializeAllPoss();
            displayMenu();
        }
        if(input == "6"){
            DadTree->printPastFlips();
            displayMenu();
        }
        if(input == "7"){
            DadTree->undoFlip();
            displayMenu();
        }
        if(input == "8"){
            int flipCount = DadTree->countFlips(DadTree->root);
            cout<<"You have flipped "<<flipCount<<" times."<<endl;
            displayMenu();
        }
        if(input == "9"){
            bool isHeads;
            bool choosing = true;
            cout<<"Do you want it to be heads or tails? <H/T> "<<endl;
            while(choosing){
                cin>>input;
                if(input == "h"||input=="H"){
                    bool isHeads = true;
                    DadTree->forceFlip(isHeads);
                    break;
                }
                else if(input == "t"||input=="T"){
                    bool isHeads = false;
                    DadTree->forceFlip(isHeads);
                    break;
                }
                else{
                    cout<<"Invalid input, choose again. <H/T>"<<endl;
                }
            }
            displayMenu();
        }
        if(input == "10"){
            displayMenu();
        }
        if(input == "11"){
            //DadTree->DeleteAll(root);
            break;
        }
    }
    cout<<"Goodbye!\n";
    return 0;

}
