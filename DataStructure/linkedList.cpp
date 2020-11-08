#include <iostream>

struct node
{
	int data;
	node* next;
};

class List
{
	node* head;
	node* tail;

	node* createNode(int data, node* next = nullptr)
	{
		node* temp = new node;
		temp->data = data;
		temp->next = next;

		return temp;
	}

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	void push_back(int data)
	{
		if (!head)
		{
			head = createNode(data);
			tail = head;
		}
		else
		{
			tail->next = createNode(data);
			tail = tail->next;
		}
	}

	void push_front(int data)
	{
		if (!head)
		{
			head = createNode(data);
			tail = head;
		}
		else
		{
			head = createNode(data, head);
		}
	}

	void pop()
	{
		if (!head)
			return;

		if (head == tail)
		{
			head = nullptr;
			delete head;
			return;
		}

		node* current = head;

		while (current->next != tail)
		{
			current = current->next;
		}

		delete tail;
		tail = current;
		tail->next = nullptr;
	}

	void pop_front()
	{
		if (!head)
			return;

		if (head == tail)
		{
			head = nullptr;
			delete head;
			return;
		}

		node* temp = head->next;
		delete head;
		head = temp;

	}

	void print()
	{
		for (node* current = head; current != nullptr; current = current->next)
		{
			std::cout << current->data << " ";
		}
	}

	~List()
	{
		node* current = head->next;
		node* prev = head;

		while (!prev)
		{
			delete prev;

			prev = current;
			current = current->next;
		}
	}
};


int main()
{
	
	return 0;
}