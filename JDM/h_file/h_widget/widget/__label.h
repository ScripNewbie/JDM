#pragma once
#include "__drag.h"

class __Label : public __Widget, public __DragBehavior
{
public:
    int font_size;
    Uint8 R_color, G_color, B_color, A_color;
    bool Fwidth, Fheight;
    enum Valign
    {
        BOTTOM = 0,
        VCENTER,
        TOP
    };
    enum Halign
    {
        LEFT = 0,
        HCENTER,
        RIGHT
    };
    Valign valign = VCENTER;
    Halign halign = HCENTER;

public:
    __Label(const std::string &_text = "", const float width = 100.f,
            const float height = 100.f, const float x = 0.f, const float y = 0.f,
            const Uint8 r_color = 255, const Uint8 g_color = 255,
            const Uint8 b_color = 255, const Uint8 a_color = 255);
    ~__Label() { SDL_DestroyTexture(this->__texture); }

    void setRandomColor();
    void changeText(const std::string &text);
    void changeFont(const std::string &font);
    std::string getText() const;

protected:
    void setRect();
    void _render();
    void _update();
    void _l_m_down();
    void _l_m_motion();
    void _l_m_up();
    void _r_m_down();
    void _r_m_motion();
    void _r_m_up();

private:
    std::string __font;
    std::string __text;
    SDL_Texture *__texture;
    SDL_Rect __source;
    SDL_FRect __destination;

private:
    void __initVariables();
    void __setColor();
    void __setOpacity();
    void __changeLabel();
};