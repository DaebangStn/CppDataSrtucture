#ifndef RINGLINKEDLIST_H
#define RINGLINKEDLIST_H
class node {
public:
	int data;
	node* next;
	node* prev;
	node(): data(0) {}
	node(int length);
	node(int length, node* head, node* prev);
	void passtail(node* tail);
	node* move(int step);
	int read(int step);
	node* write(int step, int data);
	node* add(int step);
	node* add(int step, int data);
	node* remove(int step); // ���� ��尡 �����Ǹ� ���� ��带 ��ȯ�Ѵ�.
// ���ڷ� ���Ǵ� step���� ���, ������ ���Ե� �� �ִ�.
	node* info(); // �� ����� ����, ��� �����͸� cout���� ����Ѵ�.
	int size(); // �� ����� ���̸� ����Ѵ�.
	void kill();

	~node() {
		cout << "node killed" << endl;
	}
};
void Deleteleftover(node* leftover) {
	delete leftover;
}

#endif