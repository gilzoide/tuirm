tuirm
=====
tuirm (Terminal UI Rocks, Modafaka) is a ncurses based toolkit for writting console applications using Lua

What does/will it do:
- abstract the application main loop
- have a nice set of highly customizable widgets
- abstract panels, with child widgets/panels, positioned relatively to it
- handle widget focus, with default keys for traversing them
- handle inputs nicely, with common callbacks like `widget.onClick` and `widget.onFocus` and stuff
- callbacks with Lua `functions` (which may be closures), which is really confy to program
- handle panels/widgets layout and terminal resizes


Dependencies
------------
For now, [lcurses](https://github.com/rrthomas/lcurses) and [argparse](https://github.com/mpeterv/argparse)
