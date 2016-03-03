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

/** @file Logger.hpp
 * A logger, with child classes for multiple possible outputs. Tuirm apps will
 * have a default logger (static instance), that tuirm API uses for debug/error.
 */
#pragma once

#include <App.hpp>

#include <string>

using namespace std;

namespace tuirm {

/**
 * Abstract class for Loggers
 *
 * Children __must__ implement the @ref writeLog and @ref writeError functions
 */
class Logger {
	/**
	 * App is a friend, so that it can create/delete it's default Logger
	 * @sa appLogger
	 */
	friend class App;
public:
	/**
	 * Log something
	 *
	 * Internally, calls @ref writeLog if minVerbosity is satisfied
	 *
	 * @param message The message which will be logged
	 * @param minVerbosity Minimum verbosity needed to be set in Logger for
	 *  'message' to be logged
	 */
	void log (const string& message, int minVerbosity = 0);

	/**
	 * Log an error
	 *
	 * Like @ref log, Internally, calls @ref writeError if minVerbosity is
	 * satisfied
	 *
	 * @param message The message which will be logged
	 * @param minVerbosity Minimum verbosity needed to be set in Logger for
	 *  'message' to be logged
	 */
	void error (const string& message, int minVerbosity = 0);

	/**
	 * Return App's default Logger
	 *
	 * @return appLogger
	 */
	static Logger *getAppLogger ();

	/**
	 * Dtor, virtual so that this class can really be a virtual class
	 */
	virtual ~Logger ();

protected:
	/**
	 * Method that properly writes a log message into some output channel
	 *
	 * @note Any children __must__ implement this method, as it is the one who
	 *  properly logs stuff
	 *
	 * @param message The message to be written
	 */
	virtual void writeLog (const string& message) = 0;
	/**
	 * Method that properly writes an error message into some output channel
	 *
	 * @note Any children __must__ implement this method, as it is the one who
	 *  properly logs stuff
	 *
	 * @param message The message to be written
	 */
	virtual void writeError (const string& message) = 0;

	/**
	 * Logger verbosity level
	 *
	 * Verbosity determines which messages are to be logged
	 */
	int verbosity {0};

private:
	/**
	 * App's default Logger
	 */
	static Logger *appLogger;
};

}
