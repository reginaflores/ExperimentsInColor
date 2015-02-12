#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    //initialize variables
    num = 500;
    boxWidth = 600;
    boxHeight = 400;
    boxDepth = 500;
    speedRotate = 0.16;

    
    
    p.loadImage("flower1.jpg");
    
    //read in all the pixels from the image
    for(int x = 0; x < p.width; x++){
        for(int y = 0; y < p.height; y++){
            ofColor currentColor;
            colors.push_back(p.getColor(x, y));
            
            currentColor = p.getColor(x, y);
            pixels.push_back((currentColor.r+ currentColor.g + currentColor.b));
            
            //cout<<pixels[y]<<endl;
            //cout<<pixels.size()<<endl;
        }
        
    }
    
    
    //Binning the Values
    //Create a counter
    bins.resize(768); //256*3
    for(int i = 0; i < pixels.size(); i++){
        
        int index = pixels[i];
        bins[index] ++;
        //cout<<index<<endl;
        //cout<<bins.size()<<endl;
    }

    
    //////////////////////////
    //Gui Setup
    gui = new ofxUICanvas();
    
    gui->addLabel("Adjust the fields");
    gui->addLabel("and press spacebar");
    gui->addLabel("to update");

    gui->addSlider("Rotation", 0, 0.5, &speedRotate);
    
    gui-> autoSizeToFitWidgets();
    /////////////////////////

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::refresh(){
    

}
//--------------------------------------------------------------
void ofApp::draw(){
    

    cam.begin();
    
    //ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    
    //rotate the cam
    ofRotate(ofGetFrameNum()*speedRotate, 0, 1, 0);
    
    ofNoFill();
    //ofDrawBox(0, 0, 0, 200, 200, 200);
    ofSetColor(255,255,255,100);
    ofDrawBox(0, 0, 0, boxWidth, boxHeight, boxDepth);//3D box centered in screen
    ofTranslate(-boxWidth/2, -boxHeight/2, -boxDepth/2);
    
    for(int i= 0; i < colors.size(); i++){
        ofSetColor(colors[i].r, colors[i].g, colors[i].b);
        ofCircle(colors[i].r, colors[i].g, colors[i].b, 5);
    }
    
    
    cam.end();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
