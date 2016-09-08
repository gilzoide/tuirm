----//    LDoc configuration file    //----

project = 'tuirm'
title = 'tuirm'
description = 'A ncurses based Terminal UI toolkit in Lua'
full_description = [[
tuirm (Terminal UI Rocks, Modafaka) is a ncurses based toolkit for writting console applications using Lua
]]

format = 'markdown'
not_luadoc = true
merge = true

file = { 'src' }
readme = 'README.md'

--//  add custom types for parameters  //--
-- builtin Lua types
tparam_alias ('string', 'string')
tparam_alias ('number', 'number')
tparam_alias ('int', 'int')
tparam_alias ('bool', 'bool')
tparam_alias ('table', 'table')
-- Tuirm types
tparam_alias ('App', 'App')
tparam_alias ('Widget', 'Widget')
