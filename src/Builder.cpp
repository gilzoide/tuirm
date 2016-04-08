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

#include "Builder.hpp"
#include "debug.hpp"

#include <iostream>
#include <yaml-cpp/yaml.h>

namespace tuirm {

Widget *Builder::build (const string& file) {
	auto tree = YAML::LoadFile (file);

	// assert root key
	if (tree["root"]) {
		tree = tree["root"];
	}
	else {
		throw TUIRM_API_EXCEPTION ("Builder::build", "YAML file don't have a 'root' key");
	}

	for (auto node : tree) {
		cout << "- " << node << endl;
	}

	return new Widget;
}

}
