//  Harbor - A portable and highly customisable game engine
//  Copyright (C) 2021 A. Semphris <semphris@protonmail.com>
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

#ifndef _HEADER_HARBOR_VIDEO_SDL_SDLWINDOW_HPP
#define _HEADER_HARBOR_VIDEO_SDL_SDLWINDOW_HPP

#include "video/window.hpp"

#include "SDL.h"

class SDLWindow :
  public Window
{
public:
  SDLWindow();
  virtual ~SDLWindow();

  virtual std::string get_title() const override;
  virtual void set_title(const std::string& title) override;

private:
  SDL_Window* m_window;

private:
  SDLWindow(const SDLWindow&) = delete;
  SDLWindow& operator=(const SDLWindow&) = delete;
};

#endif
