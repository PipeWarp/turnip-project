#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

#include <nds.h>
#include <nf_lib.h>

#include "simplenfl.hpp"
#include "Sound.hpp"
#include "STween.hpp"
#include "Random.hpp"
#include "Assets.hpp"
#include "TransformObject.hpp"
#include "SaveGame.hpp"

class NGObject {
    public:
        // int x;
		// int y;
		// int rotation;
		// int scaleX;
		// int scaleY;
		// int layer;
		// int frame;
		// int delay;
		// ObjectBound bound;
		uint8_t screen;
		bool enableUpdate;
		// bool enableAnimation;

		static int objectNum;
    protected:
        // int _x;
		// int _y;
		// int _rotation;
		// int _scaleX;
		// int _scaleY;
		// int _layer;
		// int _frame;

		// std::map<std::string, std::vector<int>> _animationData;
		// std::string _currentPlay;
		// int _currentFrame;
		// int _currentDelay;

		std::string _name;
		// uint16_t _sprite;
		// uint16_t _pallete;
		uint16_t _id;
    
    public:
        // NGObject(std::string name, uint16_t sprite, uint16_t pallete);
        NGObject(std::string name);
		virtual ~NGObject();
        
        // void draw(uint16_t id);
		virtual void preUpdate();

		virtual void initialize();
        virtual void update();
		
        virtual void destroy();

        // Animation stuff
        // void addAnimation(std::string name, std::vector<int> frames);
        // void updateAnimation(std::string name, std::vector<int> frames);
        // void removeAnimation(std::string name);
        // void clearAnimation(std::string name);
        // void quickPlay(std::vector<int> frames, int frameskip = 0);
        // void play(std::string name, int frameskip = 0);
        // void stop(std::string name);
        // void reset();

		// Touch
		// bool getTouch(KeyPhase phase);

        // Get && Set
        std::string get_name();

		void set_id(uint16_t id);
        uint16_t get_id();
    private:
};