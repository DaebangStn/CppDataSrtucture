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
	node* remove(int step); // 현재 노드가 삭제되면 이전 노드를 반환한다.
// 인자로 사용되는 step에는 양수, 음수가 포함될 수 있다.
	node* info(); // 총 노드의 길이, 모든 데이터를 cout으로 출력한다.
	int size(); // 총 노드의 길이를 출력한다.
	void kill();

	~node() {
		cout << "node killed" << endl;
	}
};
void Deleteleftover(node* leftover) {
	delete leftover;
}

#endif