#pragma once
//#include <iostream>
//#include <windows.h>
//#include <new>
//11. 4
template <typename T> class stack{
private :
	struct NODE {
		T data;
		NODE *nextpoint;
	};

	NODE *SEED;

public :
	void push(T indata);
	T pop();
	void size();
	bool empty();
	void Clear();
	T peek();
	stack(){SEED = NULL;}
	~stack(){Clear();}
};

template <typename T>
void stack<T>::Clear(){
	while(SEED){
		NODE *Delete_Node;
		Delete_Node = SEED;
		SEED = Delete_Node->nextpoint;
		delete Delete_Node;
	}
}

template <typename T>
void stack<T>::push(const T indata){
	NODE *NewNode;
	
	NewNode = new NODE;
	NewNode->nextpoint = NULL;
	memcpy(&NewNode->data, &indata, sizeof(T));

	if(SEED)
	{
		NewNode->nextpoint = SEED;
		SEED = NewNode;
	}
	else
	{
		SEED = NewNode;
	}
}

template <typename T>
T stack<T>::pop(){
	T data;
	memset(&data,NULL,sizeof(T));
	if(SEED) {
		NODE *Delete_Node;
		Delete_Node = SEED;
		SEED = Delete_Node->nextpoint;
		memcpy(&data, &Delete_Node->data, sizeof(T));
		delete Delete_Node;
	}
	return data;
}

template <typename T>
T stack<T>::peek(){
	return SEED->data;
}

template <typename T>
void stack<T>::size(){
	int list = 0;		
	NODE *SIZE;
	SIZE = SEED;
	while(SIZE){
		list++;
		SIZE = SIZE->nextpoint;
		}
	cout<<"SIZE :  "<<list<<endl;
}




template <typename T>
bool stack<T>::empty(){
	if(SEED)	return TRUE;
	else		return FALSE;
}
