CSCI2270 Final Project:

A) Project Summary:
The purpose of this project is to calculate probabilities when playing the game of flipping a coin. It is easy to calculate probability of getting 2 heads for example, but what about the probability of getting in total 2 heads and 3 tails after you got 2 tails already, not easy right? Well this program will help solve those kind of problems. To archive this we use a binary tree that we can transverse to get this probabilities. 

B) How To Run:
This program is very straight forward and easy to use. When you start the program, you will see a menu similar to this one:

======Main Menu======
1. Build Probability Tree
2. Flip Coin
3. Calculate Probabilities
4. Reset Tree
5. Count Total Probabilities
6. Show Previous Flip Outcomes
7. Redo Flip
8. Show Number Of Flips
9. Force Flip
10. Compares Odd
11. Quit

To select an item, you must type the NUMBER AT THE LEFT OF THE ITEM, and then press ENTER or RETURN.

1.- Build Probability Tree:
 The first thing you will want to do in the program is type "1" and ENTER, in order to start your very own probability binary tree. 
The program will immediately ask you for the maximum number of tosses you are going to make, so it can build the tree as big as you want it to.
You will be asked with the prompt:

How many tosses do you want to make?
5

The number 5 is an example of the number you will give to the program to build the binary tree.
After doing this, you are now ready to count probabilities!

2.- Flip Coin:
In the most simple terms, it gives you either a "head" or a "tail".
Internally, the program uses a random number generator, and based on the number it gets, it traverses the tree either right or left (Which in this case;  right is Head, and left is Tails).
This is what you will want to do to start counting probabilities.
When the tree is full and cannot make another toss, it will simply say "No more tosses left".

3.- Calculate Probabilities:
By pressing "3" and ENTER, the program will ask you how many heads and tails will you like to have, and tells you the probability of getting that amount of heads and tails. If you already have done coin flips, it will count the flip of having a probability of 100% on whatever you got.
So for example, you did 2 coin flips that both ended up being Heads, and you want to calculate the probability of having 3 Heads; so because you already have 2, instead of looking for the chance of getting 3 Heads (which is 12.5%), it will only consider the possibility of getting that last Head that you need to reach the 3 heads that you wanted (which is 50%).

4.- Reset Tree:
When you run out of flips, and you want to make another experiment, or even if you simply want to restart your tosses;  you can always press "4" and ENTER. 
This will simply restart the tosses you made in the past, so you can make new tosses.
You will get a prompt saying:

You are about to reset the tree, do you want to continue? (y = yes, n = no)

At this point, you will either type "y" to confirm that you want to reset the tree, or "n" to cancel the action. 

5.- Count Total Probabilities:
This item will traverse inside the binary tree, and calculate how many probabilities you can have with all the possible outcomes.
For example, if you initialized the tree to toss the coin 2 times, you will have the following outcome:

0.25 chance of getting 2 heads, 0 tails
0.5 chance of getting 1 heads, 1 tails
0.25 chance of getting 2 tails, 0 tails

