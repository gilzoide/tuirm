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

/** @file App.hpp
 * The App definition
 */
#pragma once

#include "Logger.hpp"
#include "Widget.hpp"
#include "Exception.hpp"

#include <ncurses.h>
#include <lap/lap.hpp>

namespace tuirm {

/**
 * Tuirm's App class
 *
 * @warning Everything in _tuirm_ is based around having one and only App
 *  object, so please don't go crazy thinking having 2 will work =P
 */
class App {
public:
	/**
	 * Default Ctor
	 *
	 * Initializes curses
	 */
	App ();
	/**
	 * Ctor using command line arguments
	 *
	 * @note we use references to the arguments, so that we can extract tuirm's
	 *  command line options
	 *
	 * @throw lap::Exception with command line options errors
	 */
	App (int& argc, char **& argv) throw (tuirm::Exception, lap::Exception);

	/**
	 * Dtor: closes app logger
	 */
	~App ();

	/**
	 * GETTER for application logger
	 */
	Logger *getLogger ();

	/**
	 * SETTER for the root widget
	 *
	 * @warning This only overrides the stored pointer, so if you change an
	 *  existing one, you must take care of freeing it. App only frees the
	 *  stored pointer
	 *
	 * @return Old Widget pointer
	 */
	Widget *setRoot (Widget *newRoot);

	/**
	 * Run application main loop
	 *
	 * This function ends when @ref close is called
	 */
	void run ();

	/**
	 * Pause the application, closing ncurses, but not ending the main loop
	 *
	 * @sa resume
	 */
	void pause ();

	/**
	 * Resume the application, restoring ncurses
	 *
	 * @note Calling this without pausing the App doesn't do anything
	 *
	 * @sa pause
	 */
	void resume ();

	/**
	 * Close the application, ending ncurses windowing
	 */
	void close ();

protected:
	/**
	 * Initialize the application, starting curses stuff
	 */
	void initCurses ();

	/**
	 * Boolean indicating if main loop should continue running
	 */
	bool mainLoop;

	/**
	 * Application's logger
	 */
	Logger *logger {nullptr};

	/**
	 * Root Widget: a Panel
	 */
	Widget *root {nullptr};
};

}
