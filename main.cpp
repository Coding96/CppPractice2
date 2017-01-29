/*
 * Basic pangolins game
 */

/* 
 * File:   main.cpp
 * Author: Edward
 *
 * Created on 07 January 2017, 22:43
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>

struct node
{
    int Type; //type is 0 for question and 1 for answer
    char Data[250];
    struct node *yes;
    struct node *no;
};

/*
 * 
 */
using namespace std;

struct node *topNode = (node*) malloc(sizeof (topNode));

//Our Function Declarations
void FreeRecur(struct node *inode);
void FreeTree();

int main(int argc, char** argv)
{
    //initial set up
    topNode->Type = 0; //top node is always a question
    strcpy(topNode->Data, "Is it Human?");
    struct node *allYes = (node*) malloc(sizeof (allYes));
    struct node *allNo = (node*) malloc(sizeof (allNo));

    allYes->Type = 1;
    strcpy(allYes->Data, "you only answered yes");
    allYes->no = NULL;
    allYes->yes = NULL;
    allNo->Type = 1;
    strcpy(allNo->Data, "you only answered no");
    allNo->no = NULL;
    allNo->yes = NULL;

    topNode->no = allNo;
    topNode->yes = allYes;


    //read in from file if there is one

    //begin the game loop
    int gameCompleted = 0;
    struct node *currentNode = topNode;
    char answer[250];
    while (gameCompleted == 0)
    {
        if (currentNode->Type == 1)
        {
            //if we are at answer node
            cout << currentNode->Data << "?\n";
            cin >> answer;
            if (strcmp(answer, "no") == 0)
            {

            }
            else
            {
                cout << "Woo I got it right";
                gameCompleted = 1;
            }
        }
        else
        {
            //if we are at a question node
            cout << currentNode->Data << "\n";
            cin >> answer;

            if (strcmp(answer, "yes") == 0)
            {
                currentNode = currentNode->yes;
            }
            else if (strcmp(answer, "no") == 0)
            {
                currentNode = currentNode->no;
            }
            else
            {
                cout << "I'm sorry i didn't understand that\n";
            }
        }
    }

    FreeTree();
    return (0);


}

void FreeRecur(struct node *inode)
{
    if (inode->Type == 0)
    {
        FreeRecur(inode->yes);
        FreeRecur(inode->no);
    }
    free(inode);
}

void FreeTree()
{
    FreeRecur(topNode);
}

