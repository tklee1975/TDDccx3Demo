#ifdef ENABLE_TDD
//
//  FontTest.m
//	TDD Framework 
//
//
#include "FontTest.h"
#include "TDDHelper.h"
#include <vector>
#include <string>

void FontTest::setUp()
{
	log("TDD Setup is called");
	
	
	std::vector<std::string> fontList;
	
	// note: name of the font can be found here:
	// http://iosfonts.com/
	fontList.push_back("Arial");
	fontList.push_back("GillSans");
	fontList.push_back("Helvetica");
	fontList.push_back("AmericanTypewriter");
	fontList.push_back("Arial-BoldMT");
	fontList.push_back("Chalkduster");
	fontList.push_back("Courier");
	fontList.push_back("Papyrus");
	fontList.push_back("TimesNewRomanPSMT");
	
	Point pos = Point(300, 20);
	for(int i=0; i<fontList.size(); i++) {
		std::string name = fontList[i];
		
		Label *label = createLabel(name, name, 20);
		label->setPosition(pos);
		addChild(label);
		
		pos.y += 30;
	}
}


void FontTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void FontTest::setSubTest(Vector<MenuItem *> &menuArray)
{
}

Label *FontTest::createLabel(const std::string &text, const std::string &font, int size)
{
	Label *label = Label::createWithSystemFont(text, font, size);
	label->setColor(Color3B::WHITE);
	label->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
	
	return label;
}


#endif
