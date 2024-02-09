#include <iostream>
#include <limits.h>
using namespace std;

template<typename T>
struct List
{
public:
	void push_back(T data);
	int GetSize() { return Size; }

	T& operator[](const int index);


	List();
private:

	template<typename T>
	struct Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;

};

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = head;
	int counter = 0;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;

		current = current->pNext;
		counter++;
	}
}

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
struct Stack 
{
public:
	void Push(T data);
	T Pop();
	T Front();
	bool Empty();
	int GetSize() { return Size; }

	Stack();

private:
	template<typename T>
	struct Node
	{
	public:

		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = NULL)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	int Size;
};

template<typename T>
void Stack<T>::Push(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* newHead = new Node<T>(data, head);
		head = newHead;
	}
	Size++;
}

template<typename T>
T Stack<T>::Pop()
{
	T temp = head->data;
	head = head->pNext;
	Size--;
	return temp;
}

template<typename T>
T Stack<T>::Front()
{
	return head->data;
}

template<typename T>
bool Stack<T>::Empty()
{
	if (Size == 0) return true;
}

template<typename T>
Stack<T>::Stack()
{
	head = NULL;
	Size = 0;
}


template<typename T>
struct Queue
{
public:
	void Push(T data);
	T Pop();
	int GetSize() { return Size; }

	Queue();
private:

	template<typename T>
	struct Node 
	{
	public: 
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = NULL)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T>* head;
	int Size;
};

template<typename T>
void Queue<T>::Push(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;

		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T Queue<T>::Pop()
{
	T data = head->data;
	Node<T>* temp = head;
	head = temp->pNext;
	
	delete temp;
	Size--;
	
	return data;
}

template<typename T>
Queue<T>::Queue()
{
	head = NULL;
	Size = 0;
}

template<typename T>
struct PriorityQueue 
{
public:
	void Push(T data, int key);
	int GetSize() { return nSize; }
	T Pop();
	bool Empty();
	PriorityQueue();
private:
	
	template<typename T>
	struct Node 
	{
		Node* pNext;
		Node* pPrevious;
		T data;
		int key;

		Node(T data = T(),int key = 0, Node* pNext = NULL, Node* pPrevious = NULL) 
		{
			this->data = data;
			this->pNext = pNext;
			if (key < 0) { this->key = 0; }
			this->key = key;
			this->pPrevious = pPrevious;
		}
	};
	Node<T>* head;
	int nSize;
};
template<typename T>
PriorityQueue<T>::PriorityQueue() { head = NULL; nSize = 0; }

template<typename T>
void PriorityQueue<T>::Push(T data, int key)
{
	if (head == NULL)
	{
		head = new Node<T>(data, key);
	}
	else
	{
		Node<T>* current = head;
		while (current->pNext != NULL)
		{
			Node<T>* tmp = current;     // 5 6 7 8
			current = current->pNext;            
 			current->pPrevious = tmp;
		}
		current->pNext = new Node<T>(data, key);
		current->pNext->pPrevious = current;
	}
	nSize++;
}

template<typename T>
T PriorityQueue<T>::Pop()
{
	if (nSize == 0) { return T(); }
	Node<T>* current = head;
	Node<T>* popItem = current;

	while (current != NULL)           
	{
		if (current->key < popItem->key)
		{
			popItem = current;
		}
		current = current->pNext;
	}
	                                     
	T tmpData = popItem->data;    
	
	if (popItem->pPrevious != NULL)
	{
		popItem->pPrevious->pNext = popItem->pNext;   
		if(popItem->pNext)
			popItem->pNext->pPrevious = popItem->pPrevious;	 // hello sun robot man river 
	}
	else
	{
		head = popItem->pNext;
		if (head)
			head->pPrevious = NULL;
	}

	delete popItem;
	nSize--;

	return tmpData;
}

template<typename T>
bool PriorityQueue<T>::Empty()
{
	if (nSize == 0) return true;
	else return false;
}


int main()
{
	//---- List-----

	/*List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(12);
	lst.push_back(7);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}*/

	//---- Stack-----

	/*Stack<int> stack;
	stack.Push(5);
	stack.Push(12);
	stack.Push(10);
	stack.Push(7);
	stack.Push(11);
	stack.Push(20);

	cout << endl;
	cout << stack.Front() << endl;
	cout << "Size: " << stack.GetSize();

	stack.Pop();
	stack.Pop();
	stack.Pop();

	cout << endl;
	cout << stack.Front() << endl;
	cout << "Size: " << stack.GetSize();*/


	//---- Queue-----

	/*Queue<int> queue;
	queue.Push(10);      
	queue.Push(12); 
	queue.Push(15);

	cout << queue.Pop() << endl;  
	cout << queue.Pop() << endl;  

	queue.Push(25); 
	queue.Push(30); 

	cout << queue.Pop() << endl;*/


	//---- PriorityQueue-----

	PriorityQueue<string> priorityQueue;
	priorityQueue.Push("hello", 5);
	priorityQueue.Push("sun", 3);
	priorityQueue.Push("robot", 18);
	priorityQueue.Push("man", 5);
	priorityQueue.Push("river", 5);

	cout << "Size: " << priorityQueue.GetSize() << endl;

	cout << priorityQueue.Pop() << endl;
	cout << priorityQueue.Pop() << endl;
	cout << priorityQueue.Pop() << endl;
	cout << priorityQueue.Pop() << endl;
	cout << priorityQueue.Pop() << endl;
	cout << priorityQueue.Pop() << endl;
	



}


