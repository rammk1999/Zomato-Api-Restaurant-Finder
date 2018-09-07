#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDatGui.h"
#include "Requester.h"
#include "Restaurant.h"
#include <string>


class ofApp : public ofBaseApp {
	private:
	// initializes the application when it starts
	void setup();
	// called when certain variables need to be updated
	void update();
	// allows images, text, shapes to be displayed on screen
	void draw();

	ofImage cuisine_img;
	ofImage logo;
	ofSoundPlayer sound_player;
	Restaurant::Restaurant user_search;
	ofxDatGui* input_gui;
	ofxDatGui* output_gui;
	vector<string> cuisine_list;
	vector<string> cost_list;
		
	void initialize_cuisine_list();
	void initialize_cost_list();

	// chooses the correct sound file depending on the type of cuisine
	std::string choose_sound_file(Restaurant::Restaurant user_search);

	// chooses the correct image file depending on the type of cuisine
	std::string choose_image_file(Restaurant::Restaurant user_search);

	// sets the variables of the restaurant object that is passed to the request methods
	void on_dropdown_event(ofxDatGuiDropdownEvent select_inputs);

	// starts the search for the 
	void on_button_event(ofxDatGuiButtonEvent begin_search);

	// prints the restaurant name to the output_gui
	void draw_name(std::string name);

	// prints the address to the output_gui
	void draw_address(std::string address);
};