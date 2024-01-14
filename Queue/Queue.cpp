#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue *queue = new Queue();
    cout << "Enter 1 to insert items to the queue." << endl;
    cout << "Enter 2 to remove an item from the queue." << endl;
    cout << "Enter 3 to get the front item from the queue." << endl;
    cout << "Enter 4 to print all of the existing items in the queue." << endl;
    cout << "Enter 5 to exist the application" << endl;
    while (true) {
        int option;
        cout << "Enter option: ";
        cin >> option;
        if (option == 5) {
            cout << "Thank you for using this application." << endl;
            break;
        } else if (option == 1) {
            int item;
            cout << "Enter item(item should be non-negative): ";
            cin >> item;
            queue->enqueue(item);
        } else if (option == 2) {
            int item = queue->dequeue();
            if (item != -99999) {
                cout << "Removed item is " << item << "." << endl;
            } else {
                cout << "Empty queue. No item has been removed." << endl;
            }
        } else if (option == 3) {
            int item = queue->getFront();
            if (item != -99999) {
                cout << "The front item is " << item << "." << endl;
            } else {
                cout << "The queue is currently empty." << endl;
            }
        } else if (option == 4) {
            queue->printQueue();
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    delete queue;
}