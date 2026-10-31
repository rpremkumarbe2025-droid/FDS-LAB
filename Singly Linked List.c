
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void prepend(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) return;

    newnode->data = data;
    newnode->next = head;
    head = newnode;

    printf("Data prepended: %d\n", data);
}

void append(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) return;

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Data appended: %d\n", data);
}

void display() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insert(int data, int pos) {
    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 0) {
        prepend(data);
        return;
    }

    struct node *temp = head;

    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) return;

    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Data inserted: %d at position: %d\n", data, pos);
}

void search(int data) {
    struct node *temp = head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == data) {
            printf("Data found at position: %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Data not found\n");
}

void delete(int data) {
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Element deleted: %d\n", temp->data);
    free(temp);
}

int main() {
    append(10);
    append(20);
    append(30);

    display();

    prepend(40);
    display();

    delete(20);
    display();

    insert(50, 0);
    display();

    printf("Search element: 40\n");
    search(40);

    printf("List data:\n");
    display();

    return 0;
}
