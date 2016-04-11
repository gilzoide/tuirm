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

#include "Widget.hpp"
#include "debug.hpp"

namespace tuirm {

// uses '1, 1' because curses windows gives error when creating with '0, 0'
Widget::Widget () : Widget (1, 1) {}


Widget::Widget (unsigned int width, unsigned int height) throw (tuirm::Exception)
	: width (width), height (height) {
	// Note here that ncurses uses "Y, X" on every function, and tuirm will use
	// "X, Y" as everyone else does =P
	win = newpad (height, width);
	if (!win) {
		throw TUIRM_API_EXCEPTION ("Widget::Widget",
				"Couldn't create curses window: ENOMEM");
	}
}


Widget::~Widget () {
	delwin (win);
	for (auto & child : children) {
		delete child;
	}
}

}
