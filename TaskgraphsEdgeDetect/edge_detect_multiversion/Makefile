CC=gcc
CFLAGS=-lm
OBJDIR = ./bin
PREFIX = edge_detect_tasks_

vd: $(PREFIX)baseline.c
	$(CC) $(PREFIX)baseline.c $(CFLAGS) -o $(OBJDIR)/vd.elf ; $(OBJDIR)/vd.elf

v0: $(PREFIX)v0.c common.c
	$(CC) $(PREFIX)$@.c common.c $(CFLAGS) -o $(OBJDIR)/$@.elf ; $(OBJDIR)/$@.elf

v0c: $(PREFIX)v0c.c common.c
	$(CC) $(PREFIX)$@.c common.c $(CFLAGS) -o $(OBJDIR)/$@.elf ; $(OBJDIR)/$@.elf

v1: $(PREFIX)v1.c common.c
	$(CC) $(PREFIX)$@.c common.c $(CFLAGS) -o $(OBJDIR)/$@.elf ; $(OBJDIR)/$@.elf

v1c: $(PREFIX)v1c.c common.c
	$(CC) $(PREFIX)$@.c common.c $(CFLAGS) -o $(OBJDIR)/$@.elf ; $(OBJDIR)/$@.elf

v2: $(PREFIX)v2.c common.c
	$(CC) $(PREFIX)$@.c common.c $(CFLAGS) -o $(OBJDIR)/$@.elf ; $(OBJDIR)/$@.elf

v2c: $(PREFIX)v2c.c common.c
	$(CC) $(PREFIX)$@.c common.c $(CFLAGS) -o $(OBJDIR)/$@.elf ; $(OBJDIR)/$@.elf