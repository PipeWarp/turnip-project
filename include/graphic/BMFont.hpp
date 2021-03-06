#pragma once

#include "DisplayObject.hpp"
#include "Color.hpp"

class BMFont : public DisplayObject {
    public:
        std::string text;
        // uint16_t colorId;

    private:
        // uint16_t _colorId;
    
    public:
        BMFont(std::string _name, std::string _text);
        void preUpdate() override;
        void destroy() override;

        // static

        static void defineRGB(uint8_t _screen, uint16_t id, uint8_t r, uint8_t g, uint8_t b);
        static void defineHex(uint8_t _screen, uint16_t id, uint16_t hex);
        static void setColor(uint8_t _screen, uint16_t id);
    private:
};