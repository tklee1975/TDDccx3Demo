#ifdef ENABLE_TDD
//
//  FontTest.h
//
//
#ifndef __TDD_FontTest__
#define __TDD_FontTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class FontTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	Label *createLabel(const std::string &text, const std::string &font, int size);
}; 

#endif

#endif
