#include "music.h"
#include <cstdlib>

Music::Music(std::string title, std::string artist, double duration)
{
	//inicialazing the variables 
	_title = title;
	_artist = artist;
	_duration = duration;
	_next = NULL;
	_before = NULL;
}

Music::~Music()
{
}
