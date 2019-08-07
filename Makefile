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
# LAST EDITED:	    08/07/2019
###

flags=-shell-escape
dep=minted/source/minted.sty

build:
	dot -T png -o architecture.png architecture.gv
	pipenv run pdflatex $(flags) $(TGT) $(dep)

##############################################################################
