#include "Main Menu.h"
int main()
{
	    iSetTimer(5, introChange);
		PlaySound("Sound//IntroSong.wav", NULL, SND_ASYNC);
	    iInitialize(1920, 1080, "Arrival");
	return 0;
}
