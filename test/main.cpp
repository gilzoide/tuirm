#include <iostream>
#include "tuirm.hpp"

using namespace std;
using namespace tuirm;

int main (int argc, char **argv) {
	App app (argc, argv);
	app.run ();
	Logger::getAppLogger ()->log ("yo!");
	Logger::getAppLogger ()->log ("yo2");
	Logger::getAppLogger ()->log ("yo3");
	return 0;
}
