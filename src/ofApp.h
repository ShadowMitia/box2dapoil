#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class CustomImage : public ofxBox2dRect {
	ofImage* img;

public:

	CustomImage(ofImage* i) {
		img = i;
	}

	void draw() {
		glPushMatrix();
		ofTranslate(getPosition().x, getPosition().y);
		ofRotate(getRotation());
		img->setAnchorPercent(0.5, 0.5);
		img->draw(0, 0);
		glPopMatrix();
	}
};

class CustomLetter : public ofxBox2dRect {

	char m_letter;

public:

	CustomLetter(char letter) : m_letter(letter) {

	}

	void draw() {
		glPushMatrix();
		ofDrawBitmapString(m_letter, getPosition().x, getPosition().y);
		glPopMatrix();
	}
};

class CustomSentance : public ofxBox2dRect {
	std::string m_sentance;

public:
	CustomSentance(std::string s) : m_sentance(s) {

	}

	void draw() {
		glPushMatrix();
		ofDrawBitmapString(m_sentance, getPosition().x, getPosition().y);
		glPopMatrix();
	}
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxBox2d box2d;
		vector <shared_ptr<ofxBox2dRect>> boxes;
		vector <shared_ptr<CustomLetter>> letters;
		vector <shared_ptr<CustomSentance>> sentance;
		vector <shared_ptr<CustomImage>> images;
		ofImage a, p, o, i, l;
		
};
