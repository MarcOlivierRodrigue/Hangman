#include "Man.h"


Man::Man(int plimbs) {
	limbsLeft = plimbs;

	for (int i = 0; i < plimbs; i++) {
		*bodyParts[i] = ' ';
	}
}


void Man::addLimb() {
	limbsLeft -= 1;
	switch (limbsLeft)
	{
	case 0 : 
		*bodyParts[limbsLeft] = '\\';
		break;
	case 1 : 
		*bodyParts[limbsLeft] = '/';
		break;
	case 2:
		*bodyParts[limbsLeft] = '|';
		break;
	case 3:
		*bodyParts[limbsLeft] = '|';
		break;
	case 4:
		*bodyParts[limbsLeft] = '\\';
		break;
	case 5:
		*bodyParts[limbsLeft] = '/';
		break;
	case 6:
		*bodyParts[limbsLeft] = 'o';
		break;
	default:
		break;
	}
}

 int Man::getLimbsLeft() {
	return limbsLeft;
 }

std::vector<std::string> Man::getMan() {
	return vectorMan;
}


 


