#ifndef MUSIC_H
#define MUSIC_H
#include <string>

class Music
{
	public:
	   	 Music(std::string title, std::string artist, double duration);
		~Music();
		std::string getTitle()  { return _title;    }
		std::string getArtist() { return _artist;   }
		double getDuration()    { return _duration; }
		Music* getBefore()      { return _before;	}
		Music* getNext()        { return _next;	    }
		
	private:
		std::string _title;
		std::string _artist;
		double _duration; 
	    Music* _before;
	    Music* _next;
	    friend class List;
};

#endif
