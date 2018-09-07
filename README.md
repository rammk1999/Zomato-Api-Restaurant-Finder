# CS 126 Final Project (Restaurant Finder using Zomato API)
## Description
- This application will ask for a type of cuisine and the amount of money a user is willing to spend. 
- From these inputs, the application will return the name and address for the highest rated restaurant in the urbana-champaign area.
- This application returns restaurants based on the Zomato API. 
## Set Up
### Downloading ofx and libraries
- If you haven't done so already, download openframeworks and this git repository.
- You will also need to download two additionaly openframeworks libraries and install those correctly: ofxJSON and ofxDatGui.
### Editing library files
- Additionally, go into the ofxDatGui folder and edit the ofxDatGuiTheme.h file under src/themes. At the end of this file is a struct 
under a comment labeled "typography & icons"
- In this struct change the size variable to 10. This value controls the font size, and the default size is usually too small.
### Build/Run Details
- Use the project generator provided by openframeworks and import the the path to where the repository was downloaded.
- The addons should be automatically detected and the project can be opened in Visual Studio or another IDE, but another IDE may require additional steps. 
- You should then be able to run the project successfully. 
