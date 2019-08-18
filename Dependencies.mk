###############################################################################
# NAME:		    Dependencies.mk
#
# AUTHOR:	    Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:	    Make dependencies for the targets in the Makefile.
#
# CREATED:	    08/15/2019
#
# LAST EDITED:	    08/18/2019
###

SortMedia-obj += source/CrossCutting/Logging/LoggerConfiguration.o
SortMedia-obj += source/CrossCutting/Logging/LoggerFactory.o
SortMedia-obj += source/CrossCutting/Logging/NullLogger.o
SortMedia-obj += source/MediaSorter.o

Test-objs += test/TestMain.o
Test-objs += test/Logging/LogSystemTest.o

###############################################################################
