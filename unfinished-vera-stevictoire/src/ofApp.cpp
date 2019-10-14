#include "ofApp.h"

#define BUCKETS_SIZE 200
float buckets[BUCKETS_SIZE];

int bucketCounter = 0;
void updateBuckets() {
    bucketCounter += 1;
    for (int i = 0; i < BUCKETS_SIZE; i++) {
        buckets[i] = ofMap(ofNoise(i * 0.1, bucketCounter * 0.1), -1, 1, 0, ofGetHeight());
    }
}


//--------------------------------------------------------------
void ofApp::setup(){
/*
    int appHeight = ofGetHeight();
    int delta = ofRandom(0.3);
    buckets[0] = appHeight / 2;
    for (int i = 1; i < BUCKETS_SIZE; i++) {
        if (ofNoise(i * 0.02) > 0.7) {
            delta = ofRandom(0.3);
        }
        if (buckets[i - 1] > appHeight - 100) {
            delta *= -1;
        }
        if (buckets[i - 1] < 100) {
            delta *= -1;
        }
        buckets[i] = buckets[i - 1] + delta;
        cout << "buckets[i]" << i << buckets[i] << endl;
    }
*/
    updateBuckets();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------

ofPolyline line;

void ofApp::draw(){
    /*
    
    int appWidth = ofGetWidth();
    int appHeight = ofGetHeight();
    
    for (int i = 0; i < appWidth; i++) {
        float bucketValue = buckets[i * (appWidth / BUCKETS_SIZE)];
        ofDrawRectangle(i, bucketValue, 2, 2);
    }
     */
    ofBackground(40);
    ofSeedRandom(0);
    
    for (int k = 0; k < 7; k++) {
        int width = ofGetWidth();
        for (int i = 0; i < width; i += 10) {
            // 100 * ofNoise(i * 0.001) + 100
            //line.addVertex(ofVec3f(i + ofRandom(5), buckets[i/(15*3)] + (ofNoise(i * 0.002, k * 0.02 + mouseX * 0.01) * 80), 0));
            line.addVertex(i + ofNoise(i * 0.001 + k * 0.01), buckets[i / (15 * 3)] + ofRandom(20));
        }
        line.setClosed(false);
        line.draw();
        line.clear();
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
    updateBuckets();
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
