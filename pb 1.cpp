#include <iostream>
struct node
{
	int key;
	node* prev, * next;
};
struct lista
{
	node* head = nullptr, * tail = nullptr;
	int nrOfElements = 0;
	void print()
	{
		node* current = head;
		while (current)
		{
			std::cout << current->key << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
	void push_front(int val)
	{
		node* newNode = new node;
		newNode->key = val;
		newNode->prev = nullptr;
		newNode->next = head;
		if (head)
			head->prev = newNode;
		else tail = newNode;
		head = newNode;
		nrOfElements++;
	}
	void push_back(int val)
	{
		node* newNode = new node;
		newNode->key = val;
		if (!head) {
			head = newNode;
			tail = newNode;
			head->prev = nullptr;
			head->next = nullptr;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			tail->next = nullptr;
		}
		nrOfElements++;
	}
	void pop_front()
	{
		if (!head)
			return;
		node* toErase = head;
		head = head->next;
		if (head)
			head->prev = nullptr;
		else
			tail = nullptr;
		delete toErase;
		nrOfElements--;
	}
	void pop_back()
	{
		if (!tail)
			return;
		node* toErase = tail;
		tail = tail->prev;
		if (!tail)
			head = nullptr;
		else tail->next = nullptr;
		delete toErase;
	}
	node* find(int val)
	{
		if (!head)
			return nullptr;
		node* current = head;
		while (current != nullptr) {
			if (current->key == val)
				return current;
			current = current->next;
		}
		return nullptr;
	}
	void erase(node* Nod)
	{
		if (Nod == head)
		{
			pop_front();
			return;
		}
		if (Nod == tail)
		{
			pop_back();
			return;
		}
		else
		{
			Nod->prev->next = Nod->next;
			Nod->next->prev = Nod->prev;
			delete Nod;
		}
	}
	void remove(int val)
	{
		node* Nod = head;
		while (Nod->next != nullptr)
		{
			if (Nod->key == val)
			{
				node* toErase = Nod->next;
				erase(Nod);
				Nod = toErase;
			}
			else
				Nod = Nod->next;
		}
		if (Nod->key == val)
			pop_back();
	}
	void insert(node* Nod, int val)
	{
		node* current = new node;
		if (!head)
			return;
		if (Nod == head)
			push_front(val);
		else {
			node* current = head;
			while (current->next != Nod)
				current = current->next;
			node* toInsert = new node;
			current->next = toInsert;
			toInsert->next = Nod;
			toInsert->key = val;
		}
	}
	int empty()
	{
		if (head == nullptr && tail == nullptr)
			return 0;
		else return 1;
	}
	void clear()
	{
		if (!head)
			return;
		node* current = head;
		while (current->next != nullptr)
		{
			node* toErase = current->next;
			erase(current);
			current = toErase;
		}
		pop_back();
	}
	int size() {
		nrOfElements = 0;
		node* Nod = head;
		if (head)
		{
			nrOfElements++;
			while (Nod->next != nullptr) {
				nrOfElements++;
				Nod = Nod->next;
			}
		}
		return nrOfElements;
	}
};
int palindrom(lista L)
{
	int nr = 0;
	node* spreFata = L.head;
	node* spreSpate = L.tail;
	if (!L.head)
		return 0;
	if (L.size())
		while (spreFata->key == spreSpate->key && nr < L.size() / 2)
		{
			spreFata = spreFata->next;
			spreSpate = spreSpate->prev;
			nr++;
		}
	if (nr == L.size() / 2)
		return 1;
	else return 0;
}
int compare(lista L1, lista L2)
{
	int ok = 1;
	node* current1 = L1.head;
	node* current2 = L2.head;
	if (L1.head == nullptr && L2.head == nullptr)
		return 1;
	if (L1.size() == L2.size())
		while (current1->next != nullptr && current2->next != nullptr && ok == 1)
		{
			if (current1->key != current2->key)
				ok = 0;
			current1 = current1->next;
			current2 = current2->next;
		}
	if (current1->key != current2->key)
		ok = 0;
	if (ok == 1)
		return 1;
	else return 0;
}
int main()
{
	lista L1, L2;
	int nr1, el1;
	int nr2, el2;
	int number;
	int numar;
	int valoare;
	std::cin >> number;
	while (number != 0)
	{
		switch (number) {
		case 1://push_front
			std::cin >> nr1;
			for (int index = 0; index < nr1; index++)
			{
				std::cin >> el1;
				L1.push_front(el1);
			}
			L1.print();
			break;
		case 2://push_back
			std::cin >> nr1;
			for (int index = 0; index < nr1; index++)
			{
				std::cin >> el1;
				L1.push_back(el1);
			}
			L1.print();
			break;
		case 3://pop_front
			L1.pop_front();
			L1.print();
			break;
		case 4://pop_back
			L1.pop_back();
			L1.print();
			break;
		case 5://erase
			std::cin >> numar;
			L1.erase(L1.find(numar));
			L1.print();
			break;
		case 6://remove
			std::cin >> numar;
			L1.remove(numar);
			L1.print();
			break;
		case 7://insert
			std::cin >> numar;
			std::cin >> valoare;
			L1.insert(L1.find(numar), valoare);
			L1.print();
			break;
		case 8://clear
			L1.clear();
			break;
		case 9://size
			std::cout << L1.size();
			break;
		case 10:
			if (palindrom(L1) == true)std::cout << "este palindrom";
			else std::cout << "nu este palindrom";
			break;
		case 11:
			std::cout << "nr elem= ";
			std::cin >> nr2;
			for (int index = 0; index < nr2; index++)
			{
				std::cin >> el2;
				L2.push_back(el2);
			}
			if (compare(L1, L2) == true)std::cout << "sunt egale";
			else std::cout << "nu sunt egale";
			break;
		default:
			return 0;
			break;
		}
		std::cin >> number;
	}
}