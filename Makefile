# project directories
INCDIRS		= include
SRCDIR 		= src
BUILDDIR	= build
TARGETS 	= runtime 

# compilation variables
CC			= gcc
DEPFLAGS	= -MP -MD
OPT			= -O2
CFLAGS		= -Wall $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)

# build variables
SOURCES     = $(shell find $(SRCDIR) -type f -name *.c)
OBJECTS     = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.c=.o))
DEPFILES	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.c=.d))

# recipies
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJECTS) $(DEPFILES)

$(BUILDDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all remake clean cleaner resources
