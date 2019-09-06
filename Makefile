###############################################################################
# NAME:		    Makefile
#
# AUTHOR:	    Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:	    Makefile for homework in this directory. This is just a
#		    convenience wrapper for a slightly unpleasant latex call.
#
# CREATED:	    02/03/2019
#
# LAST EDITED:	    09/05/2019
###

flags=-shell-escape
dep=
TGT=designdoc.tex

ifneq ($(shell uname),Darwin)
    $(info This is not a Darwin environment, so I am depending on the \
	environment to know where its own compiler is...)
else
    CXX=$(shell xcode-select -p)/usr/bin/gcc
endif

FSAdaptor-dir=FSAdaptor
FSAdaptor-CXXFLAGS = -I $(FSAdaptor-dir)/include
FSAdaptor-LDFLAGS = -L $(FSAdaptor-dir)/build -lfsadaptor

TagLib-dir=dependencies/taglib-1.11.1/
TagLib-CXXFLAGS = -I $(TagLib-dir)/include
TagLib-LDFLAGS = -L $(TagLib-dir) -ltag `pkg-config --libs zlib`

CXXFLAGS = -g -Wall -Wextra -O0 -I ./include --std=c++17 \
	$(FSAdaptor-CXXFLAGS) $(TagLib-CXXFLAGS)
LDFLAGS  = -lc++ $(FSAdaptor-LDFLAGS) $(TagLib-LDFLAGS)

include Dependencies.mk

Main-obj = source/main.o

# Force pipenv to put the package cache here
export PIPENV_CACHE_DIR=$(PWD)
# Force pipenv to put the venv in the project directory
export PIPENV_VENV_IN_PROJECT=1

.PHONY: pipenv

all: SortMedia test # TODO: Uncomment docs dependency

libFSAdaptor: $(FSAdaptor-dir)/build/libfsadaptor.a

$(FSAdaptor-dir)/build/libfsadaptor.a:
	mkdir $(FSAdaptor-dir)/build && cd $(FSAdaptor-dir)/build \
		&& cmake .. && make fsadaptor

SortMedia: libFSAdaptor $(SortMedia-obj) $(Main-obj)
	$(CXX) $(CXXFLAGS) -o $@ $(Main-obj) $(SortMedia-obj) $(LDFLAGS)

$(Main-obj):
$(SortMedia-obj):

test: CXXFLAGS += `pkg-config --cflags gtest_main`
test: LDFLAGS += `pkg-config --libs gtest_main`
test: UnitTests
UnitTests: libFSAdaptor $(SortMedia-obj) $(Test-objs)
	$(CXX) $(CXXFLAGS) -o $@ $(SortMedia-obj) $(Test-objs) $(LDFLAGS)

$(Test-objs): CXXFLAGS += -Wno-unused-parameter
$(Test-objs):

docs:
	dot -T pdf -o architecture.pdf architecture.gv
	dot -T pdf -o InterfaceLayer.pdf InterfaceLayer.gv
	pipenv run pdflatex $(flags) $(TGT) $(dep)

pipenv:
	pipenv install

clean:
	rm -f `find . -name *.o`
	rm -rf $(FSAdaptor-dir)/build
	rm -f SortMedia
	rm -f UnitTests

##############################################################################
