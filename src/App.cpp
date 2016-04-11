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
#include "App.hpp"
#include "Input.hpp"
#include "Colors.hpp"
#include "debug.hpp"
#include "StdLogger.hpp"
#include "FileLogger.hpp"

using namespace std;

namespace tuirm {

App::App () {
	logger = new StdLogger ();
	initCurses ();
}


App::App (int& argc, char **& argv) throw (tuirm::Exception, lap::Exception) {
	int wantedVerbosity = 0;
	// reference to App::logger, for accesing in the lambdas
	auto & logger = this->logger;

	lap::ArgParser args;
	// possible tuirm's command line options
	args.registerOpt ("-help", "tuirm command line options help", [&args] {
				args.showHelp ("Tuirm", "bora lá, moçada!");
				exit (EXIT_SUCCESS);
				return false;
			});
	args.registerOpt ("-log", "redirect app logs to a file", 1, {"FILE"},
			[&logger] (lap::argVector v) {
				logger = new FileLogger (v[0]);
				return true;
			});
	// app logger verbosity
	args.registerOpt ("-verbosity", "set App Logger verbosity level", 1,
			{"VERBOSITY"}, [&wantedVerbosity] (lap::argVector v) {
				try {
					wantedVerbosity = stoi (v[0]);
				}
				catch (...) {
					throw Exception ("Verbosity level should be an integer!");
				}
				return true;
			});
	args.parseAndRemove (argc, argv);

	// user didn't choose logger type, so create a standard one
	if (!logger) {
		logger = new StdLogger ();
	}

	// set App Logger verbosity, after it's been decided
	logger->setVerbosity (wantedVerbosity);

	initCurses ();
}


App::~App () {
	delete logger;
	delete root;
}


void App::initCurses () {
	try {
		initscr ();
		keypad (stdscr, TRUE);
		cbreak ();
		noecho ();
		initCursesColors ();
	}
	catch (char const *err) {
		throw TUIRM_API_EXCEPTION ("App::initCurses", err);
	}
}


Logger *App::getLogger () {
	return logger;
}


Widget *App::setRoot (Widget *newRoot) {
	auto old = root;
	root = newRoot;
	return old;
}


void App::run () {
	// if there's no root, we can't run at all dude
	if (!root) {
		throw TUIRM_API_EXCEPTION ("App::run", "Can't run App without Widgets!");
	}
	mainLoop = true;

	int c = 0;
	while (mainLoop) {
		c = Input::getInput ();
		switch (c) {
			case 'q':
				close ();
				break;

			case 'p':
				pause ();
				puts ("digita um trem, rapá!");
				{
					string str;
					cin >> str;
					resume ();
					attrset (COLOR_PAIR (NN));
					addch ('"');
					addstr (str.c_str ());
				}
				addstr ("\"\n");
				break;

			default:
				attrset (COLOR_PAIR (BkBl));
				addstr ("Clicked something. 'p' to pause, 'q' to quit\n");
				break;
		}
	}
}


void App::pause () {
	endwin ();
}


void App::resume () {
	refresh ();
}


void App::close () {
	endwin ();
	mainLoop = false;
}

}
