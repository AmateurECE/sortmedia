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
# LAST EDITED:	    08/08/2019
###

flags=-shell-escape
dep=
TGT=designdoc.tex

# Force pipenv to put the package cache here
export PIPENV_CACHE_DIR=$(PWD)
# Force pipenv to put the venv in the project directory
export PIPENV_VENV_IN_PROJECT=1

.PHONY: pipenv

build:
	dot -T pdf -o architecture.pdf architecture.gv
	pipenv run pdflatex $(flags) $(TGT) $(dep)

pipenv:
	pipenv install

##############################################################################
