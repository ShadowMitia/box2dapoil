#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){



	a.load("A.jpg");
	a.resize(75, 75);
	p.load("P.jpg");
	p.resize(75, 75);
	o.load("O.jpg");
	o.resize(75, 75);
	i.load("I.jpg");
	i.resize(75, 75);
	l.load("L.jpg");
	l.resize(75, 75);
	cout << a.getWidth() << " " << a.getHeight() << endl;

	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(60.0);
	/*
	for (size_t i = 0; i < 50; i++) {
		boxes.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
		boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
		boxes.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 50, 50);
	}*/
	
	char apoil[5] = { 'A', 'P', 'O', 'I', 'L' };
	for (size_t i = 0; i < 50; i++) {
		letters.push_back(shared_ptr<CustomLetter>(new CustomLetter(apoil[(int)ofRandom(0, 5)])));
		letters.back().get()->setPhysics(3.0, 0.53, 0.1);
		letters.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 10, 10);
	}

	for (size_t i = 0; i < 50; i++) {
		sentance.push_back(shared_ptr<CustomSentance>(new CustomSentance("APOIL")));
		sentance.back().get()->setPhysics(3.0, 0.53, 0.1);
		sentance.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 10, 30);
	}

	for (size_t i = 0; i < 10; i++) {
		images.push_back(make_shared<CustomImage>(&a));
		images.back().get()->setPhysics(3.0, 0.53, 0.1);
		images.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 75, 75);
	}
	
	for (size_t i = 0; i < 10; i++) {
		images.push_back(shared_ptr<CustomImage>(new CustomImage(&p)));
		images.back().get()->setPhysics(3.0, 0.53, 0.1);
		images.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 75, 75);
	}

	for (size_t i = 0; i < 10; i++) {
		images.push_back(shared_ptr<CustomImage>(new CustomImage(&o)));
		images.back().get()->setPhysics(3.0, 0.53, 0.1);
		images.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 75, 75);
	}

	for (size_t j = 0; j < 10; j++) {
		images.push_back(shared_ptr<CustomImage>(new CustomImage(&i)));
		images.back().get()->setPhysics(3.0, 0.53, 0.1);
		images.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 75, 75);
	}

	for (size_t i = 0; i < 10; i++) {
		images.push_back(shared_ptr<CustomImage>(new CustomImage(&l)));
		images.back().get()->setPhysics(3.0, 0.53, 0.1);
		images.back().get()->setup(box2d.getWorld(), ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 75, 75);
	}
	

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();

	//ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
	//ofRemove(letters, ofxBox2dBaseShape::shouldRemoveOffScreen);
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (size_t i = 0; i < letters.size(); i++) {
		ofFill();
		ofSetHexColor(0xe63b8b);
		letters[i].get()->draw();
	}

	for (size_t i = 0; i < sentance.size(); i++)
	{
		sentance[i].get()->draw();
	}

	ofSetColor(ofColor::white);
	for (size_t i = 0; i < images.size(); i++)
	{
		images[i].get()->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
