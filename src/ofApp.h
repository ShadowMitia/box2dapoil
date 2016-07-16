#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"




class CustomImage : public ofxBox2dRect /*, public ofxBox2dContactListener */{
	ofImage* img;
	bool shattered;
public:
	vector <shared_ptr<ofxBox2dPolygon> > polyShapes;
public:

	CustomImage(ofImage* i) {
		img = i;
		shattered = false;
	}
	/*
	void BeginContact(b2Contact* contact) override {
		if (contact->IsTouching()) {
			cout << "test" << endl;
		}
	}
	*/

	void draw() {
		if (!shattered) {
			glPushMatrix();
			ofTranslate(getPosition().x, getPosition().y);
			ofRotate(getRotation());
			img->setAnchorPercent(0.5, 0.5);
			img->draw(0, 0);
			glPopMatrix();
		} else {
			glPushMatrix();
			ofTranslate(getPosition().x, getPosition().y);
			ofRotate(getRotation());

			glPopMatrix();
		}

	}

	 void shapeSmash(ofxBox2d& box2d) {

		vector <shared_ptr<ofxBox2dPolygon> > polyShapes;

		ofPolyline poly;
		poly.addVertex(getPosition().x, getPosition().y);
		poly.addVertex(getPosition().x + getWidth(), getPosition().y);
		poly.addVertex(getPosition().x, getPosition().y + getHeight());
		poly.addVertex(getPosition().x + getWidth(), getPosition().y + getHeight());
		vector<TriangleShape> tris = triangulatePolygon(poly, true);

		for (int i = 0; i<tris.size(); i++) {

			shared_ptr<ofxBox2dPolygon> triangle = shared_ptr<ofxBox2dPolygon>(new ofxBox2dPolygon);
			triangle->addTriangle(tris[i].a, tris[i].b, tris[i].c);
			triangle->setPhysics(1.0, 0.3, 0.3);
			triangle->create(box2d.getWorld());

			polyShapes.push_back(triangle);
		}
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
