#pragma once

#include <string>
#include "ofxJSON.h"

namespace Restaurant {
	class Restaurant
	{
	public:
		// constructors 
		Restaurant();
		Restaurant(std::string cuisine, int price_level);

		// setter methods
		void set_cuisine(std::string type);
		void set_price(int price_level);
		void set_name(std::string name);

		// getter methods
		int get_price();
		std::string get_name();
		std::string get_cuisine();

		// helper functions

		// This methods looks at the cuisine type and returns the corresponding zomato id for making a http request
		int cuisine_to_zomato_id();

		// This method looks at the price the user wants and sets parameters to sort the http response accordingly
		std::string price_to_zomato_sort(); 

		// This method looks through a json response and returns the name of the restaurant that most closely matches the request
		std::string find_best_restaurant_name(std::string json_body);

		// This method looks through a json response and returns the location of the restaurant that most closely matches the request
		std::string find_best_restaurant_location(std::string json_body);

		// This method checks whether or not a restaurant has been initialized and a search can be done
		bool is_valid_to_search();

	private:
		int price_;
		std::string name_;
		std::string cuisine_;
	};

} // namespace restaurant