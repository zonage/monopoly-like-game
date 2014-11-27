#ifndef __SQUARE_H__
#define __SQUARE_H__

class Square {
	protected:
	int number;
	
	Square();
	~Square();
	virtual void action()=0;
};

#endif