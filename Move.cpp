#include <utility>
using namespace std;

class Move{
public:
	bool initialized;
	pair<int,int> loc;
	int util;
	char mark;

	Move(pair<int,int> location, int utility, char marker);
	void toString();
	pair<int,int> getLocation();
	char getMarker();
	
};

Move::Move(pair<int,int> location, int utility, char marker)
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


void Move::toString()
{
	if(initialized)
	{
		cout << "Location:";
		cout << loc.first;
		cout << ",";
		cout << loc.second;
		cout << '\n';
	
		cout << "Utility:";
		cout << util;
		cout << '\n';
	
		cout << "Marker:";
		cout << mark;
		cout << '\n';
	}
}