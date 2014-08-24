TDDccx3: TDD Framework for cocos2d-x 
================

(This README is composed in http://dillinger.io/)

A Test Driven Development Framework for cocos2d-x 3.0 final. 
It helps building unit tests with cocos2d-x 3.0.

## Goal
* This project wanna help cocos2d-x developer developer Visual Unit Tests, such as UI building blocks,
animation test, ... 

## Feature

* Tests can be created easily 
* Tests can be filtered out
* Test History is kept so it is ease to redo the recent tests;

## Project Structure
* /script : The script to create a new test 
* /Classes : The example project source 
* /Classes/TDDLib : The TDDLib library source
* /Classes/UnitTest : Example Unit test


## How to setup in your project

### 1. Download the Library project 

* Main Development Code: 
 * https://github.com/tklee1975/tddlib_cocos2dx3 (The core source on which develop the TDDccx3, contains the unit tests made for the framework) 

* Demos: 
 * https://github.com/tklee1975/TDDccx3Demo (Landscape orientation)
 * https://github.com/tklee1975/TDDccx3DemoP (Portrait orientation)

* Note:
  * If you want to try and use, download the demo, it is simpler
  * If you want to hack the code and changes, download the development code.

### 2. Add the library to your project

After download the project, you will the project structure mentioned in last section. Copy the Library source code to your cocos2dx project. For my preference, I will copy to a folder named "Library" under my Classes folder.

Then add the 'TDDLib' folder to the Xcode. 


### 3. Add the script to your project

Besides source code, there are some scripts that help to make the UnitTest classes. 

### 4. Set the MACRO 'ENABLE_TDD'

As we don't want to let the unit test stuff affect the size of the release build, all the UnitTest code and most of the library are enclosed by the 'ENABLE_TDD' macro. The test will not be included if 'ENABLE_TDD' isn't defined. 

To turn the test code on, we need add the Marcro "ENABLE_TDD" definition to the compile setting. 

### 5. Add the Test Button

Unlike the way of most unit test framework, TDDLib will build with the main code; Thus, the unit tests are linked with the main code in Test build version. 

The way to do so is that add "test" button is placed on the Main View (e.g title scene or main scene) of the game. 

The code sample is: 

<pre>
TDDHelper::addTestButton(this, Point(visibleSize.width/2, 50)); 
</pre>

## How to add a new test

(note: we will use ExampleTest as the example of the new UnitTest)

### 1. Run the 'createTest' script 

* Go to the main folder e.g MyProject/
* Run the createTest.sh script  
 <pre>
 ./script/createTest.sh Example
 </pre>
  noted that the following files will be generated.

  - MyProject/Classes/UnitTest/ExampleTest.h
  - MyProject/Classes/UnitTest/ExampleTest.cpp


### 2. Add the new test class

* Add the new UnitTest header and source files to XCode
* For my preference, I will place them in a group called 'UnitTest'.

### 3. Create the MyTDDCases.h 

MyTDDCases.h is the your header defining the test cases you created.

This is the sample code 
<pre>
// include files
#include "ExampleTest.h"	// Test class header

// Test Class Definition 
TDD_CASES
{
	TEST(ExampleTest),	// Test class name
};
</pre>

To add a new test, just include your test class header and define it inside TDD_CASES block
 
 

### 4. Build and Run 
* Build (Cmd+B) and Run (Cmd + R) in Xcode. 


### 5. Adding test code

If the unit test is successfully added. you can place your test code inside.

#### 5.1 Using the sub test


Every Unit Test is designed to contain many sub tests to be invoked. Just add the sub test method and add the entry in the setSubTest method. 

The code sample are as follows:

* Add the sub test method 

<pre>
void ExampleTest::testSomethingNew(Ref *sender)
{
	log("testSomethingNew");
}
</pre>

* Add the entry in setSubTest method

<pre>
void ExampleTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(ExampleTest::testSomethingNew);
	SUBTEST(ExampleTest::testSprite);
}
</pre>


#### 5.2 Override the Unit Test content

Every Unit Test Class (TDDTest) is the sub class of Scene. So it can do everything you expect to be done in Scene. But the different is that TDDTest will run 'setUp' after the Scene is loaded and 'tearDown' below the Scene is removed. 

So, we can setup a custom testing UI at the setUp logic to fit the test environment we needed.

(note: build an example in the future)

## Future Development
* Document:
    * Tutorial #1: Setup TDDLib
    * Tutorial #2: Very simple unit test
* Feature: 
    * Test Filtering in the Test Menu (done)
    * Beautify the UI
    * More compact subtest menu
    * Remmber the test filtering keyword
    * Clear the current filtering keyword
* Sample Code
    * Custom Test UI. e.g particle test with setting sliders

## Help! I need somebody help! 
### Call for users
* I am the only user of this project now;
* As more users, more suggestions come and the framework will evolve faster and better.
* Users help to discover bugs and bad UX (User Experience).
* Users may drive me to work. (This is my pet project after work, so I will be lazy ....) 

### Call for Developers
* It would be fun if more people get involved in the development.
* You can help to code review so that the code can be more concise and easy to understand.

### Improvement on the document. 
* I am not an native english person. Thus, my grammer and explanation are not good enough to help users understand the detail.
* I am really weak in technical writing >.< !










