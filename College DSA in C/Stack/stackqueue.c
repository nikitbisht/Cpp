#include <stdio.h>
#include <stdbool.h>
#define max 30

int queue1[max];
int queue2[max];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
bool usingQueue1 = true;

void enqueue(int data) {
    if (usingQueue1) {
        if (rear1 == max - 1) {
            printf("Queue is Full\n");
            return;
        }
        if (front1 == -1) {
            front1 = 0;
        }
        rear1 = rear1 + 1;
        queue1[rear1] = data;
    } else {
        if (rear2 == max - 1) {
            printf("Queue is Full\n");
            return;
        }
        if (front2 == -1) {
            front2 = 0;
        }
        rear2 = rear2 + 1;
        queue2[rear2] = data;
    }
}

int dequeue() {
    if (usingQueue1) {
        if (front1 == -1) {
            printf("Queue is Empty\n");
            return -1;
        }
        int item = queue1[front1];
        if (front1 == rear1) {
            front1 = rear1 = -1;
        } else {
            front1 = front1 + 1;
        }
        return item;
    } else {
        if (front2 == -1) {
            printf("Queue is Empty\n");
            return -1;
        }
        int item = queue2[front2];
        if (front2 == rear2) {
            front2 = rear2 = -1;
        } else {
            front2 = front2 + 1;
        }
        return item;
    }
}

void push(int x) {
    enqueue(x);
    usingQueue1 = !usingQueue1; // Toggle between the two queues
}

int pop() {
    if (usingQueue1) {
        usingQueue1 = !usingQueue1; // Toggle before popping
        while (front1 != rear1) {
            enqueue(dequeue());
        }
        return dequeue();
    } else {
        usingQueue1 = !usingQueue1; // Toggle before popping
        while (front2 != rear2) {
            enqueue(dequeue());
        }
        return dequeue();
    }
}

void display() {
    if (usingQueue1) {
        if (front1 == -1) {
            printf("Stack is Empty\n");
            return;
        }
        for (int i = front1; i <= rear1; i++) {
            printf("%d ", queue1[i]);
        }
    } else {
        if (front2 == -1) {
            printf("Stack is Empty\n");
            return;
        }
        for (int i = front2; i <= rear2; i++) {
            printf("%d ", queue2[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, a;
    printf("Enter the number of elements you want to add in the stack: ");
    scanf("%d", &n);
    printf("Enter the stack elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        push(a);
    }
    printf("Popped elements from the stack: ");
    for (int i = 0; i < n; i++) {
        int popped_item = pop();
        if (popped_item != -1) {
            printf("%d ", popped_item);
        }
    }
    printf("\n");
    return 0;
}
