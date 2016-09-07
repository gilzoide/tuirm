## Tuirm Makefile ##

# Luarocks stuff, but hardcoded
PREFIX = /usr
BINDIR = $(PREFIX)/bin
LIBDIR = $(PREFIX)/lib/lua/5.3
LUADIR = $(PREFIX)/share/lua/5.3
CONFDIR = $(PREFIX)/etc

# source files
src = $(wildcard src/*.lua)
# build path
BUILD = build/tuirm


all : build
	cp -r $(src) $(BUILD)

install :
	install -d $(LUADIR)/tuirm
	install -m 644 -t $(LUADIR)/tuirm $(BUILD)/*

# assert build path
build :
	@mkdir -p $(BUILD)

