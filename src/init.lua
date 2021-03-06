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

--- @module tuirm
-- Base module

local M = {}

--- App constructor (`tuirm.app.new`)
--
-- @see tuirm.app.new
M.App = require 'tuirm.app'.new

return M
