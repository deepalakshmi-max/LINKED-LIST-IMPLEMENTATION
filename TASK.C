#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Function declarations */
void insertBeg(int);
void insertMid(int, int);
void insertLast(int);
void deleteBeg(void);
void deleteMid(int);
void deleteLast(void);
void display(void);

/* Insert at beginning */
void insertBeg(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

/* Insert at middle (position) */
void insertMid(int value, int pos) {
    struct Node *newNode, *temp = head;
    int i;

    if (pos <= 1 || head == NULL) {
        insertBeg(value);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    for (i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Insert at last */
void insertLast(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Delete at beginning */
void deleteBeg() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

/* Delete at middle (position) */
void deleteMid(int pos) {
    struct Node *temp = head, *prev = NULL;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos <= 1) {
        deleteBeg();
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Delete at last */
void deleteLast() {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

/* Display list */
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle\n");
        printf("3. Insert at Last\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Middle\n");
        printf("6. Delete at Last\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeg(value);
                break;

            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertMid(value, pos);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertLast(value);
                break;

            case 4:
                deleteBeg();
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteMid(pos);
                break;

            case 6:
                deleteLast();
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
