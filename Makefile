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
# LAST EDITED:	    09/02/2019
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

CXXFLAGS = -g -Wall -Wextra -O0 -I ./include --std=c++17
LDFLAGS  = -lc++ -lstdc++fs

include Dependencies.mk

Main-obj = source/main.o

# Force pipenv to put the package cache here
export PIPENV_CACHE_DIR=$(PWD)
# Force pipenv to put the venv in the project directory
export PIPENV_VENV_IN_PROJECT=1

.PHONY: pipenv

all: SortMedia test # TODO: Uncomment docs dependency

SortMedia: $(SortMedia-obj) $(Main-obj)
	$(CXX) $(CXXFLAGS) -o $@ $(Main-obj) $(SortMedia-obj) $(LDFLAGS)

$(Main-obj):
$(SortMedia-obj):

test: CXXFLAGS += -I ./googletest/googletest/include/
test: LDFLAGS += -L googletest/googlemock/gtest/ -lgtest_main -lgtest
test: UnitTests
UnitTests: $(SortMedia-obj) $(Test-objs)
	$(CXX) $(CXXFLAGS) -o $@ $(SortMedia-obj) $(Test-objs) $(LDFLAGS)

$(Test-objs):

docs:
	dot -T pdf -o architecture.pdf architecture.gv
	pipenv run pdflatex $(flags) $(TGT) $(dep)

pipenv:
	pipenv install

clean:
	rm -f `find . -name *.o`
	rm -f SortMedia
	rm -f UnitTests

##############################################################################
