#include <iostream>
#include "tuirm.hpp"

using namespace std;
using namespace tuirm;

int main (int argc, char **argv) {
	App app (argc, argv);
	app.run ();
	Logger::getAppLogger ()->log ("yo!");
	return 0;
}
