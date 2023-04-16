#pragma once
using namespace std;
#include <vector>

class linkedlist {

private:


public:


	struct node {

		int number;
		node* next;

	};

	
	node* head;

	linkedlist();




	void add( int x);
	void addMid(int x, int y);


	void remove(int x);

	void print();

	node* vectorLL(vector<int> const& v, linkedlist vec);

	int sumNode();


};






