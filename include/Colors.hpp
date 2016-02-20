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

/** @file Color.hpp
 * The Color definitions, and curses colors initialization
 */
#pragma once

namespace tuirm {

/**
 * Color definitions
 * 
 * The colors used in tuirm (and in terminals, in overall), defined
 * in an enum. These are already the COLOR_PAIRs at curses.
 * 
 * @note Colors are defined in the format: _foreground-background_
 * @note They're agrouped by foreground color.
 */
enum Colors : unsigned char {
	NN = 0,	///< Terminal's default colors
// Normal
	NBk,	///< Normal-Black
	NR,		///< Normal-Red
	NG,		///< Normal-Green
	NY,		///< Normal-Yellow
	NBl,	///< Normal-Blue
	NM,		///< Normal-Magenta
	NC,		///< Normal-Cyan
	NW,		///< Normal-White
// black
	BkN,	///< Black-Normal
	BkBk, 	///< Black-Black
	BkR, 	///< Black-Red
	BkG, 	///< Black-Green
	BkY, 	///< Black-Yellow
	BkBl, 	///< Black-Blue
	BkM, 	///< Black-Magenta
	BkC, 	///< Black-Cyan
	BkW, 	///< Black-White
// red
	RN,		///< Red-Normal
	RBk, 	///< Red-Black
	RR, 	///< Red-Red
	RG, 	///< Red-Green
	RY, 	///< Red-Yellow
	RBl, 	///< Red-Blue
	RM, 	///< Red-Magenta
	RC, 	///< Red-Cyan
	RW, 	///< Red-White
// green
	GN,		///< Green-Normal
	GBk, 	///< Green-Black
	GR, 	///< Green-Red
	GG, 	///< Green-Green
	GY, 	///< Green-Yellow
	GBl, 	///< Green-Blue
	GM, 	///< Green-Magenta
	GC, 	///< Green-Cyan
	GW, 	///< Green-White
// yellow
	YN,		///< Yellow-Normal
	YBk, 	///< Yellow-Black
	YR, 	///< Yellow-Red
	YG, 	///< Yellow-Green
	YY, 	///< Yellow-Yellow
	YBl, 	///< Yellow-Blue
	YM, 	///< Yellow-Magenta
	YC, 	///< Yellow-Cyan
	YW, 	///< Yellow-White
// blue
	BlN,	///< Blue-Normal
	BlBk, 	///< Blue-Black
	BlR, 	///< Blue-Red
	BlG, 	///< Blue-Green
	BlY, 	///< Blue-Yellow
	BlBl, 	///< Blue-Blue
	BlM, 	///< Blue-Magenta
	BlC, 	///< Blue-Cyan
	BlW, 	///< Blue-White
// magenta
	MN,		///< Magenta-Normal
	MBk,	///< Magenta-Black
	MR, 	///< Magenta-Red
	MG,  	///< Magenta-Green
	MY,  	///< Magenta-Yellow
	MBl,	///< Magenta-Blue
	MM, 	///< Magenta-Magenta
	MC, 	///< Magenta-Cyan
	MW, 	///< Magenta-White
// cyan
	CN,		///< Cyan-Normal
	CBk, 	///< Cyan-Black
	CR, 	///< Cyan-Red
	CG, 	///< Cyan-Green
	CY, 	///< Cyan-Yellow
	CBl, 	///< Cyan-Blue
	CM, 	///< Cyan-Magenta
	CC, 	///< Cyan-Cyan
	CW, 	///< Cyan-White
// white
	WN,		///< White-Normal
	WBk, 	///< White-Black
	WR, 	///< White-Red
	WG, 	///< White-Green
	WY, 	///< White-Yellow
	WBl, 	///< White-Blue
	WM,		///< White-Magenta
	WC, 	///< White-Cyan
	WW 		///< White-White
};

/// Number of colors
#define MAX_COLORS (WW + 1)
/// The step of the colors' agrouping. Color + COLORS_STEP gets
/// a color with the the same background, but the next foreground
#define COLORS_STEP (BkN)

/// Get the color's foreground
#define GetFore(color) ((color) / COLORS_STEP)
/// Get the color's background
#define GetBack(color) ((color) % COLORS_STEP)

/**
 * Initialize ncurses colors
 */
void initCursesColors ();

}
