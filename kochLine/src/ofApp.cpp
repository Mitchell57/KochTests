#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    size = 0;
    rot = 0;
    
    r = 175;
    g = 125;
    b = 250;
    
    kochFlake(600, 4);
    for(int i=0; i<50; i++){
        kochFlake(600 - (i, 4, paths[i]);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateDeg(rotY, 1, 0, 0);
    ofRotateDeg(rotX, 0, 1, 0);
    for(int i=0; i<MAX(size/10, 1); i+=1){
        int size = MAX(6, 680-(20*i));

        //ofTranslate(0,0, -size/20);
        ofColor myColor;
        //changeColor();
        if(i%3 == 0) {
            myColor.r = r;
            myColor.g = 0;
            myColor.b = 0;
        }
        else if(i%3 == 1){
            myColor.r = 0;
            myColor.g = g;
            myColor.b = 0;
        }
        else{
            myColor.r = 0;
            myColor.g = 0;
            myColor.b = b;
        }
        

        

    }


    
    ofPopMatrix();
    
    if(switchA){
        if(size < 340){
            size += 0.75;
        }
        else{
            if(rot < 90) rot += 0.75;
            else{
                switchA = false;
            }
        }
    }
    else{
        if(size > 6 || ((int)size % 3) != 0){
            size -= 0.75;
        }
        else{
            if(rot > 1) rot -= 0.75;
            else{
                switchA = true;
            }
        }
    }
    
    
    
    
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
    rotY = y;
    rotX = x;
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
void ofApp::kochLine(int x1, int y1, int x2, int y2, int it, ofPath path){

    double angle = 60*PI/180;
    
    int x3 = (2*x1+x2)/3;
    int y3 = (2*y1+y2)/3;
    
    int x4 = (x1+2*x2)/3;
    int y4 = (y1+2*y2)/3;
    
    int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
    int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);
    
    
    if(it > 0)
    {
        kochLine(x1, y1, x3, y3, it-1, path);
        kochLine(x3, y3, x, y, it-1, path);
        kochLine(x, y, x4, y4, it-1, path);
        kochLine(x4, y4, x2, y2, it-1, path);
    }
    else
    {
        path.moveTo(x1, y1);
        path.lineTo(x3, y3);
        path.lineTo(x, y);
        path.lineTo(x4, y4);
        path.lineTo(x2, y2);
        
        /*ofDrawLine(x1, y1, x3, y3);
        ofDrawLine(x3, y3, x, y);
        ofDrawLine(x, y, x4, y4);
        ofDrawLine(x4, y4, x2, y2);*/
    }
}

//--------------------------------------------------------------
void ofApp::kochFlake(int l, int it, ofPath path){
    ofPushMatrix();
    // starts from center
    ofTranslate(-l/2, -l/2);
    
    

    // x values
    int aX = 0;
    int bX = l;
    int cX = l/2;
    
    // height of small triangle
    int h1 = sqrt(pow(((bX-aX)/3), 2)-pow(((bX-aX)/6), 2));
    
    // height of big triangle
    int h2 = sqrt(pow(((bX-aX)), 2)-pow(((bX-aX)/2), 2));
    
    
    kochLine(aX, h1, bX, h1, it, path);
    kochLine(cX, h1+h2, aX, h1, it, path);
    kochLine(bX, h1, cX, h1+h2, it, path);
    
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::changeColor(){
    if(switchR){
        if(r < 255) r += 1;
        else switchR = false;
    }
    else{
        if(r > 0) r -= 1;
        else switchR = true;
    }
    if(switchG){
        if(g < 255) g += 1;
        else switchG = false;
    }
    else{
        if(g > 0) g -= 1;
        else switchG = true;
    }
    if(switchB){
        if(b < 255) b += 1;
        else switchB = false;
    }
    else{
        if(b > 0) b -= 1;
        else switchB = true;
    }
}
