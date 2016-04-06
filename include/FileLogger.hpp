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

/** @file FileLogger.hpp
 * Logger that writes to a file
 */
#pragma once

#include <Logger.hpp>

#include <fstream>

using namespace std;

namespace tuirm {

/**
 * Logger that writes to a file
 */
class FileLogger : public Logger {
public:
	/**
	 * Ctor: initializes the file
	 */
	FileLogger (const string& fileName);

	/**
	 * Dtor: closes the file
	 */
	~FileLogger ();

protected:
	/**
	 * Writes message to the file, prefixed with "LOG: "
	 */
	void writeLog (const string& message) override;

	/**
	 * Writes message to the file, prefixed with "ERROR: "
	 */
	void writeError (const string& message) override;

	/**
	 * Output file
	 */
	ofstream file;
};

}
