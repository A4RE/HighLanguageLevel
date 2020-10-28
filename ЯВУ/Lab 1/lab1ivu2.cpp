#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BSTnode //Структура бинарного дерева
{
    char word[128], meaning[256];
    struct BSTnode* left, * right;
};

struct BSTnode* root = NULL;

struct BSTnode* createNode(char* word, char* meaning) {
    struct BSTnode* newnode;
    newnode = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    strcpy(newnode->word, word);
    strcpy(newnode->meaning, meaning);
    newnode->left = newnode->right = NULL;
    return newnode;
}

void insert(char* word, char* meaning) //Функция добавления слова
{
    struct BSTnode* parent = NULL, * current = NULL, * newnode = NULL;
    int res = 0;
    if (!root) {
        root = createNode(word, meaning);
        return;
    }
    for (current = root; current != NULL;
        current = (res > 0) ? current->right : current->left) 
    {
        res = strcmp(word, current->word);
        if (res == 0) {
            printf("Povtor!!\n");
            return;
        }
        parent = current;
    }
    newnode = createNode(word, meaning);
    res > 0 ? (parent->right = newnode) : (parent->left = newnode);
    return;
}



void findElement(char* str) {
    struct BSTnode* temp = NULL;
    int flag = 0, res = 0;
    if (root == NULL) {
        printf("Binarnoie Derevo Poiska ne rabotaet!!\n");
        return;
    }
    temp = root;
    while (temp) {
        if ((res = strcmp(temp->word, str)) == 0) {
            printf("Slovo   : %s", str);
            printf("Znachenie: %s", temp->meaning);
            flag = 1;
            break;
        }
        temp = (res > 0) ? temp->left : temp->right;
    }
    if (!flag)
        printf("Slovo ne naideno\n");
    return;
}


int main() //Функция главного меню
{
    int ch;
    char str[128], meaning[256];
    while (1) 
    {
        printf("\n1. Vvod\n");
        printf("2. Poisk\n");
        printf("3. Vihod\nVibor:");
        scanf("%d", &ch);
        getchar();
        switch (ch) {
        case 1:
            printf("Slovo:");
            fgets(str, 100, stdin);
            printf("Znachenie:");
            fgets(meaning, 256, stdin);
            insert(str, meaning);
            break;
        case 2:
            printf("Slovo dlia Poiska:");
            fgets(str, 100, stdin);
            findElement(str);
            break;
        case 3:
            exit(0);
        default:
            printf("Vvedena ne suhesvuyshaia optcia\n");
            break;
        }
    }
    return 0;
}