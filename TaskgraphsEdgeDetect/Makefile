CC=gcc
CFLAGS=-lm
SRCDIR = ./src/
OBJDIR = ./bin/
PREFIX = $(SRCDIR)edge_detect_tasks_
EXT = .elf
SEP = ;

ifeq ($(OS),Windows_NT)
EXT = .exe
SEP = &
endif

vd: $(PREFIX)baseline.c
	$(CC) $(PREFIX)baseline.c $(CFLAGS) -o $(OBJDIR)vd$(EXT) $(SEP) $(OBJDIR)vd$(EXT)

v0: $(PREFIX)v0.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v0c: $(PREFIX)v0c.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v1: $(PREFIX)v1.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v1c: $(PREFIX)v1c.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v2: $(PREFIX)v2.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v2c: $(PREFIX)v2c.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v0e: $(PREFIX)v0e.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v0ce: $(PREFIX)v0ce.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v1e: $(PREFIX)v1e.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v1ce: $(PREFIX)v1ce.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v2e: $(PREFIX)v2e.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

v2ce: $(PREFIX)v2ce.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@$(EXT) $(SEP) $(OBJDIR)$@$(EXT)

