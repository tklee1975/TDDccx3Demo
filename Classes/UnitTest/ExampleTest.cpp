#ifdef ENABLE_TDD
//
//  ExampleTest.m
//	TDD Framework 
//
//
#include "ExampleTest.h"
#include "TDDHelper.h"

void ExampleTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void ExampleTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void ExampleTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(ExampleTest::testLabel);
	SUBTEST(ExampleTest::testSprite);
}

#pragma mark -
#pragma mark Sub Test Definition
void ExampleTest::testLabel(Ref *sender)
{
	log("testLabel");
	
	std::string fontName = "Marker Felt.ttf";
	float fontSize = 40.0f;
	
	float x = 20;
	float y = 80;
	
	int repeat = 7;
	int step = 5;
	
	for(int i=0; i<repeat; i++) {
		char temp[100];
		sprintf(temp, "%s %.0f", fontName.c_str(), fontSize);
		Label *label = Label::createWithTTF(temp, fontName, fontSize);
		if(label == NULL) {
			continue;
		}
		label->setAnchorPoint(Point(0, 0));
		label->setPosition(x, y);
		addChild(label);

		y += fontSize + 5;
		fontSize -= step;
	}
	
}

void ExampleTest::testSprite(Ref *sender)
{
	log("testSprite");
	
    // add "HelloWorld" splash screen"
	Sprite *sprite = Sprite::create("HelloWorld.png");
	sprite->setScale(0.5, 0.5f);
    sprite->setPosition(Point(200, 100));
	
    this->addChild(sprite, 0);
	
	sprite = Sprite::create("HelloWorld.png");
	sprite->setScale(0.3, 0.3f);
	sprite->setRotation(45.0f);
    sprite->setPosition(Point(200, 200));
	
    this->addChild(sprite, 0);
	
}

#endif
