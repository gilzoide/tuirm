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

/** @file StdLogger.hpp
 * _stdout_ and _stderr_ Logger
 */
#pragma once

#include <Logger.hpp>

#include <iostream>

using namespace std;

namespace tuirm {

/**
 * Logger that writes to _stdout_ and _stderr_
 */
class StdLogger : public Logger {
protected:
	/**
	 * Writes message to _stdout_ using `std::cout`
	 */
	void writeLog (const string& message) override;

	/**
	 * Writes message to _stderr_ using `std::cerr`
	 */
	void writeError (const string& message) override;
};

}
