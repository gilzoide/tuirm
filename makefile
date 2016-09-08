## Tuirm Makefile ##

# Luarocks stuff, but hardcoded
CFLAGS = -Wall -O2 -fPIC
LIBFLAG = -shared
LUA_LIBDIR = /usr/lib
LUA_BINDIR = /usr/bin
LUA_INCDIR = /usr/include
LUA = lua
#
PREFIX = /usr
BINDIR = $(PREFIX)/bin
LIBDIR = $(PREFIX)/lib/lua/5.3
LUADIR = $(PREFIX)/share/lua/5.3
CONFDIR = $(PREFIX)/etc

# source files
src = $(wildcard src/*.lua)
c_src = src/ncursesextras.c
c_out = ncursesextras.so
# build path
BUILD = build/tuirm


all : builddir lua c_extra

lua :
	cp -r $(src) $(BUILD)

c_extra : $(c_src)
	$(CC) $< $(CFLAGS) -I$(LUA_INCDIR) $(LIBFLAG) -o $(BUILD)/$(c_out)

install :
	install -d $(LUADIR)/tuirm $(LIBDIR)/tuirm
	install -m 644 -t $(LUADIR)/tuirm $(BUILD)/*.lua
	install -m 644 -t $(LIBDIR)/tuirm $(BUILD)/*.so

# assert build path
builddir :
	@mkdir -p $(BUILD)

.PHONY : test
test :
	@cd build; lua ../test/first.lua
