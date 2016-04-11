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

/** @file Builder.hpp
 * Tuirm Widget Builder, from a string or file
 */
#pragma once

#include "Widget.hpp"

#include <string>

using namespace std;

namespace tuirm {

/**
 * Widget Builder, from a string or file
 *
 * This is a pure virtual class, that any Widget Builder should extend.
 */
class Builder {
public:
	/**
	 * Build a Widget tree from a file
	 *
	 * @param file File name
	 *
	 * @return Built Widget tree
	 */
	virtual Widget *loadFile (const string& file) = 0;

	/**
	 * Build a Widget directly from a string
	 *
	 * @param input Input string
	 *
	 * @return Built Widget tree
	 */
	virtual Widget *loadString (const string& input) = 0;

	/**
	 * Dtor
	 */
	virtual ~Builder () {};
};

}
