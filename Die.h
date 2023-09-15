#pragma once

#include <iostream>
#include <cstdlib>

class Die
{

public:

	Die(){};
	~Die(){};

	int roll(int faces)
	{
		int r = rand();
		int rollN = r % (faces) + 1;
		return(rollN);
	}

	int D20() { return roll(20); }
	int D12() { return roll(12); }
	int D10() { return roll(10); }
	int D8()  { return roll(8);  }
	int D6()  { return roll(6);  }
	int D4()  { return roll(4);  }

};