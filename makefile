
CFLAGS = -O2 -g -Wall -Wextra
#CPPFLAGS
#LDLIBS

SRCDIR = src
OBJDIR = obj

OBJS = $(OBJDIR)/main.o $(OBJDIR)/input.o $(OBJDIR)/abstract_stratagy.o $(OBJDIR)/strat_fac.o $(OBJDIR)/fifo.o $(OBJDIR)/LRU.o $(OBJDIR)/optimal.o

build: $(OBJDIR) $(OBJS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o program $(LDLIBS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONEY: clean

clean:
	-rm -r $(OBJDIR)
	-rm program
