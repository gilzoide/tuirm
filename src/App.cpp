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
#include <App.hpp>
#include <Colors.hpp>

using namespace std;

namespace tuirm {

App::App () {
	initCurses ();
}


void App::initCurses () {
	initscr ();
	keypad (stdscr, TRUE);
	cbreak ();
	noecho ();
	initCursesColors ();
}


void App::run () {
	int c = 0;

	mainLoop = true;
	while (mainLoop) {
		c = getch ();
		if (c == 'q') {
			close ();
		}
		else {
			attron (COLOR_PAIR (BkBl));
			addstr ("Clicked something. 'q' to quit\n");
		}
	}
}


void App::close () {
	endwin ();
	mainLoop = false;
}

}
