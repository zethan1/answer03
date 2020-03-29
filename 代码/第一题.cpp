/**
 * @Author:zeng junbo
 * @creat:2020/3/29
 */

#include<iostream>
#include<assert.h>
/*
template<typename T>
struct Node
{
	T data;
	Node<T> *next;
};
template<typename T>
class queue
{
private:
	Node<T> *last;
public:
	queue();
	void enqueue(T data);
	T dequeue();
	void prin();
};
template<typename T>
queue<T>::queue()
{
	last = NULL;
}
template<typename T>
void queue<T>::enqueue(T data)
{
	Node<T> *s = new Node<T>;
	s->data = data;
	if (last == NULL) s->next = s;
	else
	{
		s->next = last->next;
		last->next = s;
	}
	last = s;
}
template<typename T>
T queue<T>::dequeue()
{
	//if (last == NULL) return -1;
	assert(last != NULL);
	Node<T> *s = last->next;
	int num = s->data;
	last->next = s->next;
	delete s;
	return num;
}
template<typename T>
void queue<T>::prin()
{
	int num = 5;
	for (int i = 0; i < num; i++)
	{
		int n = last->data;
		printf("%d ", n);
		last = last->next;
	}
}
void main_1()
{
	queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	//q.prin();
	system("pause");
}
*/