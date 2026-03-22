#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PlayerData{
    char *Name;
    char *UUID;
};

struct Node{
    struct PlayerData Data;
    struct Node *Next;
};

int main(){
    struct Node *Head = malloc(sizeof(struct Node));
    struct Node *Second = malloc(sizeof(struct Node));
    struct Node *Third = malloc(sizeof(struct Node));

    Head->Data.Name = malloc(20*sizeof(char));
    Head->Data.UUID = malloc(20*sizeof(char));
    Second->Data.Name = malloc(20*sizeof(char));
    Second->Data.UUID = malloc(20*sizeof(char));
    Third->Data.Name = malloc(20*sizeof(char));
    Third->Data.UUID = malloc(20*sizeof(char));

    Head->Next = Second;
    Second->Next = Third;
    Third->Next = NULL;

    strcpy(Head->Data.Name,"EndeeerMan");
    strcpy(Head->Data.UUID,"9849495644");
    strcpy(Second->Data.Name,"EndeeeeeerMan");
    strcpy(Second->Data.UUID,"85929284949");
    strcpy(Third->Data.Name,"wzh23x");
    strcpy(Third->Data.UUID,"84499949");

    struct Node *temp = Head;

    while(temp != NULL){
        printf("Name: %s UUID: %s\n",temp->Data.Name,temp->Data.UUID);

        free(temp->Data.Name);
        free(temp->Data.UUID);

        temp = temp->Next;
    }
    if(temp != NULL) free(temp);
}