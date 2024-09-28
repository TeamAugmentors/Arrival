#define fireSpeed 10
#define firePic 6
#define fireIndex 6
struct fire
{
	int firex;
	int firey;
}spacefire[fireIndex], fire1, fire2, fire3, fire4, fire5, fire6, fire7, fire8, fire9, fire10, fire11, fire12, fire13, fire14, fire15, fire16, fire17;
int fireI;
char fire[fireIndex][50] = { "Picture//Fire//fire1.bmp", "Picture//Fire//fire2.bmp", "Picture//Fire//fire3.bmp", "Picture//Fire//fire4.bmp", "Picture//Fire//fire5.bmp", "Picture//Fire//fire6.bmp" };
void fireshow(int player)
{
	int sum = playery-150;
	for (fireI = 0; fireI < firePic; fireI++)
	{
		spacefire[fireI].firex = player+20;
		spacefire[fireI].firey = sum;
		sum += 180;
		printf("Yes");
	}

}
void firechange()
{
	for (fireI = 0; fireI < firePic; fireI++)
	{
		spacefire[fireI].firey += fireSpeed;
		if (spacefire[fireI].firey >= 1900)
		{
			spacefire[fireI].firey = 0;
		}
	}
}