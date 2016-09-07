package = 'tuirm'
version = 'scm-1'
source = {
	url = 'git://github.com/gilzoide/tuirm'
}
description = {
	summary = 'A ncurses based Terminal UI toolkit in Lua',
	detailed = [[
		tuirm (Terminal UI Rocks, Modafaka) is a ncurses based toolkit for writting console applications using Lua
	]],
	license = 'GPLv3',
	maintainer = 'gilzoide <gilzoide@gmail.com>',
}

dependencies = {
	'lua >= 5.2',
	'lcurses',
	'argparse',
}

build = {
	type = 'make',
	build_variables = {
		CFLAGS = "$(CFLAGS)",
		LIBFLAG = "$(LIBFLAG)",
		LUA_LIBDIR = "$(LUA_LIBDIR)",
		LUA_BINDIR = "$(LUA_BINDIR)",
		LUA_INCDIR = "$(LUA_INCDIR)",
		LUA = "$(LUA)",
	},
	install_variables = {
		PREFIX = "$(PREFIX)",
		BINDIR = "$(BINDIR)",
		LIBDIR = "$(LIBDIR)",
		LUADIR = "$(LUADIR)",
		CONFDIR = "$(CONFDIR)",
	},
}
