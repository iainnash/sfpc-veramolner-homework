#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}


const int squareOffset = 20;
const int gridSize = 6;
const int offset = 30;
// This emulates "marker" colors in a plotter (6).
ofColor colors[] = {
    ofColor(144, 35, 41),    // red
    ofColor(139, 89, 158),   // purple
    ofColor(125, 114, 148),  // cyan dark
    ofColor(105, 161, 210),  // cyan
    ofColor(208, 240, 255),  // whiteish
    ofColor(238, 222, 15),   // yellow
};
const int colorsSize = 6;
ofPolyline line;
int randomDivision = 4;
#define randoff ofRandom(-1 * squareEach / randomDivision, squareEach / randomDivision)
void ofApp::draw(){
    ofBackground(0);
    ofNoFill();
    ofSeedRandom(mouseX * 3000);
    ofEnableAlphaBlending();
    
    int squareFinal = ofGetWidth() - squareOffset;
    int squareEach = (squareFinal - squareOffset) / gridSize;
    ofSetLineWidth(4);
    for (int x = squareOffset; x < squareFinal; x += squareEach) {
        for (int y = squareOffset; y < squareFinal; y += squareEach) {
            ofColor color = colors[(int)ofRandom(colorsSize)];
            color.setBrightness(255);
            ofSetColor(color.r, color.g, color.b, 200);
            
            for (int k = 0, kMax = 8; k < kMax; k++) {
                line.addVertex( // top left
                   x + offset + randoff,
                   y + offset + randoff
                );
                line.addVertex( // top right
                    x - offset + squareEach + randoff,
                    y + offset + randoff
                );
                line.addVertex( // bottom right
                    x - offset + squareEach + randoff,
                    y - offset + squareEach + randoff
                );
                line.addVertex( // bottom left
                    x + offset + randoff,
                    y - offset + squareEach + randoff
                );
                line.close();
                line.draw();
                line.clear();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    randomDivision += 1;
    if (randomDivision == 6) {
        randomDivision = 2;
    }
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
