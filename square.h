#ifndef __SQUARE_H__
#define __SQUARE_H__

class Square {

	public:
	int number;

	std::string display;
	
	Square();
	~Square();
	virtual void action()=0;
};

#endif