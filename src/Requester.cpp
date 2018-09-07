#include "Requester.h"

// Builds a url based on the search parameters the user wants to use
std::string Requester::Requester::url_builder(Restaurant::Restaurant user_input) {
	std::string unique_url = url;
	Requester::initialize_map(user_input);
	for (std::pair<std::string, std::string> pair : parameters) {
		unique_url = unique_url + pair.first + pair.second;
	}
	return unique_url;
}

// A helper method that initializes parts of the http request in a map
void Requester::Requester::initialize_map(Restaurant::Restaurant user_input) {
	parameters.insert(std::pair<std::string, std::string>("&cuisines=", std::to_string(user_input.cuisine_to_zomato_id())));
	parameters.insert(std::pair<std::string, std::string>("&sort=", "cost"));
	parameters.insert(std::pair<std::string, std::string>("&order=", user_input.price_to_zomato_sort()));
}

// Makes a http get request to Zomato and returns the response as one continuous string in json format
std::string Requester::Requester::make_request(std::string url) {
	ofHttpRequest request;
	request.headers["Accept"] = "application/json";
	request.headers["user-key"] = "cd7b6b1eef1d170a033b86bb61e37df7";
	request.url = url;
	ofURLFileLoader loader;
	ofHttpResponse response = loader.handleRequest(request);
	std::string json_response = response.data.getText();
	return json_response;
}
