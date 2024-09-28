
int speed;
struct meteor
{
	int meteorx;
	int meteory;
}meteors;
int meteorspeed = rand() % 15;
int random_number(int min_num, int max_num)
{
	int result = 0, low_num = 0, hi_num = 0;

	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1; // include max_num in output
	}
	else {
		low_num = max_num + 1; // include max_num in output
		hi_num = min_num;
	}

	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}
void meteorchange()
{
	if (meteors.meteory <= 0)
	{
		meteors.meteorx = rand()%1890;
		meteors.meteory = 1080;
		speed = rand() % 15;
		if (speed<= 0)
			meteorspeed += 10;
		else
			meteorspeed = speed;
	}

}
bool collisioncheck()
{
	if (meteors.meteorx <= playerx + 50 && meteors.meteorx >= playerx - 50 && meteors.meteory <= playery + 50 && meteors.meteory >= playery - 50)
		return true;
	else
		return false;

}
bool checkfiremeteor(int x, int y)
{


	if (((fire1.firex >= x && fire1.firex <= x + 70) && fire1.firey >= y) || ((fire2.firex >= x && fire2.firex <= x + 70) && fire2.firey >= y) ||
		((fire3.firex >= x && fire3.firex <= x + 70) && fire3.firey >= y) || ((fire4.firex >= x && fire4.firex <= x + 70) && fire4.firey >= y) ||
		((fire5.firex >= x && fire5.firex <= x + 70) && fire5.firey >= y) || ((fire6.firex >= x && fire6.firex <= x + 70) && fire6.firey >= y) ||
		((fire7.firex >= x && fire7.firex <= x + 70) && fire7.firey >= y) || ((fire8.firex >= x && fire8.firex <= x + 70) && fire8.firey >= y) ||
		((fire9.firex >= x && fire9.firex <= x + 70) && fire9.firey >= y) || ((fire10.firex >= x && fire10.firex <= x + 70) && fire10.firey >= y) ||
		((fire11.firex >= x && fire11.firex <= x + 70) && fire11.firey >= y) || ((fire12.firex >= x && fire12.firex <= x + 70) && fire12.firey >= y) ||
		((fire13.firex >= x && fire13.firex <= x + 70) && fire13.firey >= y) || ((fire14.firex >= x && fire14.firex <= x + 70) && fire14.firey >= y) ||
		((fire15.firex >= x && fire15.firex <= x + 70) && fire15.firey >= y) || ((fire16.firex >= x && fire16.firex <= x + 70) && fire16.firey >= y) ||
		((fire17.firex >= x && fire17.firex <= x + 70) && fire17.firey >= y))
		{
			if ((fire1.firex >= x && fire1.firex <= x + 70) && fire1.firey >= y)
				fire1.firex = -2000;
			else if((fire2.firex >= x && fire2.firex <= x + 70) && fire2.firey >= y)
				fire2.firex = -2000;
			else if ((fire3.firex >= x && fire3.firex <= x + 70) && fire3.firey >= y)
				fire3.firex = -2000;
			else if ((fire4.firex >= x && fire4.firex <= x + 70) && fire4.firey >= y)
				fire4.firex = -2000;
			else if ((fire5.firex >= x && fire5.firex <= x + 70) && fire5.firey >= y)
				fire5.firex = -2000;
			else if ((fire6.firex >= x && fire6.firex <= x + 70) && fire6.firey >= y)
				fire6.firex = -2000;
			else if ((fire7.firex >= x && fire7.firex <= x + 70) && fire7.firey >= y)
				fire7.firex = -2000;
			else if ((fire8.firex >= x && fire8.firex <= x + 70) && fire8.firey >= y)
				fire8.firex = -2000;
			else if ((fire9.firex >= x && fire9.firex <= x + 70) && fire9.firey >= y)
				fire10.firex = -2000;
			else if ((fire11.firex >= x && fire11.firex <= x + 70) && fire11.firey >= y)
				fire11.firex = -2000;
			else if ((fire12.firex >= x && fire12.firex <= x + 70) && fire12.firey >= y)
				fire12.firex = -2000;
			else if ((fire13.firex >= x && fire13.firex <= x + 70) && fire13.firey >= y)
				fire13.firex = -2000;
			else if ((fire14.firex >= x && fire14.firex <= x + 70) && fire14.firey >= y)
				fire14.firex = -2000;
			else if ((fire15.firex >= x && fire15.firex <= x + 70) && fire15.firey >= y)
				fire15.firex = -2000;
			else if ((fire16.firex >= x && fire16.firex <= x + 70) && fire16.firey >= y)
				fire13.firex = -2000;
			else if ((fire17.firex >= x && fire17.firex <= x + 70) && fire17.firey >= y)
				fire17.firex = -2000;

			return true;
		}
	else
		return false;

}