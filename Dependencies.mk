###############################################################################
# NAME:		    Dependencies.mk
#
# AUTHOR:	    Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:	    Make dependencies for the targets in the Makefile.
#
# CREATED:	    08/15/2019
#
# LAST EDITED:	    09/01/2019
###

SortMedia-obj += source/SortMedia/Adaptors/StandardFilesystemAdaptor.o
SortMedia-obj += source/SortMedia/Factories/OrganizationalSchemaFactory.o
SortMedia-obj += source/SortMedia/Factories/FileLocatorFactory.o
SortMedia-obj += source/SortMedia/Logging/StreamLogger.o
SortMedia-obj += source/SortMedia/Logging/NullLogger.o
SortMedia-obj += source/SortMedia/MediaSorter.o
SortMedia-obj += source/SortMedia/Path.o

Test-objs += test/TestMain.o
Test-objs += test/Logging/LogSystemTest.o
Test-objs += test/FileLocator/AnyFileLocatorTest.o
Test-objs += test/Path/UnixAbsolutePathTest.o
Test-objs += test/Path/UnixHiddenFilePathTest.o
Test-objs += test/Path/UnixNoExtensionPathTest.o
Test-objs += test/Path/UnixRelativeCurrentPathTest.o
Test-objs += test/Path/UnixRelativeParentPathTest.o

###############################################################################
