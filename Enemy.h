
struct enemy{
	int eHealth, ePosX, ePosY=1080;
}eShip[10];
int numEnemy, eI,eI2;
int f2, f3, f4, f5, f6, f7;
void enemySet()
{
	srand(time(0));
	numEnemy = rand()% 6;
	for (eI = 0; eI <= numEnemy; eI++)
	{
		if (eShip[eI].ePosY <= 0)
		{
			eShip[eI].ePosY = 1080;
			eShip[eI].ePosX = rand() % 1890;
		}
	}
}