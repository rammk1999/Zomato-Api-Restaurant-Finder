#include "Restaurant.h"

// constructors //
Restaurant::Restaurant::Restaurant() {
	price_ = 0; //1-4
	name_ = "";
	cuisine_ = "";
}

Restaurant::Restaurant::Restaurant(std::string cuisine, int price_level) {
	price_ = price_level;
	name_ = "";
	cuisine_ = cuisine;
}

// setter methods //
void Restaurant::Restaurant::set_cuisine(std::string type) {
	Restaurant::cuisine_ = type;
}

void Restaurant::Restaurant::set_price(int price_level) {
	Restaurant::price_ = price_level;
}

void Restaurant::Restaurant::set_name(std::string name) {
	Restaurant::name_ = name;
}

// getter methods //
int Restaurant::Restaurant::get_price() {
	return Restaurant::price_;
}

std::string Restaurant::Restaurant::get_cuisine() {
	return Restaurant::cuisine_;
}

std::string Restaurant::Restaurant::get_name() {
	return Restaurant::name_;
}

// helper methods
// This methods looks at the cuisine type and returns the corresponding zomato id for making a http request
int Restaurant::Restaurant::cuisine_to_zomato_id() {
	if (cuisine_ == "American") {
		return 1;
	}
	else if (cuisine_ == "Asian") {
		return 3;
	}
	else if (cuisine_ == "Burger") {
		return 168;
	}
	else if (cuisine_ == "Chinese") {
		return 25;
	}
	else if (cuisine_ == "Desserts") {
		return 100;
	}
	else if (cuisine_ == "Fast Food") {
		return 40;
	}
	else if (cuisine_ == "French") {
		return 45;
	}
	else if (cuisine_ == "German") {
		return 134;
	}
	else if (cuisine_ == "Greek") {
		return 156;
	}
	else if (cuisine_ == "Indian") {
		return 148;
	}
	else if (cuisine_ == "Italian") {
		return 55;
	}
	else if (cuisine_ == "Japanese") {
		return 60;
	}
	else if (cuisine_ == "Korean") {
		return 67;
	}
	else if (cuisine_ == "Mediterranean") {
		return 70;
	}
	else if (cuisine_ == "Mexican") {
		return 73;
	}
	else if (cuisine_ == "Pizza") {
		return 82;
	}
	else if (cuisine_ == "Spanish") {
		return 89;
	}
	else if (cuisine_ == "Steak") {
		return 141;
	}
	else if (cuisine_ == "Sushi") {
		return 177;
	}
	else if (cuisine_ == "Thai") {
		return 95;
	}
	else if (cuisine_ == "Vietnamese") {
		return 99;
	}
}

// This method looks at the price the user wants and sets parameters to sort the http response accordingly
std::string Restaurant::Restaurant::price_to_zomato_sort() {
	if (price_ > 2) {
		return "desc";
	}
	else {
		return "asc";
	}
}

// This method looks through a json response and returns the name of the restaurant that most closely matches the request
std::string Restaurant::Restaurant::find_best_restaurant_name(std::string json_body) {
	ofxJSONElement parser(json_body);
	return parser["restaurants"][0]["restaurant"]["name"].asString();
}

// This method looks through a json response and returns the location of the restaurant that most closely matches the request
std::string Restaurant::Restaurant::find_best_restaurant_location(std::string json_body) {
	ofxJSON parser(json_body);
	return parser["restaurants"][0]["restaurant"]["location"]["address"].asString();
}

// This method checks whether or not a restaurant has been initialized and a search can be done
bool Restaurant::Restaurant::is_valid_to_search() {
	if ((price_ == 0 || cuisine_ == "") && name_ == "") {
		return false;
	}
	return true;
}
