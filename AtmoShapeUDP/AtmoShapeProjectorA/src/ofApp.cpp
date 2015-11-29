#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // we run at 60 fps!
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    // create the socket and bind to port 3000
    udpConnection.Create();
    udpConnection.Bind(3000);
    udpConnection.SetNonBlocking(true);

    // load videos
    toTheSea.loadMovie("toTheSea.mkv");
    toAnotherLocation.loadMovie("toAnotherLocation.mkv");
    behindTheWalls.loadMovie("behindTheWalls.mkv");

}

//--------------------------------------------------------------
void ofApp::update(){
    char udpMessage[100000];
    udpConnection.Receive(udpMessage, 100000);
    string message = udpMessage;
    if (message != "") {
        if (message == "toTheSea") {
            currentVideo = toTheSea;
            toAnotherLocation.stop();
            behindTheWalls.stop();
        } else if (message == "toAnotherLocation") {
            currentVideo = toAnotherLocation;
            toTheSea.stop();
            behindTheWalls.stop();
        } else if (message == "behindTheWalls") {
            currentVideo = behindTheWalls;
            toTheSea.stop();
            toAnotherLocation.stop();
        }
        currentVideo.play();
    }
    // Decode the new frame if needed
    currentVideo.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    currentVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f' || key == 'F') {
        ofToggleFullscreen();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
