#pragma once
#include "ofxJSON.h"
#include "Restaurant.h"
#include <string>
#include <map>


namespace Requester {
	class Requester {
		public:
		ofxJSONElement json;

		// A helper method that initializes parts of the http request in a map
		std::string url_builder(Restaurant::Restaurant user_preference);  

		// Makes a http get request to Zomato and returns the response as one continuous string in json format
		std::string make_request(std::string url); 

	private:
		std::map <std::string, std::string> parameters;
		std::string url = "https://developers.zomato.com/api/v2.1/search?entity_id=685&entity_type=city";
		// Builds a url based on the search parameters the user wants to use
		void initialize_map(Restaurant::Restaurant user_preference);

	};
}