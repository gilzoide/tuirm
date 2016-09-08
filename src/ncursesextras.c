/*
 * Copyright (C) 2016 Gil Barbosa Reis
 * This file is part of Tuirm.
 *
 * Tuirm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tuirm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tuirm.  If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ncursesextras.c
 * Extras from ncurses not found in lcurses
 */

#include <ncurses.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

/// Assume default colors
int assumeDefaultColors (lua_State *L) {
	int fg = luaL_optinteger (L, 1, -1);
	int bg = luaL_optinteger (L, 2, -1);

	int ret = assume_default_colors (fg, bg);
	// success
	if (ret) {
		lua_pushboolean (L, 1);
		return 1;
	}
	else {
		lua_pushnil (L);
		lua_pushliteral (L, "Terminal can't bind default colors, do you have ncurses?");
		return 2;
	}
}

const struct luaL_Reg lib[] = {
	{ "assume_default_colors", assumeDefaultColors },
	{ NULL, NULL }
};
int luaopen_tuirm_ncursesextras (lua_State *L) {
	luaL_newlib (L, lib);
	return 1;
}
