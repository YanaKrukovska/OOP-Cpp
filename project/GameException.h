#pragma once
#include <iostream>

using namespace std;


class GameException
{
private:
    string _reason;
public:
	explicit GameException(string reason)
		: _reason(reason) { }

	 void show() const{
         cout << "Error: " << _reason << endl;
	}
};


