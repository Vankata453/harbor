//  Harbor - A portable and highly customisable game engine
//  Copyright (C) 2021 Semphris <semphris@protonmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as
//  published by the Free Software Foundation, either version 3 of the
//  License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef _HEADER_HARBOR_VIDEO_RENDERER_HPP
#define _HEADER_HARBOR_VIDEO_RENDERER_HPP

#include <string>

#include "SDL.h"

class Blend;
class Color;
class Font;
class Rect;
class Texture;
class Vector;
class Window;

class Renderer
{
public:
  enum class Blend {
    NONE = SDL_BLENDMODE_NONE,
    BLEND = SDL_BLENDMODE_BLEND,
    ADD = SDL_BLENDMODE_ADD,
    MODULATE = SDL_BLENDMODE_MOD
  };

  enum class TextAlign
  {
    TOP_LEFT,
    TOP_MID,
    TOP_RIGHT,
    MID_LEFT,
    CENTER,
    MID_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_MID,
    BOTTOM_RIGHT
  };

protected:
  static SDL_Surface* get_font_surface(const Font& font,
                                       const std::string& text);

public:
  virtual ~Renderer() = default;

  virtual void draw_filled_rect(const Rect& rect, const Color& color,
                                const Blend& blend) = 0;
  virtual void draw_texture(const Texture& texture, const Rect& srcrect,
                            const Rect& dstrect, const Color& color,
                            const Blend& blend) = 0;
  virtual void draw_text(const std::string& text, const Vector& pos,
                         TextAlign align, const std::string& fontfile, int size,
                         const Color& color, const Blend& blend) = 0;
  virtual void start_draw(Texture* texture = nullptr);
  virtual void end_draw();

  bool is_drawing() const;

protected:
  Renderer();

private:
  bool m_drawing;

private:
  Renderer(const Renderer&) = delete;
  Renderer& operator=(const Renderer&) = delete;
};

#endif
