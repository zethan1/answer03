/**
 * @Author:zeng junbo
 * @creat:2020/3/29
 */


#include<iostream>
#include<assert.h>
using namespace std;
template<typename T>
class queue
{
private:
	int first, last, size;
	T *a;
public:
	queue(int n)
	{
		size = n;
		//const int sizeofT = sizeof(T);
		//a = (T *)malloc(n*sizeofT);
		a = new T[n];
		first = last = 0;
		//cout << "first:" << first << " last:" << last << endl;
	}
	void enqueue(T data);
	T dequeue();
	void prin();
};
template<typename T>
void queue<T>::enqueue(T data)
{
	last = (last + 1) % size;
	//cout << "last:" << last << endl;
	assert(last != first);//////////////////////////////////////
	a[last] = data;
}
template<typename T>
T queue<T>::dequeue()
{
	assert(last != first);
	first = (first + 1) % size;
	return a[first];
}
template<typename T>
void queue<T>::prin()
{
	int length = (last - first + size) % size;
	int num = first;
	for (int i = 0; i < length; i++)
	{
		num = (num + 1) % size;
		cout << a[num] << " ";
	}
}
template<typename T>
class stack
{
private:
	int size, top;
	T *a;
public:
	stack(int n)
	{
		a = new T[n];
		top = -1;
		size = n;
	}
	void push(T data)
	{
		assert(top != size - 1);
		a[++top] = data;
	}
	T pop()
	{
		assert(top != -1);
		return a[top--];
	}
	void prin()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << a[i] << " ";
		}
	}
};
template<typename T>
void set(stack<T> s,int n)
{
	const int half_n = n / 2;
	queue<T> q(n+1);
	int data;
	for (int i = 0; i < n; i++)	//stack to queue
	{
		data = s.pop();
		q.enqueue(data);
	}
	for (int i = 0; i < n; i++) //queue_even to stack
	{

		if (i % 2 == 0)
		{
			data = q.dequeue();
			s.push(data);
		}
		else
		{
			data = q.dequeue();
			q.enqueue(data);
		}
	}
	for (int i = 0; i < half_n; i++) //stack_even to queue
	{
		data = s.pop();
		q.enqueue(data);
	}
	for (int i = 0; i < half_n; i++) //queue_odd to stack
	{
		data = q.dequeue();
		s.push(data);
	}
	for (int i = 0; i < half_n; i++) //stack_odd to queue
	{
		data = s.pop();
		q.enqueue(data);
	}
	for (int i = 0; i < half_n; i++) //queue_even to queue
	{
		data = q.dequeue();
		q.enqueue(data);
	}
	for (int i = 0; i < n; i++) //queue to stack
	{
		data = q.dequeue();
		s.push(data);
	}
}


void main()
{
	stack<int> s(10);
	for (int i = 1; i < 11; i++)
	{
		s.push(i);
	}
	s.prin();
	set(s, 10);
	cout << endl;
	s.prin();
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		int num = s.pop();
		cout << num << " ";
	}
	system("pause");
}

/*
void main_test_stack()
{
	stack<int> s(10);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
	s.prin();
	system("pause");
}

void main_test_queue()
{
	queue<int> q(9);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();
	q.prin();
	cout << endl << "ok" << endl;
	system("pause");
}
*/
