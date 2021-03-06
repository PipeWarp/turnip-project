#include "scene3.hpp"

scene3::scene3() {

}

TextBox* text1;

void scene3::initialize() {
    // videoSetMode(MODE_0_2D);
	// consoleInit(NULL, consoleGetDefault()->bgLayer, BgType_Text4bpp, BgSize_T_256x256, consoleGetDefault()->mapBase, consoleGetDefault()->gfxBase, true, true);

    std::cout << "scene 3 initialized" << std::endl;

    std::string capital = "";
    capital += "A  B  C  D  E  F  G  H||I  J  K  L  M  N  O  P||Q  R  S  T  U  V  W  X||Y  Z";

    text1 = new TextBox("text1", "", 0, 0);
    // text1->x = 8;
    text1->set_text(capital);
    addChild(text1);
    
    std::for_each(capital.begin(), capital.end(), [](char & c){
        c = ::tolower(c);
    });

    TextBox* text2 = new TextBox("text2", "", 0, 0);
    // text2->x = 8;
    text2->y = 8*8 + 2*8;
    text2->set_text(capital);
    addChild(text2);

    BMFont* result = new BMFont("result", "");
    result->y = 10*8 + 8*8 + 2*8;
    addChild(result);

}


std::string baseCapital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void scene3::update() {
    
    for (uint x=0; x<8; x++) {
        for (uint y=0; y<4; y++) {

            if (SNF::getTouchRect(x*8 + x*2*8 - 3, y*8 + y*8 - 3, 8 + 3, 8 + 3, KeyPhase::release)) {
                reinterpret_cast<BMFont*>(getChildByName("result"))->text += baseCapital.at(x + y*8);
            }

            if (SNF::getTouchRect(x*8 + x*2*8 - 3, y*8 + y*8 + (8*8 + 2*8) - 3, 8 + 3, 8 + 3, KeyPhase::release)) {
                reinterpret_cast<BMFont*>(getChildByName("result"))->text += std::tolower(baseCapital.at(x + y*8), std::locale());
            }

        }
    }

    if (SNF::getKeys(Key::B, KeyPhase::release)) {
        std::string* text = &reinterpret_cast<BMFont*>(getChildByName("result"))->text;
        if (!text->empty()) text->pop_back();
    }

}