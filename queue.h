#pragma once
//#include <iostream>
//#include <windows.h>
//#include <new>
//#include "main.h"
//11. 4
template <typename T> class queue{
private :
	struct NODE {
		T data;
		NODE *nextpoint;
		NODE *backpoint;
	};

	NODE *SEED;
	NODE *END;

public :
	void push(T indata);
	void pop();
	void Clear();
	T peek();

	queue(){SEED = NULL;}
	~queue(){Clear();}

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
void queue<T>::push(T indata){
	NODE *NewNode = new NODE;
	NODE *End_back_Node = NULL;

	memcpy(&NewNode->data, &indata, sizeof(T));
	NewNode->backpoint = NULL;
	NewNode->nextpoint = NULL;

	if(SEED == NULL)	{	
		SEED = NewNode; 
		END	= NewNode;
	}
	else		//if(노드가 하나라도 있을 경우) 
	{
		End_back_Node = END;
		NewNode->backpoint = End_back_Node;
		End_back_Node->nextpoint = NewNode;
		END = NewNode;
	}
}

template <typename T>
T queue<T>::pop(){
	T data = NULL;
	if(END){
		NODE *Delete_Node;
		Delete_Node = END;
		END = Delete_Node->backpoint;
		memcpy(&data, &Delete_Node->data, sizeof(T));
		delete Delete_Node;
	}
	return data;
}

template <typename T>
T queue<T>::peek(){
	return END->data;
}