#include "ofApp.h"
#include "Requester.h"
#include "Restaurant.h"

// Starts the app with some predefined settings
void ofApp::setup()
{
	ofSetWindowPosition(0, 0);
	ofSetBackgroundColor(ofColor::white);

	// configure the gui that will take user input
	input_gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	input_gui->addHeader("# Find the Best Restaurant #");
	input_gui->setTheme(new ofxDatGuiThemeWireframe());
	input_gui->addBreak();

	// instantiate the drop down menus
	initialize_cuisine_list();
	input_gui->addDropdown("Select a Cuisine", cuisine_list);
	input_gui->onDropdownEvent(this, &ofApp::on_dropdown_event);
	input_gui->addBreak();
	initialize_cost_list();
	input_gui->addDropdown("Select a Cost Level", cost_list);
	input_gui->onDropdownEvent(this, &ofApp::on_dropdown_event);
	input_gui->addBreak();

	// add a button to commence the search
	input_gui->addButton("Search for Restaurant");
	input_gui->getButton("Search for Restaurant")->onButtonEvent(this, &ofApp::on_button_event);
	input_gui->addBreak();

	// configure the gui that will return the name and address of the best restaurant
	output_gui = new ofxDatGui((ofGetWindowWidth() *6) / 13, ofGetWindowHeight() - (ofGetWindowHeight() / 3)); // sets the general position
	output_gui->addHeader("# The Best Restaurant #");
	output_gui->setTheme(new ofxDatGuiThemeWireframe());
	output_gui->addBreak();
	output_gui->addLabel("Name: ");
	output_gui->addLabel("Address: ");

	cuisine_img.load("restaurant.png");
	logo.load("logo.png");

	user_search = Restaurant::Restaurant();
}

// Helps change cuisine_img when its value is changed to another file, called automatically by ofApp
void ofApp::update() {
	logo.update();
	cuisine_img.update();
}

// Puts the logo and cuisine_img on the screen, called automatically by ofApp
void ofApp::draw() {
	logo.draw(((ofGetWindowWidth() *2) / 5), ofGetWindowHeight() - ((ofGetWindowWidth()*2)/ 3));
	cuisine_img.draw(ofGetWindowWidth() / 2, ofGetWindowHeight() / 3, 250, 200);
}

// When a search parameter is selected, the user_search Restaurant object is updated to reflect the inputs
void ofApp::on_dropdown_event(ofxDatGuiDropdownEvent input){
	if (input.target->is("Select a Cuisine")) {
		user_search.set_cuisine(cuisine_list[input.child]);
	}
	else if (input.target->is("Select a Cost Level")) {
		sound_player.load("cash.mp3");
		sound_player.play();
		user_search.set_price(input.child + 1);
	}
}

// When the user hits the search button, a http request is made and the best responses are displayed in output_gui
void ofApp::on_button_event(ofxDatGuiButtonEvent search) {
	if (search.target->is("Search for Restaurant")) {
		if (user_search.is_valid_to_search()) {
			Requester::Requester requester;
			std::string url = requester.url_builder(user_search);
			std::string json_response = requester.make_request(url);

			draw_name(user_search.find_best_restaurant_name(json_response));
			draw_address(user_search.find_best_restaurant_location(json_response));

			sound_player.load(ofApp::choose_sound_file(user_search));
			cuisine_img.load(ofApp::choose_image_file(user_search));
			sound_player.play();
		}
		else {
			sound_player.load("sad.mp3");
			sound_player.play();
			draw_name("Invalid Search");
			draw_address("Invalid Search");
			cuisine_img.load("restaurant.png");
		}
	}
}

// displays the name of the best restaurant
void ofApp::draw_name(std::string name) {
	output_gui->getLabel("Name: ")->setLabel(name);
}

// displays the address of the best restaurant
void ofApp::draw_address(std::string address) {
	output_gui->getLabel("Address: ")->setLabel(address);
}

// populates the cost drop down menu
void ofApp::initialize_cost_list() {
	cost_list.push_back("Cheap");
	cost_list.push_back("Inexpensive");
	cost_list.push_back("Moderate");
	cost_list.push_back("Costly");
}

// populates the cuisine drop down menu
void ofApp::initialize_cuisine_list() {
	cuisine_list.push_back("American");  
	cuisine_list.push_back("Asian");  
	cuisine_list.push_back("Burger"); 
	cuisine_list.push_back("Chinese"); 
	cuisine_list.push_back("Desserts");  
	cuisine_list.push_back("Fast Food"); 
	cuisine_list.push_back("French"); 
	cuisine_list.push_back("German"); 
	cuisine_list.push_back("Greek"); 
	cuisine_list.push_back("Indian");
	cuisine_list.push_back("Italian");
	cuisine_list.push_back("Japanese"); 
	cuisine_list.push_back("Korean");
	cuisine_list.push_back("Mediterranean"); 
	cuisine_list.push_back("Mexican"); 
	cuisine_list.push_back("Pizza"); 
	cuisine_list.push_back("Spanish"); 
	cuisine_list.push_back("Steak");  
	cuisine_list.push_back("Sushi"); 
	cuisine_list.push_back("Thai"); 
	cuisine_list.push_back("Vietnamese"); 
}

// chooses the correct sound file depending on the type of cuisine
std::string ofApp::choose_sound_file(Restaurant::Restaurant user_search) {
	if (user_search.get_cuisine() == "American") {
		return "fiddle.wav";
	}
	else if (user_search.get_cuisine() == "Asian" || user_search.get_cuisine() == "Chinese" ||
		user_search.get_cuisine() == "Vietnamese" || user_search.get_cuisine() == "Thai" || user_search.get_cuisine() == "Korean") {
		return "gong.wav";
	}
	else if (user_search.get_cuisine() == "Burger" || user_search.get_cuisine() == "Steak") {
		return "burger.wav";
	}
	else if (user_search.get_cuisine() == "Sushi" || user_search.get_cuisine() == "Japanese") {
		return "sakura.mp3";
	} 
	else if (user_search.get_cuisine() == "Desserts") {
		return "candy.wav";
	}
	else if (user_search.get_cuisine() == "Fast Food") {
		return "fast_food.mp3";
	} 
	else if (user_search.get_cuisine() == "French" || user_search.get_cuisine() == "Italian") {
		return "french.mp3";
	}
	else if (user_search.get_cuisine() == "German") {
		return "german.mp3";
	}
	else if (user_search.get_cuisine() == "Greek" || user_search.get_cuisine() == "Mediterranean") {
		return "greek.mp3";
	}
	else if (user_search.get_cuisine() == "Mexican" || user_search.get_cuisine() == "Spanish") {
		return "mariachi.mp3";
	}
	else if (user_search.get_cuisine() == "Pizza") {
		return "pizza.mp3";
	}
	else if (user_search.get_cuisine() == "Indian") {
		return "indian.wav";
	}
}

// chooses the correct image file depending on the type of cuisine
std::string ofApp::choose_image_file(Restaurant::Restaurant user_search) {
	if (user_search.get_cuisine() == "American") {
		return "american.png";
	}
	else if (user_search.get_cuisine() == "Burger") {
		return "burger.png";
	}
	else if (user_search.get_cuisine() == "Chinese" || user_search.get_cuisine() == "Asian" || user_search.get_cuisine() == "Vietnamese") {
		return "chinese.png";
	}
	else if (user_search.get_cuisine() == "Desserts") {
		return "dessert.png";
	}
	else if (user_search.get_cuisine() == "Fast Food") {
		return "fast.png";
	}
	else if (user_search.get_cuisine() == "French") {
		return "french.png";
	}
	else if (user_search.get_cuisine() == "German") {
		return "german.png";
	}
	else if (user_search.get_cuisine() == "Italian") {
		return "pasta.png";
	}
	else if (user_search.get_cuisine() == "Indian") {
		return "india.png";
	}
	else if (user_search.get_cuisine() == "Greek" || user_search.get_cuisine() == "Mediterranean") {
		return "gyro.png";
	}
	else if (user_search.get_cuisine() == "Korean") {
		return "korean.png";
	}
	else if (user_search.get_cuisine() == "Mexican") {
		return "mexican.png";
	}
	else if (user_search.get_cuisine() == "Pizza") {
		return "pizza.png";
	}
	else if (user_search.get_cuisine() == "Spanish") {
		return "spanish.png";
	}
	else if (user_search.get_cuisine() == "Steak") {
		return "steak.png";
	}
	else if (user_search.get_cuisine() == "Sushi" || user_search.get_cuisine() == "Japanese") {
		return "sushi.png";
	}
	else if (user_search.get_cuisine() == "Thai") {
		return "thai.png";
	}
}