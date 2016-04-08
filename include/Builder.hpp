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
 * Tuirm Widget builder, using [YAML](http://www.yaml.org) files
 */
#pragma once

#include "Widget.hpp"

#include <string>

using namespace std;

namespace tuirm {

namespace Builder {
	/**
	 * Build a Widget tree from a YAML file
	 *
	 * To build a tuirm app with yaml, there must be a 'root' key, with value
	 *  as the sequence of widget entries. Note that this is useful if you want
	 *  to use references to common widgets
	 *
	 * @param file YAML file name
	 *
	 * @return Built Widget tree
	 *
	 * @throw exception when something went wrong
	 */
	Widget *build (const string& file);
}

}
