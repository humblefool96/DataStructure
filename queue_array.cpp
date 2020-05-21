#include <iostream>
using namespace std;
#define MAX_SIZE 101

class Queue {
    private:
        int que[MAX_SIZE];
        int front, rear;
    public:
        Queue() {
            front = rear = -1;
        }
        bool isEmpty();
        bool isFull();
        void enqueue(int data);
        void dequeue();
        int Front();
        void print();
};

bool Queue::isFull() {
    return rear == MAX_SIZE - 1;
}

bool Queue::isEmpty() {
    return (front == -1 && rear == -1);
}

void Queue::enqueue(int data) {
    if (rear >= MAX_SIZE - 1) {
        cout << "queue overflow" << "\n";
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    que[rear++] = data;
    cout << "element inserted is: " << data << "\n";
}

void Queue::dequeue () {
    if (isEmpty()) {
        cout << "queue underflow" << "\n";
        return;
    }
    if (front == rear) {
        rear = front = -1;
    }
    int temp = que[front];
    front--;
    cout << "dequeued element is: " << temp << "\n";
}

int Queue::Front () {
    if (isEmpty()) {
        cout << "queue underflow" << "\n";
        return -1;
    }
    return que[front];
}

void Queue::print() {
    cout << "Printing queue" << "\n";
    for (int i = 0; i < rear; i++) {
        cout << que[i] << " ";
    }
    cout << "\n";
}

int main() {
    Queue *q = new Queue();
    q->enqueue(5);
    q->enqueue(2);
    q->enqueue(7);
    q->enqueue(3);
    q->enqueue(15);
    q->print();
    int f = q->Front();
    cout << "Front of queue is: " << f << "\n";
    q->dequeue();
    q->print();
    return 0;
}