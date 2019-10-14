#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

void drawLineAtAngle(int elWidth, int x, int y, int angle) {
    ofPushMatrix();
    ofTranslate(x + elWidth / 2, y + elWidth / 2);
    ofRotateZDeg(angle * 45);
    ofDrawLine(-1 * elWidth / 3, 0, elWidth / 3, 0);
    ofPopMatrix();
}

void ofApp::draw(){
    ofBackground(55);
    ofSetColor(158);
    ofNoFill();
    
    const int gridSize = 3;
    
    int startAt = ofGetWidth() * 0.4 / 4.0;
    int endAt = ofGetWidth() * 3.4 / 4.0;
    int elWidth = (endAt - startAt) / gridSize;

    for (int j = 0; j < gridSize; j++) {
        int angleAmounts = 2;
        for (int i = 0; i < gridSize; i++) {
            int x = ofMap(i, 0, gridSize, startAt, endAt);
            int y = ofMap(j, 0, gridSize, startAt, endAt);
            ofDrawRectangle(x, y, elWidth, elWidth);

            int atSquare = i + j * gridSize;
            if (atSquare < 4) {
                drawLineAtAngle(elWidth, x, y, (2 + atSquare) * 45);
            }
            if (atSquare > 4) {
                drawLineAtAngle(elWidth, x, y, (10 - atSquare) * 45);
            }
            if (atSquare == 4) {
                drawLineAtAngle(elWidth, x, y, 1 * 45);
                drawLineAtAngle(elWidth, x, y, 3 * 45);
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
