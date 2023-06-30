#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>

class Serial {

public:

Serial() {
	m_size = 0; 
	m_region = new int[m_size + 1];
}

~Serial() {
	delete [] m_region;
}

void push_back(int value) {
	int* new_region = new int[m_size + 1]; 	// новая область памяти
	for (int i = 0; i < m_size; ++i) {
		new_region[i] = m_region[i]; 		// копирование элементов
	}
	new_region[m_size] = value; // добавление нового элемента
	delete [] m_region; 		// удаление старой области
	m_region = new_region; 		// сохранение новой в мембер
	m_size += 1; 				// обновление информации о размере
}

void insert_begin(int value) {
	int* new_region = new int[m_size + 1]; 
	for (int i = 0; i < m_size; ++i) {
		new_region[i+1] = m_region[i]; 		
	}
	new_region[0] = value; 
	delete [] m_region; 		
	m_region = new_region; 		
	m_size += 1; 				
}

void insert_middle(int value) {
	int* new_region = new int[m_size + 1]; 	
	int middle = m_size/2; 
	for (int i = 0; i < m_size; ++i) {
		if(i<middle){
			new_region[i] = m_region[i];
		}
		else if(i==middle){
			new_region[middle] = value;
			new_region[i+1] = m_region[i];
		}
		else if(i>middle){
			new_region[i+1] = m_region[i];
		}
	}
	delete [] m_region; 		
	m_region = new_region; 		
	m_size += 1; 				
}

void erase(int value) {
	int* new_region = new int[m_size-1]; 
	for (int i = 0; i < m_size; ++i) {
		if(i<value){
			new_region[i] = m_region[i];
		}
		else{
			new_region[i] = m_region[i+1];
		}
		
	}
	delete [] m_region; 	
	m_region = new_region; 		
	m_size -= 1; 				
}

void erase(int first, int second, int third) {
	int* new_region = new int[m_size-3]; 
	int add = 0;

	for (int i = 0; i < m_size; ++i) {
		if (i == first || i == second || i == third){ ++add; }
		new_region[i-add] = m_region[i];
	}

	delete [] m_region; 	
	m_region = new_region; 		
	m_size -= 3; 				
}

void print() {
	for (int i = 0; i < m_size; ++i) {
		std::cout << m_region[i] << " ";
	}
	std::cout << std::endl;
}

int size() {
	return m_size; 
}

int &operator [] (int i)
{
	if (i<0 || i>m_size) {
	std::cout << "Boundary Error\n" << std::endl;
	exit (1);
	}
	return m_region[i];
}	

private:
	int m_size;
	int* m_region;
};



class List {
public:

struct Node {
	Node* next; // указатель на следующий элемент Node
	Node* prev; // указатель на предыдущий элемент Node
	int data; 	// пользовательские данные (хранимый объект)
};

List() {
	m_size = 0; 
	m_first = nullptr;
	m_last= nullptr;
}

~List() {
	Node* del = m_first->next; 
	for (int i = 0; i < m_size - 1 ; ++i) {
		delete del->prev;
		del = del->next;
	}
	delete m_last;
}

void push_back(int value) {
	Node* new_node = new Node{}; 	// создание нового узла

	if(m_size == 0)
	{
		new_node->prev = nullptr;
		new_node->next = nullptr; 
		new_node->data = value; 
		m_last = new_node; 	
		m_first = new_node; 
	}
	else
	{
		new_node->prev = m_last;	// предыдущим элементом станет последний
		new_node->next = nullptr; 	// следующего элемента пока нет
		new_node->data = value; 	// сохраняем пользовательские данные
		m_last->next = new_node;
		m_last = new_node; 			// обновляем указатель на последний
	}
	m_size += 1; 					// обновляем размер
}


void erase(int first, int second, int third) {
	Node* del = m_first;
	for (int i = 0; i < m_size; ++i) {
		if(i == (first-1) || i == (second-1) || i == (third-1))
		{
			Node* before = del->prev;
			Node* after = del->next;
			before->next = after; 
			after->prev = before; 
			delete del;
			--m_size;
			del = after; continue;
		}
		del = del->next;
	}
}

void insert_begin(int value) {
	Node* new_node = new Node{};
	new_node->data = value;
	new_node->next = m_first;
	new_node->prev = nullptr;
	m_first = new_node;
	m_size += 1; 
}

void insert_middle(int value) {
	Node* new_node = new Node{};
	Node* tmp = m_first;
	int middle = m_size/2;
	for (int i = 0; i < m_size; ++i) {
		if (i == (middle-1))
		{
			Node* after = tmp->next;
			after->prev = new_node;
			tmp->next = new_node;
			new_node->data = value;
			new_node->next = after;
			new_node->prev = tmp;
			m_size += 1; 
			return;
		}
		tmp = tmp->next;
	}
}

int &operator[] (int i)
{
	if (i<0 || i>m_size) {
		std::cout << "Boundary Error\n" << std::endl;
		exit (1);
	} 
	Node* tmp = m_first; 
	for (int j = 0; j < m_size; ++j) {
		if(j == i){
			break;
		}
		tmp = m_first->next;
	}
	return tmp->data;
}

void print() {
	Node* print = m_first;
	for (int i = 0; i < m_size; ++i) {
		std::cout << print->data << " ";
		print = print->next;
	}
	std::cout << std::endl;
}

int size() {
	return m_size; 
}

private:
	int m_size; 
	Node* m_first; 
	Node* m_last; 
};


int main() {

//1. создание объекта контейнера для хранения объектов типа int
	Serial first;
	List second;

// 2. добавление в контейнер десяти элементов (0, 1 … 9)
	for (int i=0 ; i < 10; ++i) {first.push_back(i);}
	for (int i=0 ; i < 10; ++i) {second.push_back(i);}

// 3. вывод содержимого контейнера на экран
	first.print();
	second.print();

// 4. вывод размера контейнера на экран
	std::cout << first.size() << std::endl;
	std::cout << second.size() << std::endl;

// 5. удаление третьего (по счёту), пятого и седьмого элементов
	first.erase(3,5,7);
	second.erase(3,5,7);

// 6. вывод содержимого контейнера на экран
	first.print();
	second.print();

// 7. добавление элемента 10 в начало контейнера
	first.insert_begin(10);
	second.insert_begin(10);

// 8. вывод содержимого контейнера на экран
	first.print();
	second.print();

// 9. добавление элемента 20 в середину контейнера
	first.insert_middle(20);
	second.insert_middle(20);

// 10. вывод содержимого контейнера на экран
	first.print();
	second.print();

// 11. добавление элемента 30 в конец контейнера
	first.push_back(30);
	second.push_back(30);

// 12. вывод содержимого контейнера на экран
	first.print();
	second.print();
	
	return 0;
}