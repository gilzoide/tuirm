/* tuirm, a ncurses based toolkit for writting console applications using C++11
 * Copyright (C) <2016> <gilzoide>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Any bugs should be reported to <gilzoide@gmail.com>
 */

/** @file Widget.hpp
 * UI widgets, what your app will mostly have
 */
#pragma once

#include "Exception.hpp"

#include <ncurses.h>
#include <vector>

using namespace std;

namespace tuirm {

/**
 * UI widgets, a rectangle that shows something, and react to Input
 */
class Widget {
public:
	/**
	 * Ctor without window size
	 */
	Widget ();
	/**
	 * Ctor: with size
	 *
	 * Curses Window (pad) is created, sized 'width x height'
	 *
	 * @param width Widget width, in chars
	 * @param height Widget height, in chars
	 */
	Widget (unsigned int width, unsigned int height) throw (tuirm::Exception);

	/**
	 * Dtor
	 *
	 * Deletes curses window and associated children
	 */
	virtual ~Widget ();

	/**
	 * GETTER for width
	 */
	unsigned int getWidth ();
	/**
	 * GETTER for height
	 */
	unsigned int getHeight ();

	/**
	 * Resize a Widget to absolute size 'newWidth, newHeight'
	 *
	 * This method resizes Widgets to a minimum '1, 1' size
	 *
	 * @param newWidth The new total width
	 * @param newHeight The new total height
	 */
	void resizeTo (unsigned int newWidth, unsigned int newHeight);
	/**
	 * Resize a Widget to absolute size:
	 *  'oldWidth + deltaWidth, oldHeight + deltaHeight'
	 *
	 * To shrink the Widget, use negative deltas.
	 * This method shrinks Widgets to a minimum '1, 1' size
	 *
	 * @param deltaWidth Width increment
	 * @param deltaHeight Height increment
	 */
	void resizeBy (int deltaWidth, int deltaHeight);

	/**
	 * Add a child Widget
	 *
	 * @note This method doesn't check for nullptr, be sure to pass a valid
	 *  object
	 */
	void addChild (Widget *child);

protected:
	/**
	 * Curses window
	 */
	WINDOW *win;

	/// Children Widgets
	vector<Widget *> children;

	/// Widget's width
	unsigned int width;
	/// Widget's height
	unsigned int height;
};

}
