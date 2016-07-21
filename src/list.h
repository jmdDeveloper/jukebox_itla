#ifndef LIST_H
#define LIST_H
#include <string>
#include "music.h"
class List
{
	public:
		List();
		~List();
		void add(Music* music);
		void remove(int index);
		void setActual(Music* actualMusic);
		bool repeatOn();
		void setRepeat(int status);
		Music* getFirst()   { return _first;  }
		Music* getActual()  { return _actual; }
		Music* getLast()    { return _last;	  }
	
	private:
		Music* _first;
		Music* _actual;
		Music* _last;
		int _repeat;
};

#endif
