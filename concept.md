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
Tuirm classes (Widgets not listed, they will be severelly added/removed along
the way).

Class  | What for
------ | --------
App    | The application object. May or may not use multithreads
Panel  | The panels. Window abstractions, may have child Panels and Widgets. Maybe will be movable, and resize it's children automatically
Widget | You know that these are for. Various callbacks may be handled, C++11 function style
Input  | The input handler. Read more about it in the next chapter ;]

INPUT
=====
Input is handled by the class `Input`, our input handler.
Access is done by static methods.

There will be common (and maybe customizable) keybinds, like ^Q
for quitting, Shift-Tab for changing Widget focus, etc...

Input handler will know which Widget is in focus, change focus, and call the
Callbacks if there are any. Inputs may be ignored by some Widgets, and even
rethrown for parents to handle.

