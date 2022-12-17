#include "Loading.hpp"
#include "Entity.hpp"


bool Loader::load() {

	DrawFPS(100, 100);

	progressLoading = 0;

	/*======================================================*/

	// Add all Textures Here.

	BeginDrawing();

	ClearBackground(BLACK);

	

	textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	textureMap["Entity"] = std::make_shared<Texture2D>(LoadTexture("resources/KeplerEngineLogo.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));
	//textureMap["LoadingScreen"] = std::make_shared<Texture2D>(LoadTexture("resources/loadingscreen.png"));

	DrawTexture(*textureMap["LoadingScreen"], 600, 200, WHITE);



	EndDrawing();

	WaitTime(.5);

	/*======================================================*/

	//Add all music here.


		
	/*======================================================*/

	//Add all audio here.




	/*======================================================*/

	
	return true;



}

