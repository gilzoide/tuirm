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

#include "YAMLBuilder.hpp"
#include "debug.hpp"

namespace tuirm {


Widget *YAMLBuilder::loadString (const string& input) {
	auto node = YAML::Load (input);
	return build (node);
}


Widget *YAMLBuilder::loadFile (const string& file) {
	auto node = YAML::LoadFile (file);
	return build (node);
}


Widget *YAMLBuilder::build (YAML::Node& tree) {
	// assert root key
	auto root = tree["root"];
	if (root) {
		//auto root = tree["root"];

		// start building the tree, recursively
		return buildNode (root);
	}
	else {
		throw TUIRM_API_EXCEPTION ("YAMLBuilder::build",
				"YAML file doesn't have a 'root' key");
	}
}


Widget *YAMLBuilder::buildNode (YAML::Node& node) {
	return new Widget;
}

}
