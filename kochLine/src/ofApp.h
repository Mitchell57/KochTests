#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void kochLine(int x1, int y1, int x2, int y2, int it, ofPath path);
        void kochFlake(int l, int it, ofPath path);
        void changeColor();
        ofPath paths[50];
        float size;
        float rot;
        float rotX;
        float rotY;
        Boolean switchA;
        Boolean switchR;
        Boolean switchG;
        Boolean switchB;
        int r, g, b;
    
};
