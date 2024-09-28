#define backgroundSpeed 10
#define backgroundPic 6
#define backgroundIndex 6
struct Background
{
	double x;
	double y;
}spaceBackground[backgroundIndex];
int spaceI;
char space[backgroundIndex][50] = { "Space//space1.bmp", "Space//space2.bmp", "Space//space3.bmp", "Space//space4.bmp", "Space//space5.bmp", "Space//space6.bmp"};
void showAll()
{
	int sum = 0;
	for (spaceI = 0; spaceI < backgroundPic; spaceI++)
	{
		spaceBackground[spaceI].x = 0;
		spaceBackground[spaceI].y = sum;
		sum += 180;
	}
	
}
void change1()
{
	for (spaceI = 0; spaceI < backgroundPic; spaceI++)
	{
		spaceBackground[spaceI].y -= backgroundSpeed;
		if (spaceBackground[spaceI].y <= 0)
		{
			spaceBackground[spaceI].y = 1080;
		}
	}
}