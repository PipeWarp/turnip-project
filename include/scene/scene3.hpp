#pragma once

#include "NGMain.hpp"
#include "NGScene.hpp"

class scene3 : public NGScene {
    public:
        int i;
        Movieclip2D* mist;
        BMFont* font1;
    private:
    
    public:
        scene3();
        void initialize() override;
        void update() override;
    private:
};