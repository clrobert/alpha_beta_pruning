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
	
};

Move::Move(pair<int,int> location, int utility, char marker)
{
	initialized = true;
	loc = location;
	util = utility;
	mark = marker;
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