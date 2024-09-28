int bspeed = 10,ind;
struct bonus
{
	int bonx=1900;
	int bony;
}b;
bool collitionbonus()
{
	if (b.bonx <= playerx + 50 && b.bonx >= playerx - 50 && b.bony <= playery + 50 && b.bony >= playery - 50)
		return true;
	else
		return false;
}
void bonuschange()
{
	if (b.bony <= 0)
	{
		//srand(time(NULL));
		b.bonx = rand() % 1890;
		b.bony = 1890;
		ind = rand() % 5;
	}
	b.bony -= bspeed;

}
