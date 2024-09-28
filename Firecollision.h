
int kalaenemyX = 200, kalaenemyY = 1900;

bool checkfire(int x, int y)
{
	

	if (((fire1.firex >= x && fire1.firex <= x+100) && fire1.firey >= y) || ((fire2.firex >= x && fire2.firex <= x+100) && fire2.firey >= y) ||
		((fire3.firex >= x && fire3.firex <= x+100) && fire3.firey >= y) || ((fire4.firex >= x && fire4.firex <= x+100) && fire4.firey >= y) ||
		((fire5.firex >= x && fire5.firex <= x+100) && fire5.firey >= y) || ((fire6.firex >= x && fire6.firex <= x+100) && fire6.firey >= y) ||
		((fire7.firex >= x && fire7.firex <= x+100) && fire7.firey >= y) || ((fire8.firex >= x && fire8.firex <= x+100) && fire8.firey >= y) ||
		((fire9.firex >= x && fire9.firex <= x+100) && fire9.firey >= y) || ((fire10.firex >= x && fire10.firex <= x+100) && fire10.firey >= y) ||
		((fire11.firex >= x && fire11.firex <= x+100) && fire11.firey >= y) || ((fire12.firex >= x && fire12.firex <= x+100) && fire12.firey >= y) ||
		((fire13.firex >= x && fire13.firex <= x + 100) && fire13.firey >= y) || ((fire14.firex >= x && fire14.firex <= x + 100) && fire14.firey >= y) ||
		((fire15.firex >= x && fire15.firex <= x + 100) && fire15.firey >= y) || ((fire16.firex >= x && fire16.firex <= x + 100) && fire16.firey >= y) ||
		((fire17.firex >= x && fire17.firex <= x + 100) && fire17.firey >= y))
		return true;
	else
		return false;

}
bool checkfirekalaenemy(int x, int y)
{
	if (((fire1.firex >= x && fire1.firex <= x + 200) && fire1.firey >= y) || ((fire2.firex >= x && fire2.firex <= x + 200) && fire2.firey >= y) ||
		((fire3.firex >= x && fire3.firex <= x + 200) && fire3.firey >= y) || ((fire4.firex >= x && fire4.firex <= x + 200) && fire4.firey >= y) ||
		((fire5.firex >= x && fire5.firex <= x + 200) && fire5.firey >= y) || ((fire6.firex >= x && fire6.firex <= x + 200) && fire6.firey >= y) ||
		((fire7.firex >= x && fire7.firex <= x + 200) && fire7.firey >= y) || ((fire8.firex >= x && fire8.firex <= x + 200) && fire8.firey >= y) ||
		((fire9.firex >= x && fire9.firex <= x + 200) && fire9.firey >= y) || ((fire10.firex >= x && fire10.firex <= x + 200) && fire10.firey >= y) ||
		((fire11.firex >= x && fire11.firex <= x + 200) && fire11.firey >= y) || ((fire12.firex >= x && fire12.firex <= x + 200) && fire12.firey >= y) ||
		((fire13.firex >= x && fire13.firex <= x + 200) && fire13.firey >= y) || ((fire14.firex >= x && fire14.firex <= x + 200) && fire14.firey >= y) ||
		((fire15.firex >= x && fire15.firex <= x + 200) && fire15.firey >= y) || ((fire16.firex >= x && fire16.firex <= x + 200) && fire16.firey >= y) ||
		((fire17.firex >= x && fire17.firex <= x + 200) && fire17.firey >= y))
	{
		if ((fire1.firex >= x && fire1.firex <= x + 200) && fire1.firey >= y)
			fire1.firex = -3000;
		else if ((fire2.firex >= x && fire2.firex <= x + 200) && fire2.firey >= y)
			fire2.firex = -3000;
		else if ((fire3.firex >= x && fire3.firex <= x + 200) && fire3.firey >= y)
			fire3.firex = -3000;
		else if ((fire4.firex >= x && fire4.firex <= x + 200) && fire4.firey >= y)
			fire4.firex = -3000;
		else if ((fire5.firex >= x && fire5.firex <= x + 200) && fire5.firey >= y)
			fire5.firex = -3000;
		else if ((fire6.firex >= x && fire6.firex <= x + 200) && fire6.firey >= y)
			fire6.firex = -3000;
		else if ((fire7.firex >= x && fire7.firex <= x + 200) && fire7.firey >= y)
			fire7.firex = -3000;
		else if ((fire8.firex >= x && fire8.firex <= x + 200) && fire8.firey >= y)
			fire8.firex = -3000;
		else if ((fire9.firex >= x && fire9.firex <= x + 200) && fire9.firey >= y)
			fire10.firex = -3000;
		else if ((fire11.firex >= x && fire11.firex <= x + 200) && fire11.firey >= y)
			fire11.firex = -3000;
		else if ((fire12.firex >= x && fire12.firex <= x + 200) && fire12.firey >= y)
			fire12.firex = -3000;
		else if ((fire13.firex >= x && fire13.firex <= x + 200) && fire13.firey >= y)
			fire13.firex = -3000;
		else if ((fire14.firex >= x && fire14.firex <= x + 200) && fire14.firey >= y)
			fire14.firex = -3000;
		else if ((fire15.firex >= x && fire15.firex <= x + 200) && fire15.firey >= y)
			fire15.firex = -3000;
		else if ((fire16.firex >= x && fire16.firex <= x + 200) && fire16.firey >= y)
			fire13.firex = -3000;
		else if ((fire17.firex >= x && fire17.firex <= x + 200) && fire17.firey >= y)
			fire17.firex = -3000;
		return true;
	}
	else
		return false;
}
bool checkfireBoss(int x, int y)
{
	if (((fire1.firex >= x && fire1.firex <= x + 300) && fire1.firey >= y) || ((fire2.firex >= x && fire2.firex <= x + 300) && fire2.firey >= y) ||
		((fire3.firex >= x && fire3.firex <= x + 300) && fire3.firey >= y) || ((fire4.firex >= x && fire4.firex <= x + 300) && fire4.firey >= y) ||
		((fire5.firex >= x && fire5.firex <= x + 300) && fire5.firey >= y) || ((fire6.firex >= x && fire6.firex <= x + 300) && fire6.firey >= y) ||
		((fire7.firex >= x && fire7.firex <= x + 300) && fire7.firey >= y) || ((fire8.firex >= x && fire8.firex <= x + 300) && fire8.firey >= y) ||
		((fire9.firex >= x && fire9.firex <= x + 300) && fire9.firey >= y) || ((fire10.firex >= x && fire10.firex <= x + 300) && fire10.firey >= y) ||
		((fire11.firex >= x && fire11.firex <= x + 300) && fire11.firey >= y) || ((fire12.firex >= x && fire12.firex <= x + 300) && fire12.firey >= y) ||
		((fire13.firex >= x && fire13.firex <= x + 300) && fire13.firey >= y) || ((fire14.firex >= x && fire14.firex <= x + 300) && fire14.firey >= y) ||
		((fire15.firex >= x && fire15.firex <= x + 300) && fire15.firey >= y) || ((fire16.firex >= x && fire16.firex <= x + 300) && fire16.firey >= y) ||
		((fire17.firex >= x && fire17.firex <= x + 300) && fire17.firey >= y))
	{
		if ((fire1.firex >= x && fire1.firex <= x + 300) && fire1.firey >= y)
			fire1.firex = -3000;
		else if ((fire2.firex >= x && fire2.firex <= x + 300) && fire2.firey >= y)
			fire2.firex = -3000;
		else if ((fire3.firex >= x && fire3.firex <= x + 300) && fire3.firey >= y)
			fire3.firex = -3000;
		else if ((fire4.firex >= x && fire4.firex <= x + 300) && fire4.firey >= y)
			fire4.firex = -3000;
		else if ((fire5.firex >= x && fire5.firex <= x + 300) && fire5.firey >= y)
			fire5.firex = -3000;
		else if ((fire6.firex >= x && fire6.firex <= x + 300) && fire6.firey >= y)
			fire6.firex = -3000;
		else if ((fire7.firex >= x && fire7.firex <= x + 300) && fire7.firey >= y)
			fire7.firex = -3000;
		else if ((fire8.firex >= x && fire8.firex <= x + 300) && fire8.firey >= y)
			fire8.firex = -3000;
		else if ((fire9.firex >= x && fire9.firex <= x + 300) && fire9.firey >= y)
			fire10.firex = -3000;
		else if ((fire11.firex >= x && fire11.firex <= x + 300) && fire11.firey >= y)
			fire11.firex = -3000;
		else if ((fire12.firex >= x && fire12.firex <= x + 300) && fire12.firey >= y)
			fire12.firex = -3000;
		else if ((fire13.firex >= x && fire13.firex <= x + 300) && fire13.firey >= y)
			fire13.firex = -3000;
		else if ((fire14.firex >= x && fire14.firex <= x + 300) && fire14.firey >= y)
			fire14.firex = -3000;
		else if ((fire15.firex >= x && fire15.firex <= x + 300) && fire15.firey >= y)
			fire15.firex = -3000;
		else if ((fire16.firex >= x && fire16.firex <= x + 300) && fire16.firey >= y)
			fire13.firex = -3000;
		else if ((fire17.firex >= x && fire17.firex <= x + 300) && fire17.firey >= y)
			fire17.firex = -3000;
		return true;
	}
	else
		return false;
}