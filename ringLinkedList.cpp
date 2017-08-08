#include <iostream>
#include "ringLinkedList.h"

using namespace std;
node::node(int length): data(0) {
	if (length > 1) {
		prev = NULL;
		next = new node(length - 1, this, this);
	}
	else if (length == 1) {
		prev = this, next = this;
	}
	else {
		cout << "길이가 0인 리스트는 생성될 수 없습니다." << endl;
	}
}
node::node(int length, node* head, node* prev): data(0) {
	this->prev = prev;
	if (length > 1) {
		this->next = new node(length - 1, head, this);
	}
	else {
		this->next = head;
		prev->passtail(this);
	}
}
void node::passtail(node* tail) {
	if (this->prev != NULL) {
		prev->passtail(tail);
	}
	else {
		this->prev = tail;
	}
}
node* node::move(int step) {
	if (step>0) {
		return next->move(step - 1);
	}
	else if (step < 0) {
		return prev->move(step + 1);
	}
	else {
		return this;
	}
}
int node::read(int step) {
	if (step) {
		return next->read(step - 1);
	}
	else {
		return this->data;
	}
}
node* node::write(int step, int data) {
	this->move(step)->data = data;
	return this;
}
node* node::add(int step) {
	if (step) {
		this->move(step)->add(0);
	}
	else {
		node* next_temp = next;
		next = new node();
		next->prev = this;
		next->next = next_temp;
		next_temp->prev = next;
	}
	return this;
}
node* node::add(int step, int data) {
	this->add(step)->write(step, data);
	return this;
}
node* node::remove(int step) {
	if (this == next) {
		Deleteleftover(this);
		return (node*)NULL;
	}
	else {
		if (this != this->move(step)) {
			node* nodeTodelete = this->move(step);
			nodeTodelete->prev->next = nodeTodelete->next;
			nodeTodelete->next->prev = nodeTodelete->prev;
			delete nodeTodelete;
			return this;
		}
		else{
			return this->move(-1)->remove(1);
		}
	}
}
node* node::info() {
	int length = this->size();
	node* pointer = this;
	cout << "total length is " << length << endl << "the component is" << endl;
	for (int i = 0; i < length; i++) {
		cout <<pointer->data << " ";
		pointer = pointer->next;
	}
	cout << endl;
	return this;
}
int node::size() {
	int i=1;
	node* pointer = this;
	while (this != pointer->next) {
		pointer = pointer->next;
		i++;
	}
	return i;
}
void node::kill() {
	node* pointer = next;
	while (this != pointer) {
		node* pointer_temp = pointer->next;
		delete pointer;
		pointer = pointer_temp;
	}
	Deleteleftover(this);
}