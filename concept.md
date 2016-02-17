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
1. Import it: `#include <tuirm.hh>`
2. Create the App: `tuirm::App app;`
3. Insert your app's body/logic: `// hard to make an one-liner here`
4. Run it: `app.run ()`
5. End your `main` normally, letting the `tuirm::App`'s destructor to it's thing
(RAII)

