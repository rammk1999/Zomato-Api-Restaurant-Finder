# Project Proposal
## Restaurant Finder
### Summary:
For this project I want to create an application that will give me the best restaurant in champaign
based on a few inputs. These inputs will be price and the type of food I want (asian, pizza, italian, etc.). 
When the app is opened I want each category to be displayed, with something resembling a drop down 
menu for each category. I will use the zomato api to search for restaurants in the champaign area. 
Additionally, I want my application to have audio. For example, sounds that pertain to 
what category a user is searching through. If a user is choosing the price, as soon as 
they click, my app would make a cash-register sound. Or if they choose mexican cuisine 
I would play spanish music.
### Libraries/APIs:
#### Zomato https://developers.zomato.com/documentation
The Zomato api will help me quickly look for restaurnts by making a HTTP GET request and receiveing the 
response as as json string which I will have to parse. 
#### ofxJSON and JSONcpp https://github.com/jeffcrouse/ofxJSON
ofxJSON is a library this is built around another popular c++ library called JSONcpp. ofxJSON will allow 
me to easily work with the zomato api as I need to make a get request to the api and prase the json 
response. ofxJSON allows me to easily do this in one simple step. 
#### ofxDatGui https://github.com/braitsch/ofxDatGui
This another open frameworks library that is modeled after a popular gui format called DatGui. 
This library is also especially important because it easily implements drop down menus. I want 
to use drop down menus to help the user select their input parameters. 
