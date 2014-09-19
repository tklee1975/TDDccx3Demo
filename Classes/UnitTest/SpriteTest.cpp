#ifdef ENABLE_TDD
//
//  SpriteTest.m
//	TDD Framework 
//
//
#include "SpriteTest.h"
#include "TDDHelper.h"

void SpriteTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("effects.plist");
	setBackgroundColor(Color3B::BLACK);
}


void SpriteTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark Handy Method
Animation *SpriteTest::createAnimation(std::vector<std::string> &frameNames,
									   float duration, bool restoreOriginal)
{
	int frameSize = (int) frameNames.size();
	
	// Manual Animation
	auto animation = Animation::create();
	for(int i=0; i<frameNames.size(); i++) {
		std::string name = frameNames[i];
		
		SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name.c_str());
		animation->addSpriteFrame(frame);
	}
//    for( int i=startIdx;i<=endIdx;i++)
//    {
//        char szName[100] = {0};
//        sprintf(szName, "%s%d.png", frame_prefix.c_str(), i);
//		SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
//        animation->addSpriteFrame(frame);
//    }
//	
	
    animation->setDelayPerUnit(duration / frameSize);
    animation->setRestoreOriginalFrame(restoreOriginal);
	
	return animation;
}

#pragma mark -
#pragma mark List of Sub Tests

void SpriteTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(SpriteTest::testFlash);
	SUBTEST(SpriteTest::testFlashAnimation);
	SUBTEST(SpriteTest::testLoopFlash);
}

#pragma mark -
#pragma mark Sub Test Definition
void SpriteTest::testFlash(Ref *sender)
{
	log("testFlash");
	
	Sprite *node = Sprite::createWithSpriteFrameName("flash00.png");
	node->setScale(0.5f);
	node->setPosition(Point(150, 100));
	
	addChild(node);
}

void SpriteTest::testFlashAnimation(Ref *sender)
{
	log("testFlash");
	
	Sprite *node = Sprite::createWithSpriteFrameName("flash00.png");
	node->setScale(0.1f);
	node->setPosition(Point(150, 100));
	
	//
	std::vector<std::string> frameNames;
	char tempstr[100];
	for(int i=0; i<8; i++) {
		sprintf(tempstr, "flash%02d.png", i);
		std::string name = std::string(tempstr);
		frameNames.push_back(name);
	}
	
	//
	Animation *animation = createAnimation(frameNames, 1, true);
	Animate *animate = Animate::create(animation);
	node->runAction(animate);
	
	addChild(node);
}

void SpriteTest::testLoopFlash(Ref *sender)
{
	log("testLoopFlash");
	
	Sprite *node = Sprite::createWithSpriteFrameName("flash00.png");
	node->setScale(0.1f);
	node->setPosition(Point(150, 100));
	
	//
	std::vector<std::string> frameNames;
	char tempstr[100];
	for(int i=0; i<8; i++) {
		sprintf(tempstr, "flash%02d.png", i);
		std::string name = std::string(tempstr);
		frameNames.push_back(name);
	}
	
	//
	Animation *animation = createAnimation(frameNames, 0.5, true);
	Animate *animate = Animate::create(animation);
	RepeatForever *forever = RepeatForever::create(animate);
	
    node->runAction(forever);
	
	addChild(node);
}


#endif
