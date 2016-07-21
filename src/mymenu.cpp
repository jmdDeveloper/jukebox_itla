#include "mymenu.h"
#include "list.h"
#include <iostream>
using namespace std;
MyMenu::MyMenu()
{
}
List* mList = new List();//mList mean MusicList

void MyMenu::addMusic()
{
	string title ="";
	string artist = "";
	double duration = 0.0;
	cout<<"\n \t\t Adding new music \n";
	cout<<" Please, entry the title: ";
	cin>>title;
	cout<<" Please, entry the artist: ";
	cin>>artist;
	cout<<" Please, entry the duration (ej. 4:34 => 4.34): ";
	cin>>duration;
	
	Music* newMusic = new Music(title,artist,duration);//creating the object of Music
	mList->add(newMusic);//adding the music to my list
	
}
void MyMenu::showActualMusic()
{
	
	Music* actual = mList->getActual();//getting the actual Music
	cout<<"\n\t The Actual Music playing is:\n";
	cout<<"\n Title: "<<actual->getTitle()<<"\n Artist: "<<actual->getArtist()<<"\n Duration:"<<actual->getDuration()<<endl<<endl;
}
void MyMenu::listMusic()
{
	if(mList->getFirst())//if the list is not 
	{
		Music* m = mList->getFirst();
		cout<<"\n \t\t All Music:\n";
		
		for(int i=1; m ; i++, m = m->getNext())//this is to travel the list
		{
			cout<<" "<<i<<". Title: "<<m->getTitle()<<"\n    Artist: "<<m->getArtist()<<"\n    Duration: "<<m->getDuration()<<"\n\n";
		}
		
	}else{
		cout<<"\n\t\t List of Music empty...!!!\n";
	}
	
}

void MyMenu::activeRepeat()
{
	int Opction;
	if(mList->repeatOn()){//if is on repeating
		cout<<"\n \t Now Repeat is: ON\n";
	}else{
		cout<<"\n \t Now Repeat is: OFF\n";
	}
	
	
	cout<<"\n\t Repeat Opctions: \n";
	cout<<"1. Repeat\n";
	cout<<"2. No repeat\n";
	cout<<"\t \n Select an opction: ";
	cin>>Opction;
	switch(Opction)
	{
		case 1:
			mList->setRepeat(1);
			break;
			
		case 2:
			mList->setRepeat(0);
			break;
		default: cout<<"\n\t Opction invalid.\n\n.";
	}
}

void MyMenu::nextMusic()
{
	if(mList->getFirst())//if there a music in the list
	{
		Music* actual = mList->getActual();
		
		if(actual->getNext())//if there is a one next of actual
		{
			mList->setActual(actual->getNext());// changinf the actual
			actual = mList->getActual();//getting the new actual
			
			cout<<"\t The next music is: \n";
			cout<<"\n Title: "<<actual->getTitle()<<"\n Artist: "<<actual->getArtist()<<"\n Duration:"<<actual->getDuration()<<endl<<endl;
		}else{
			
			if(mList->repeatOn())//if repeat is on
			{
				mList->setActual(mList->getFirst());//set _first like actual
				actual = mList->getActual();
				cout<<"\n\t Reapet-> ON: Repeating List...\n\n";
				cout<<"\t The next/first music is: \n";
			cout<<"\n Title: "<<actual->getTitle()<<"\n Artist: "<<actual->getArtist()<<"\n Duration:"<<actual->getDuration()<<endl<<endl;
			}else{
				cout<<"\n\t No more music in the List.\n \t Turn On repeat, to repeat all music.\n\n";
			}
		}
		
	}
	
	
	
	
	
}
void MyMenu::previewMusic()
{
	if(mList->getFirst())//if there is one music minimum
	{
		Music* actual = mList->getActual();//get the actual music
	
	     if(actual->getBefore())//if there is one before actual 
		 {
		 	actual = actual->getBefore();//new actual 
		 	mList->setActual(actual); //change the new actual
		 	cout<<"\t The preview music is: \n";
			cout<<"\n Title: "<<actual->getTitle()<<"\n Artist: "<<actual->getArtist()<<"\n Duration:"<<actual->getDuration()<<endl<<endl;
					 	
	     }else{
	     	cout<<"\n\t No preview Music found.\n";
	     }
	}else{
		cout<<"\n\t List of music empty.\n";
	}
	
}

void MyMenu::deleteMusic()
{
	listMusic();// show all music
	if(mList->getFirst())//if there is a one music mnimun
	{
		int opction;
		cout<<"\n\t Selecct one music to delete of the list: ";
		cin>>opction;
		mList->remove(opction);//deleting music
	}
}

void MyMenu::callOpction(int opction)
{
	switch(opction)
	{
		case 1:
			addMusic();
			break;
		case 2:
			listMusic();
			break;
		case 3:
			showActualMusic();
			break;
		case 4:
			nextMusic();
			break;
		case 5:
			previewMusic();
			break;
		case 6:
			activeRepeat();
			break;
		case 7:
			deleteMusic();
			break;
		case 8:
			cout<<"\n \t Trank you for use JMD software...!!! \n\n";
			sPause();
		break;
		default: cout<<" Default of the opction, try again.\n\n";
	}
	sPause();
}

void MyMenu::resetMenu()
{
	system("cls");//cleen the screen
}

void MyMenu::sPause()
{
	system("pause");//pause the system
}

bool MyMenu::validOption(int opction)
{
	if(opction >= 1 && opction <= 8)
	{
		return true;
	}else{
		cout<<"\n \t Option no valid, try again.\n\n";
		sPause();
		return false;
	}
}

void MyMenu::printMenu()
{
	int elecction;
	do
	{
		resetMenu();//clear screen
		//start- implement the menu
		cout << "\t\t \n Vellonera JMD\n" << endl;
		cout << "1. Add Music" << endl;
		cout << "2. See Musics "<< endl;
		cout << "3. Show actual Music" << endl;
		cout << "4. Next Music" << endl;
		cout << "5. Previws Music" << endl;
		cout << "6. Repeat Opctions" << endl;
		cout << "7. Remove" << endl;
		cout << "8. Exit" << endl;
		cout << "\nSelect an option => ";
		//end- implement the menu
		cin>>elecction;
		if(validOption(elecction))
		{
			callOpction(elecction);
		}
		
	}while(elecction!=8);
}

MyMenu::~MyMenu()
{
}
