Hello there!
This is gilzoide, and I'm here to explain how tuirm was thought to be

WHY
===
I really love ncurses console applications. They're light and minimalist.
They run on the tty. Plus, asc art is awesome!

Thinking about that, I wanted the world to have a full open source toolkit for
making those apps, and making it easy for programmers (trust me, this is very
important) to use it any way needed, and abstracting many things a good toolkit
should, and also use the super cool stuff C++11 gives us.

USING
=====
1. Import it: `#include <tuirm.hpp>`
2. Create the App: `tuirm::App app;`
3. Insert your app's body/logic: `// hard to make an one-liner here`
4. Run it: `app.run ()`
5. End your `main` normally, letting the `tuirm::App`'s destructor do it's thing
(RAII, dude)

CLASSES
=======
Tuirm main classes (Widgets not listed, they will be severelly added/removed
along the way, nor are auxiliary classes).

Class  | What for
------ | --------
App    | The application object. May or may not use multithreads
Panel  | The panels. Window abstractions, may have child Panels and Widgets. Maybe will be movable, and resize it's children automatically
Widget | You know that these are for. Various callbacks may be handled, C++11 function style
Input  | The input handler. Read more about it in the next chapter ;]
Logger | A logger for debug/error info, sending it to a file, ignoring it, or even opening a new panel in app (polymorphism)

INPUT
=====
Input is handled by the class `Input`, our input handler.
Access is done by static methods.

There will be common (and maybe customizable) keybinds, like ^Q
for quitting, Shift-Tab for changing Widget focus, etc...

Input handler will know which Widget is in focus, change focus, and call the
Callbacks if there are any. Inputs may be ignored by some Widgets, and even
rethrown for parents to handle.

There will probably be an event queue, and a thread separated from main to
process it, so we don't lose responsivity.

COMMAND LINE ARGUMENTS
======================
Command line arguments are really useful for customization.
Tuirm will have some common command line arguments for apps, which may be used
when calling the `App` constructor with `argc` and `argv` as arguments.
Some options:
- Log output file, or in app alerts
- Setting app's maximum height and width (instead of initial `LINES` and `COLS`),
  useful for testing

CONFIGURATION
=============
App configuration (aside from tuirm's one) is really important, most of the
time. Maybe there'll be some integration with some data serialization file type
(probably YAML, or JSON).

APP CONSTRUCTION
================
Building an interface with panels, widgets and this stuff is somewhat
complicated and demand hard work.
Thinking on that, _tuirm_ gives us programmers an easier way: a DOM like
structure for building widget trees, and with a builder using external files
(or strings).
Widgets may have IDs, stored in a `std::map`, so that we can
query the app for a specific widget. Wigets without IDs won't be in the `map`,
but will still be tied up in the tree, so it all works fine.
