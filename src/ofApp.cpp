#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(255, 255, 255);
	ofSetFrameRate(60);

	image.loadImage("images/ocean.jpeg");
	image.getTextureReference().setTextureWrap(GL_REPEAT, GL_REPEAT);

	plane.set(ofGetWidth(), ofGetHeight());
	plane.mapTexCoordsFromTexture(image.getTextureReference());

	shader.load("shaders/simple");
	shader.begin();
		shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
		shader.setUniform2f("texResolution", image.getWidth(), image.getHeight());
	shader.end();

	ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	image.getTextureReference().bind();
	shader.begin();
		shader.setUniform1f("time", ofGetElapsedTimef());
		ofPushMatrix();
			ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
			plane.draw();
		ofPopMatrix();
	shader.end();
	image.getTextureReference().unbind();
}
