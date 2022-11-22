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
	$(CC) $(PREFIX)baseline.c $(CFLAGS) -o $(OBJDIR)vd.elf ; $(OBJDIR)vd.elf

v0: $(PREFIX)v0.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@.elf ; $(OBJDIR)$@.elf

v0c: $(PREFIX)v0c.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@.elf ; $(OBJDIR)$@.elf

v1: $(PREFIX)v1.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@.elf ; $(OBJDIR)$@.elf

v1c: $(PREFIX)v1c.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@.elf ; $(OBJDIR)$@.elf

v2: $(PREFIX)v2.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c c$(SRCDIR)ommon.c $(CFLAGS) -o $(OBJDIR)$@.elf ; $(OBJDIR)$@.elf

v2c: $(PREFIX)v2c.c $(SRCDIR)common.c
	$(CC) $(PREFIX)$@.c $(SRCDIR)common.c $(CFLAGS) -o $(OBJDIR)$@.elf ; $(OBJDIR)$@.elf