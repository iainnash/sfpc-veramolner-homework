#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

ofPolyline lines;

const int margin = 40;
const float chance_change = 0.88;
const float size_div = 3;

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofBackground(255);
    ofSetColor(0);
    
    int screenWidth = ofGetWidth();
    ofSeedRandom(mouseX * 4000);
    float accepted_deviation = ofMap(mouseY, 0, ofGetHeight(), 0, 20);
    
    int startAt = screenWidth - margin;
    for (int ox = startAt / 2; ox > margin; ox -= 10) {
        lines.clear();
        int size = screenWidth - ox * 2;
        lines.addVertex(ox, ox);
        if (ofRandom(1.f) > chance_change) {
            float atY = ox;
            int incr = ofRandom(size/size_div);
            while (atY < ox + size - 40) {
                lines.addVertex(ox + ofRandom(-1 * accepted_deviation, accepted_deviation), atY);
                atY += incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        
        
        lines.addVertex(ox, ox + size);
        if (ofRandom(1.f) > chance_change) {
            float atX = ox;
            int incr = ofRandom(size);
            while (atX < ox + size - 40) {
                lines.addVertex(atX, ox + size + ofRandom(-1 * accepted_deviation, accepted_deviation));
                atX += incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        
        
        lines.addVertex(ox + size, ox + size);
        if (ofRandom(1.f) > chance_change) {
            float atY = ox + size;
            int incr = ofRandom(size);
            while (atY > ox + 40) {
                lines.addVertex(ox + size + ofRandom(-1 * accepted_deviation, accepted_deviation), atY);
                atY -= incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        
        
        lines.addVertex(ox + size, ox);
        if (ofRandom(1.f) > chance_change) {
            float atX = ox + size;
            int incr = ofRandom(size);
            while (atX > ox + 40) {
                lines.addVertex(atX, ox + ofRandom(-1 * accepted_deviation, accepted_deviation));
                atX -= incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        lines.addVertex(ox, ox);
        lines.close();
        lines.draw();
        lines.clear();
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
