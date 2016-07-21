#ifndef MYMENU_H
#define MYMENU_H

class MyMenu
{
	public:
		 MyMenu();
		~MyMenu();
		 void printMenu();
		 
	private:
		 void resetMenu();
		 void sPause();
		 bool validOption(int opction);
		 void callOpction (int opction);
		 void addMusic();
		 void deleteMusic();
		 void listMusic();
		 void showActualMusic();
		 void nextMusic();
		 void previewMusic();
		 void activeRepeat();		 		
};

#endif
