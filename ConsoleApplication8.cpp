#include <iostream>
#include <vector>
#include"compl.h"
using namespace std;

//geeksforgeeks was used for the references for a linked list
//I did not copy their code I studied from it

void insertAfter(vector<int>& v, int firstValue, int secondValue) {
    int temp=0;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == firstValue) {
            v.push_back(secondValue);
        }
    }

    

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == firstValue) {
            for (int j = temp; j < v.size(); j++) {

                if (v[j] == secondValue) {
                   //swapping twice
                    std::swap(v[j], v[i + 1]);
                    break;
                }

                temp++;


            }
        }
    }
}

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i]<<'\t';
}

linkedlist::linkedlist() {
    head = NULL;
}

void linkedlist::add(int x) {
    node* new_node = new node;
    new_node->number = x;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    }
    else {
        node* current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void linkedlist::addMid(int x, int y) {
    node* new_node = new node;
    new_node->number = y;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    }
    else {
        node* current_node = head;
        node* p = current_node;;
        while (current_node->number != x) {
            current_node = current_node->next;
        }
        p = current_node->next;
        current_node->next = new_node;
        while (current_node->number != y) {
            current_node = current_node->next;
        }
        current_node = p;
        new_node->next = current_node;
    }

}

void linkedlist::remove(int x) {
    if (head == NULL)
        cout << "The list is empty!" << endl;
    else {
        node* current_node = head;
        node* q = current_node;
        while (current_node->number != x) {
            q = current_node;
            current_node = current_node->next;

        }
        q->next = current_node->next;

        if (current_node == head) {
            head = head->next;
        }
    }


}

int linkedlist:: sumNode() {
    node* current_node = head;
    int sum = 0;
    while (current_node->next != NULL) {
        sum += current_node->number;
        current_node = current_node->next;
    }
    sum += current_node->number;

    return sum;
}

void linkedlist::print() {
    node* current_node = head;
    while (current_node != NULL) {
        std::cout << current_node->number << '\t';
        current_node = current_node->next;
    }
}

linkedlist::node* linkedlist::vectorLL(vector<int> const& v, linkedlist vec) {
    //node* new_head;
    for (int i = 0; i < v.size(); i++) {
        vec.add(v[i]);
    }

    vec.print();

    return head;
}

int main() {
    linkedlist l;
    linkedlist vec;
    //linkedlist adding
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(6);
    cout << "Normal linked list adding: ";
    l.print();
    //adding between elements
    cout << endl<< "Adding inbetween elements: ";
    l.addMid(4, 5);
    cout << endl;
    l.print();
    //linkedlist removing
    cout << endl<<"Removing elements: ";
    l.remove(2);
    cout << endl;
    l.print();
    l.remove(3);
    cout << endl;
    l.print();
    //sum of linkedlist nodes
    cout << endl;
    cout<<"The sum of the current nodes in the linkedlist is: "<<l.sumNode()<<endl;
    //creating a linkedlist from the vector c
    vector<int> c{9,8,7,6,5,4,3,2,1,0 };
    cout << "vector as linked list: ";
    vec.vectorLL(c, vec);
    vec.print();
    //insertAfter function
    cout << endl;
    vector<int> v = { 1,2,3,1,4,5,1 };
    insertAfter(v, 1, 0);
    cout << "After every 1 add a 0: ";
    printVector(v);
    return 0;
}
