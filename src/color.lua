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

--- @module tuirm.color
-- Colors and attributes =]
local M = {}

local curses = require 'curses'
local ncurses_extras = require 'tuirm.ncursesextras'

--- Initialize curses colors, to be called on App's construction
function M.initColors ()
	-- colors!
	curses.start_color ()
	ncurses_extras.assume_default_colors (-1, -1)

	local cursColors = {
		-1,
		curses.COLOR_BLACK,
		curses.COLOR_RED,
		curses.COLOR_GREEN,
		curses.COLOR_YELLOW,
		curses.COLOR_BLUE,
		curses.COLOR_MAGENTA,
		curses.COLOR_CYAN,
		curses.COLOR_WHITE,
	}
	local colorInitials = {
		'N',
		'Bk',
		'R',
		'G',
		'Y',
		'Bl',
		'M',
		'C',
		'W',
	}
	local colorStep = #cursColors
	for i, fg in ipairs (cursColors) do
		for j, bg in ipairs (cursColors) do
			local idx = (i - 1) * colorStep + j
			-- initialize curses color
			curses.init_pair (idx, fg, bg)
			-- and insert it (color directly, no need for `curses.color_pair`)
			-- in tuirm.color
			M[colorInitials[i] .. colorInitials[j]] = curses.color_pair (idx)
		end
	end
end

return M
