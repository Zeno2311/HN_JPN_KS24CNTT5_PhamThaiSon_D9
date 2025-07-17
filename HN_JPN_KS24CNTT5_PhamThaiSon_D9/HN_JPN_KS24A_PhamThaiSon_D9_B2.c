#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} Music;

typedef struct Node {
    Music music;
    struct Node *next;
} Node;

typedef struct StackNode {
    Music music;
    struct StackNode *next;
} StackNode;

Node *font = NULL;
Node *rear = NULL;
StackNode *top = NULL;
//
void deplayMenu() {
    printf("\n-----------MUSIC PLAYER-----------\n");
    printf("1. ADD\n");
    printf("2. PLAY NEXT\n");
    printf("3. PLAY PREVIOUS\n");
    printf("4. HISTORY\n");
    printf("5. EXIT\n");
    printf("\n Lua chon cua ban: ");
}

//
int queueNull() {
    return font == NULL;
}

void addMusic() {
    Music musicValue;
    printf("Ten hai hat: ");
    fgets(musicValue.name, 100, stdin);
    musicValue.name[strcspn(musicValue.name, "\n")] = 0;

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->music = musicValue;
    newNode->next = NULL;

    if (queueNull()) {
        font = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Them bai hat thanh cong\n");
}

int main() {
    int choice;
    do {
        deplayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Lua chon khong hop le\n");
        } while (choice != 5);
        return 0;
    }
}
