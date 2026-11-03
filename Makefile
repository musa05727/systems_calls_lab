CC=gcc
# Added -MMD to automatically generate correct .d files during compilation
CFLAGS=-c -Wall -MMD
SOURCES= info.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=info

all: $(SOURCES) $(EXECUTABLE)

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

# Simplified pattern rule (using standard % approach)
%.o: %.c
		$(CC) $(CFLAGS) $< -o $@

clean: 
		rm -rf $(OBJECTS) $(EXECUTABLE) *.d
