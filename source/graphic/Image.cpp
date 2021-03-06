#include <algorithm>
#include "Image.hpp"

Image::Image(std::string name, std::string sprite, std::string pallete)
    : DisplayObject(name), polygonId(0), _sprite(sprite), _pallete(pallete), _x(x), _y(y), _rotation(rotation), _scaleX(scaleX), _scaleY(scaleY), _layer(layer), _visible(visible), _flip(flip), _alpha(alpha)
{
    _type = "Sprite3D";
}

void Image::initialize() {
     std::cout << "create" << std::endl;
    NF_Create3dSprite(_id, Assets::get_sprite3D(_sprite), Assets::get_pallete3D(_pallete), x, y);

    validate();
}

void Image::validate() {
    // visibility update
    if (_visible != visible) {
        NF_Show3dSprite(_id, visible);
        _visible = visible;
        if (!_visible) return;
    }

    // update alpha
    if (_alpha != alpha) {
        if (polygonId == 0 && alpha != 100) {
            std::cout << "Change polygonId to use alpha" << std::endl;
        } else {
            std::cout << TransformObject::alpha(alpha) << std::endl;
            NF_Blend3dSprite(_id, polygonId, TransformObject::alpha(alpha));
            _alpha = alpha;
        }
    }

    // position update
    if (_x != x || _y != y) {
        NF_Move3dSprite(_id, x, y);
        _x = x;
        _y = y;
    }

    // rotation update
    if (_rotation != rotation || _flip != flip) {
        if (flip) NF_Rotate3dSprite(_id, 0, TransformObject::rotate(180), TransformObject::rotate(rotation));
        else NF_Rotate3dSprite(_id, 0, 0, TransformObject::rotate(rotation));
        _rotation = rotation;
        _flip = flip;
    }

    // scaling update
    if (_scaleX != scaleX || _scaleY != scaleY) {
        scaleX = std::clamp(static_cast<int>(scaleX), 0, 800);
        scaleY = std::clamp(static_cast<int>(scaleY), 0, 800);
        
        NF_Scale3dSprite(_id, TransformObject::scale(scaleX), TransformObject::scale(scaleY));
        _scaleX = scaleX;
        _scaleY = scaleY;
    }

    // depth update
    if (_layer != layer) {
        layer = std::clamp(static_cast<int>(layer), -512, 512);
        NF_3dSpriteSetDeep(_id, -layer);
        _layer = layer;
    }
}

void Image::preUpdate() {
    validate();

    Image::DisplayObject::preUpdate();
}

void Image::destroy() {
    NF_Delete3dSprite(_id);

    Image::DisplayObject::destroy();
}