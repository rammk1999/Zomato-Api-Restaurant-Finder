# Project Development 
### 4/20/2018
- Starting to set up all my environments and begin working on the project. 
- Looked into web scraping and it seems pretty difficult to do quickly in C++.
- Started creating objects to represent the restaurants around campus. 
### 4/26/2018
- Trying to get a basic gui to pop up with drop down menu's for all the categories that I want. This is 
proving to be difficult, the gui displays but text is not displaying properly on the screen.
- Installing the proper libraries to parse JSON is giving me a lot of problems 
### 4/28/2018
- Installed a library called ofxJSON and created a class to make http requests.
- Had trouble understanding how I should structure the classes to use the libraries properly and 
interact with each other
- Encountered several random errors with Visual Studio and git
### 4/29/2018
- Wrote methods for the Requester class and more methods for the Restaurant class.
- ofxJSON has a unique way of return the values so it took some time to understand how to 
turn the values into objects
### 4/30/2018
- The zomato api doesn't allow the api key to be put into the request url and it must be specified as a header.
Trying to get the libraries to properly specify the header is proving really difficult. 
- Fixed an issue with ofxdatgui not being able to display any text.
- Had to change the proposal a little because the zomato api is not properly return a value 
for delivery. Every time I searched for a Restaurant with delivery the api would return values
indicating that even Restaurant like pizza hut and dominoes were not delivering. 
### 5/1/2018
- Successfully created a simple gui with various drop down menus, but had some trouble when I was trying 
to integrate the front end and back end. The documentation for ofxDatGui is very good however so I didn't lose 
much time. 
### 5/2/2018 
- Successfully integrated sounds into the application. It took some time to actually download the files and specify which files should be played, 
otherwise this part wasn't too difficult.
- Created another portion of the gui that displays the name and address on the actual application instead of printing to the console. Sometimes these restaurants'
names and addresses are too long for the gui to contain on the panel.
- I am trying to have an image be displayed to the ofApp when I try I make a restaurant search but the image is not showing up on screen. I didn't properly use the draw() and update()
default methdos provided by ofApp.
- Adding the finishing touches to make the gui look nicer and more sleek. 
