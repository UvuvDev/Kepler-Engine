#include "Loading.hpp"


bool Loader::load() {

	progressLoading = 0;

	/*======================================================*/

	// Add all Textures Here.

	textureMap["Entity"] = std::make_shared<Texture2D>(EntityTexture);

	/*======================================================*/

	//Add all music here.


		
	/*======================================================*/

	//Add all audio here.




	/*======================================================*/

	
	return true;



}

