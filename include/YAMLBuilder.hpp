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

/** @file YAMLBuilder.hpp
 * Tuirm Widget Builder, from a YAML string or file
 */
#pragma once

#include "Builder.hpp"
#include "Widget.hpp"

#include <yaml-cpp/yaml.h>

using namespace std;

namespace tuirm {

/**
 * Widget Builder from a YAML string or file
 *
 * @note For YAML, there __must__ be a 'root' key, that holds a sequence of
 * widgets to be created.
 * 
 * @note Sub widgets (children) should be placed in a 'sub' key
 */
class YAMLBuilder : Builder {
public:
	/**
	 * Build a Widget tree from a YAML file
	 *
	 * @param file YAML file name
	 *
	 * @return Built Widget tree
	 *
	 * @throw tuirm::Exception if 'root' key wasn't found
	 */
	Widget *loadFile (const string& file) override;

	/**
	 * Build a Widget directly from a YAML string
	 *
	 * @param input Input string
	 *
	 * @return Built Widget tree
	 *
	 * @throw tuirm::Exception if 'root' key wasn't found
	 */
	Widget *loadString (const string& input) override;

private:
	/**
	 * The real build function, abstracting if file or string
	 *
	 * @param node A constructed YAMLNode
	 *
	 * @return Built Widget tree
	 *
	 * @throw tuirm::Exception if 'root' key wasn't found
	 */
	Widget *build (YAML::Node& tree);

	/**
	 * Recursive funtion that builds a Widget from a Node
	 *
	 * @param node A constructed YAMLNode
	 *
	 * @return Built Widget
	 *
	 * @throw tuirm::Exception if something went wrong
	 */
	Widget *buildNode (YAML::Node& node);
};

}
