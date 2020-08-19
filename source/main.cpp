#include <iostream>

#include <nds.h>
#include <nf_lib.h>

#include "NGMain.hpp"
#include "Assets.hpp"

#include "scene2.hpp"
#include "scene3.hpp"

int main() {


	NGMain* game = new NGMain(1, false);
	
	// Assets::load3dSprite("new/mist", "mist", 0, 64, 128, false);
	// Assets::load3dPallete("new/mist", "mist", 0);

	NF_LoadTiledBg("new/bg", "nfl", 256, 256);
	
	game->set_mainScene(new scene2());
	game->set_subScene(new scene3());

	while(1) {
		game->update();
	}

	return 0;

}