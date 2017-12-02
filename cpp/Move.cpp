#include <utility>
using namespace std;

class Move{
public:
	bool initialized;
	pair<int,int> loc;
	int util;
	char mark;

	Move();
	Move(pair<int,int> location, int utility, char marker);
	void toString();
	pair<int,int> getLocation();
	char getMarker();
	int getUtility();
	void buildMove(pair<int,int> location, int utility, char marker);

};

Move::Move()
{
	initialized = false;
	util = 0;
}

Move::Move(pair<int,int> location, int utility, char marker)
{
	initialized = true;
	loc = location;
	util = utility;
	mark = marker;
}

void Move::buildMove(pair<int,int> location, int utility, char marker)
{
	initialized = true;
	loc = location;
	util = utility;
	mark = marker;
}

pair<int,int> Move::getLocation()
{
	return loc;
}

char Move::getMarker()
{
	return mark;
}

int Move::getUtility()
{
	return util;
}


void Move::toString()
{
	if(initialized)
	{
		cout << "  Location:";
		cout << loc.first;
		cout << ",";
		cout << loc.second;
		cout << '\n';
	
		cout << "  Utility:";
		cout << util;
		cout << '\n';
	
		cout << "  Marker:";
		cout << mark;
		cout << '\n';
	}
}