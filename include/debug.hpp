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

/** @file debug.hpp
 * Useful debug/error functions/macros
 */
#pragma once

#include <cstdio>

/// Some error in function 'funcName'
#define ERROR(funcName, fmt, ...) \
	fprintf (stderr, "[tuirm::" funcName " @ " __FILE__ ":%d] Error: " \
			fmt "\n", __LINE__, ##__VA_ARGS__)

#define FATAL(funcName, fmt, ...) \
	fprintf (stderr, "[tuirm::" funcName " @ " __FILE__ ":%d] Error: " \
			fmt "\n", __LINE__, ##__VA_ARGS__); \
	exit (-1)