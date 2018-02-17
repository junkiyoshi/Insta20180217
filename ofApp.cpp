#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->fbo.allocate(ofGetWidth(), ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::update() {

	int x_span = 30;

	this->fbo.begin();
	ofClear(0);

	for (int x = 0; x < ofGetWidth(); x += x_span) {

		float top_rect_height = ofGetHeight() * ofNoise(x * 0.005, 1, ofGetFrameNum() * 0.005);

		ofSetColor(255);
		ofFill();
		ofDrawRectangle(ofVec2f(x, 0), x_span, ofGetHeight());

		ofSetColor(0);
		ofNoFill();
		ofDrawRectangle(ofVec2f(x, 0), x_span, ofGetHeight());

		ofSetColor(255, 0, 0);
		ofFill();
		ofDrawRectangle(ofVec2f(x, 0), x_span, top_rect_height);

		ofSetColor(0, 0, 255);
		ofNoFill();
		ofDrawRectangle(ofVec2f(x, 0), x_span, top_rect_height);

		float down_rect_height = ofGetHeight() * ofNoise(x * 0.005, 2, ofGetFrameNum() * 0.005);
	
		ofSetColor(0, 0, 255);
		ofFill();
		ofDrawRectangle(ofVec2f(x, ofGetHeight()), x_span, -down_rect_height);

		ofSetColor(255, 0, 0);
		ofNoFill();
		ofDrawRectangle(ofVec2f(x, ofGetHeight()), x_span, -down_rect_height);
	}

	this->fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->fbo.draw(0, 0);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}