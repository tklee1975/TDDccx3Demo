#ifdef ENABLE_TDD
//
//  SpriteTest.h
//
//
#ifndef __TDD_SpriteTest__
#define __TDD_SpriteTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class SpriteTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);

	Animation *createAnimation(std::vector<std::string> &frameNames,
					float duration,  bool restoreOriginal);
private:
	void testFlash(Ref *sender);
	void testFlashAnimation(Ref *sender);
	void testLoopFlash(Ref *sender);
}; 

#endif

#endif
