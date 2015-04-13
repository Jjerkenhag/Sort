#ifndef KO_H
#define KO_H

template<typename T>
class Node
{
public:
	T data;
	Node<T> *link;
};

template <typename T>
class Ko
{
private:
	Node<T> *first;
	Node<T> *last;
	int size;
public:
	void add(const T& data);
	T pop();
	Ko();
	virtual ~Ko();
	int getNrOfElements();
};

template <typename T>
Ko<T>::Ko()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

template <typename T>
void Ko<T>::add(const T& data)
{
	Node<T> *temp = new Node<T>;
	temp->data = data;
	temp->link = nullptr;
	if (first == nullptr)
		first = temp;
	else
		last->link = temp;
	last = temp;
	size++;
}



template <typename T>
T Ko<T>::pop()
{
	T data = first->data;
	Node<T> *temp = first;
	first = first->link;
	if (!(temp == nullptr))
	delete temp;
	size--;
	return data;
}

template <typename T>
int Ko<T>::getNrOfElements()
{
	return size;
}

template <typename T>
Ko<T>::~Ko()
{
	Node<T> *temp;
	while (!(first == nullptr))
	{
		temp = first;
		first = first->link;
		delete temp;
	}
}




#endif
