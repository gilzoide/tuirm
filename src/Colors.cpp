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

#include <Colors.hpp>
#include <ncurses.h>

namespace tuirm {

void initCursesColors () {
	const int cursesColors[] = {
		-1,
		COLOR_BLACK,
		COLOR_RED,
		COLOR_GREEN,
		COLOR_YELLOW,
		COLOR_BLUE,
		COLOR_MAGENTA,
		COLOR_CYAN,
		COLOR_WHITE
	};
	if (start_color () == ERR) {
		throw "Couldn't initialize colors!";
	}
	assume_default_colors (-1, -1);
	for (int i = 0; i < COLORS_STEP; i++) {
		for (int j = 0; j < COLORS_STEP; j++) {
			init_pair (i * COLORS_STEP + j, cursesColors[i], cursesColors[j]);
		}	
	}
}

}
