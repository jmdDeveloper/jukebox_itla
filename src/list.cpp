#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;
List::List(): _first(NULL), _actual(NULL), _last(NULL), _repeat(0)
{
	/*here we inicialize the variable 
	
	note: autoPlay is 0 (zero) by default that mean is off
	
	*/
}
void List::add(Music* music)
{
	if(!_first)//if is empty the List
	{
		_first = music;
		_last = music;
		_actual = music;
		cout<<"\n\t\t Music added successfull...!!!\n\n";
		return ;
	}
	
	Music* aux = _last; //this is an auxilar variable to save the value of the before of the last one finally
	_last->_next = music;
	_last = music;
	_last->_before = aux;
	
	cout<<"\n\t\t Music added successfull...!!!\n\n";	
}

void List::remove(int index)
{
	if(index==1)//if is the first to errase
	{
		
		if(_first->getNext())//if there is a second
		{
			_first->_next->_before = NULL;
	        _first = _first->_next; // this is because the first doesn't have a before cause that the before of the first is NULL.
		       /*Other way
			        _first = _first->_next;
				    _first->_before = NULL;
				*/
		}else{//if only there is one '_first'
			_first = NULL;
		}
		
		cout<<"\n\t Music erased successfull...!!!\n";
		return ;// dont continue
	}
	
	Music* candidate = _first;
	Music* bCandidate = _first;
	
	for(int i=1; candidate && i<=index; i++, bCandidate = candidate, candidate = candidate->_next )
	{
		
		if(index==i)//if is the one music looked
		{
			cout<<endl<<"\t Music '"<<candidate->_title<<"' erased successfull...!!!"<<endl<<endl;
			bCandidate->_next = candidate->_next;
			cout<<"\n \t arrive A\n";
				
			if(candidate->getNext())
			{
			   candidate->_next->_before = bCandidate;
			   	cout<<"\n \t arrive B\n";
			}
			cout<<"\n\t Music erased successfull...!!!\n";			
			return ;//dont continue
		}	
	}
	 cout<<endl<<"\n \t Music not found."<<endl<<endl;
	
}//end of remove


void List::setActual(Music* actualMusic)
{
	if(actualMusic)//if is valid, it say, not NULL
	{
		_actual = actualMusic;
	}
}

bool List::repeatOn()
{ 
	return _repeat == 1; //see methods contructor for info about autoPlay 
}
void List::setRepeat(int status)
{
	_repeat = status; // we change the status of the autoPlay
	
	if(_repeat==1)
	{
		cout<<"\n\t Status Changed->  Repeat: ON\n\n";
	}else{
		cout<<"\n\t Status Changed->  Repeat: OFF\n\n";
	}
}

List::~List()
{
}
