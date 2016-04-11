#include <iostream>
#include "tuirm.hpp"

using namespace std;
using namespace tuirm;

int main (int argc, char **argv) {
	try {
		App app (argc, argv);
		{
			YAMLBuilder builder;
			app.setRoot (builder.loadFile ("concepts/simpleApp.yaml"));
		}
		app.run ();
		app.getLogger ()->log ("yo!");
		app.getLogger ()->log ("yo2");
		app.getLogger ()->log ("yo3");
	}
	catch (exception& ex) {
		endwin ();
		cerr << "Erro do teste: " << ex.what () << endl;
	}
	return 0;
}
