#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    p.loadImage("flower1.jpg");
    
    //read in all the pixels from the image
    for(int x = 0; x < p.width; x++){
        for(int y = 0; y < p.height; y++){
            ofColor currentColor;
            colors.push_back(p.getColor(x, y));
           
            currentColor = p.getColor(x, y);
            pixels.push_back(currentColor.r + currentColor.g + currentColor.b);
            
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
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
   
    ofSetColor(0);
    for(int i= 0; i < bins.size(); i++){
        
         ofCircle(i, ofMap(bins[i], 0, 2500, 0, ofGetScreenHeight()), 2);
        //cout<<bins[i]<<"  "<<i <<endl;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
