--[[
-- Copyright (C) 2016 Gil Barbosa Reis
-- This file is part of Tuirm.
--
-- Tuirm is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
--
-- Tuirm is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with Tuirm.  If not, see <http://www.gnu.org/licenses/>.
--]]

--- @module tuirm.app
-- App stuff
local M = {}

local curses = require 'curses'
local input = require 'tuirm.input'
local color = require 'tuirm.color'

--- Let new module index it's methods
--
-- @local
M.__index = M

--- App metatable!
--
-- @local
M.__metatable = 'TuirmApp'

--- Return string representation of App
--
-- @App app App
--
-- @treturn string "`TuirmApp <app.name>`"
function M.__tostring (app)
	return 'TuirmApp "' .. app.name .. '"'
end

--- Create a new App
--
-- @string[opt='TuirmApp'] name App name
--
-- @treturn App New App
function M.new (name)
	local win = curses.initscr ()
	win:keypad (true)
	curses.cbreak (true)
	curses.echo (false)
	curses.endwin ()
	color.initColors ()
	return setmetatable ({ name = name or 'TuirmApp', win = win }, M)
end

--- Close the App, finishing curses
--
-- @App app App
function M.close (app)
	curses.endwin ()
	app.mainLoop = nil
end

--- Pause App for a while, so one can write to stdout, or whatever
--
-- @App app App
function M.pause (app)
	curses.endwin ()
end

--- Resume a paused App
--
-- @App app App
function M.resume (app)
	curses.refresh ()
end

--- Enter App main loop, quitting on 'q' (for now)
--
-- @App app App
function M.run (app)
	-- assert (app.root, 'App:run', "Can't run App without Widgets!")

	app.mainLoop = true
	curses.attrset (color.WBl)
	while (app.mainLoop) do
		local c = input.getInput ()
		if c == 'q' then
			app:close ()
		else
			app.win:addstr ('oie\n')
			curses.refresh ()
		end
	end
end

return M
