TIMIX_STRING_OBJS:= \
		memset.o				\
		strcat.o     		\
    strcmp.o     		\
    strcpy.o     		\
    strdup.o     		\
    strlen.o     		\
    strncmp.o    		\
    strncpy.o				\
		strtok.o				\
		strchr.o

TIMIX_STRING_OBJS:=$(TIMIX_STRING_OBJS:%=build/$(LIBDIR)/string/%)

ALL_KOBJS += $(TIMIX_STRING_OBJS)
KCLEANS += $(LIBDIR)/libstring.a

$(BUILDDIR)/libstring.a: $(TIMIX_STRING_OBJS)
