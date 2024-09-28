

bool enemycollision(int x1, int y1)
{
	if (x1 <= playerx + 50 && x1 >= playerx - 50 && y1 <= playery + 50 && y1 >= playery - 50)
		return true;
	else false;
}
bool kalaenemycollision(int x, int y)
{
	if (x <= playerx+100 && x >= playerx-100)
		if (y <= playery + 82 && y >= playery - 82)
		{
			return true;
		}
	else false;
}
bool kalaenemyfirecollision(int x, int y)
{
		if (x <= playerx + 50 && x >= playerx - 50 && y <= playery + 50 && y >= playery - 50)
			return true;
		else
			return false;
}