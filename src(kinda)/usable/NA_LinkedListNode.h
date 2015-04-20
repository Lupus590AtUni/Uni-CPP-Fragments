#pragma once
#include "NA_GlobalsAndIncludes.h"
template <class _template> class NA_LinkedListNode //http://www.cprogramming.com/tutorial/templates.html
{
private:
//	bool isClass<class>();
public:
	NA_LinkedListNode(void);
	~NA_LinkedListNode(void);

	//could be public but that would just mean gets and sets
	_template value;//what if this is a pointer? shouldn't we delete it? how do we check if we should delete it as this class does not know what the data is?
	NA_LinkedListNode* next;
};

template <class _template>NA_LinkedListNode<_template>::NA_LinkedListNode(void)
{
	//value = NULL; //until compiled, the node doesn't know what type value will be, this causes an issue with initalising it. ideally I would put a pointer check to init it (like for the delete below) - an easy fix would be to have a bool which is set by the code using the object if the value is a pointer that will need to be deleted, sounds a bit messy...
	next = NULL;
}


template <class _template>NA_LinkedListNode<_template>::~NA_LinkedListNode(void)
{
	//not needed for this project, but i would have liked to of been able to get this working
	//as the pusdo code suggest, it was ment to check if value was a pointer to dynamicly allocated memory and delete it if it was (calling delete on non-pointers caused a crash
	//Glenn Jenkins was helping me with this

	//if value is a pointer allocated memory
		//free the memory
	//std::is_fundamental


	if(next != NULL) delete next;
	//value=NULL;
	next=NULL;
}

//template <class _template>NA_LinkedListNode<_template>::isClass<class>()
//{
//}