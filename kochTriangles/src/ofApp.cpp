#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    size = 0;
    sizeSwitch = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255, 255, 255, 100);
    drawKoch(600);
    ofRotateDeg(60);
    drawKoch(600);
    
    /*ofSetColor(200, 200, 255, 100);
    ofRotateDeg(60);
    drawKoch(450);
    ofRotateDeg(60);
    drawKoch(450);
    
    ofSetColor(255, 200, 200, 100);
    ofRotateDeg(60);
    drawKoch(300);
    ofRotateDeg(60);
    drawKoch(300);
    
    ofSetColor(200, 200, 255, 100);
    ofRotateDeg(60);
    drawKoch(150);
    ofRotateDeg(60);
    drawKoch(150);
    
    ofSetColor(255, 0, 0, 60);
    ofRotateDeg((3*size)/10);
    drawKoch(size);
    ofSetColor(0, 0, 255, 60);
    ofRotateDeg(-2*(3*size/10));
    drawKoch(size);
    if(sizeSwitch){
        size += 0.6;
        if(size >= 600) sizeSwitch = false;
    }
    else{
        size -= 0.6;
        if(size <= 1) sizeSwitch = true;
    }
    if(size >= 900) size = 0;

    ofSetColor(20, 20, 20);*/

    //ofDrawCircle(0, 0, 2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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

//--------------------------------------------------------------

void ofApp::drawKoch(int width){
    ofPushMatrix();
    
    
    float side = width;
    float height = (sqrt(3)*width)/2;
    float height2 = (sqrt(3)*width)/2 + (sqrt(3)*width)/6;
    
    //starter
    ofTranslate(-width/2, height2/4);
    ofDrawTriangle(0, 0, side, 0, side/2, -height);
    

    //recursion
    drawKochHelper(width/3);
    
    
    ofPopMatrix();
}

void ofApp::drawKochHelper(float side){
    if(side > 1){
        float height = (sqrt(3)*side)/2;
        ofPushMatrix();
        ofRotateDeg(-60);
        ofTranslate(side, 0);
        ofDrawTriangle(0, 0, side, 0, side/2, -height);
        drawKochHelper(side/3);
    
        ofTranslate(2*side, 0);
        ofRotateDeg(-240);
        ofTranslate(side, 0);
        ofDrawTriangle(0, 0, side, 0, side/2, -height);
        drawKochHelper(side/3);
        
        ofTranslate(2*side, 0);
        ofRotateDeg(-240);
        ofTranslate(side, 0);
        ofDrawTriangle(0, 0, side, 0, side/2, -height);
        drawKochHelper(side/3);
        ofPopMatrix();
    }
}


