###############################################################################
# NAME:		    Dependencies.mk
#
# AUTHOR:	    Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:	    Make dependencies for the targets in the Makefile.
#
# CREATED:	    08/15/2019
#
# LAST EDITED:	    09/10/2019
###

SortMedia-obj += source/SortMedia/Schemas/BasicMusicOrganizationalSchema.o
SortMedia-obj += source/SortMedia/Schemas/OrganizationalSchema.o

SortMedia-obj += source/SortMedia/Policies/DeleteFile.o
SortMedia-obj += source/SortMedia/Policies/DeleteDirectoryIfEmpty.o
SortMedia-obj += source/SortMedia/Policies/BasicMusicFileNaming.o
SortMedia-obj += source/SortMedia/Policies/UnknownFileType.o
SortMedia-obj += source/SortMedia/Policies/OrganizationalBase.o

SortMedia-obj += source/SortMedia/Operations/DeleteFile.o
SortMedia-obj += source/SortMedia/Operations/DeleteDirectoryIfEmpty.o
SortMedia-obj += source/SortMedia/Operations/Warn.o

SortMedia-obj += source/SortMedia/FileTypes/MusicFile.o
SortMedia-obj += source/SortMedia/FileTypes/LibraryFile.o

SortMedia-obj += source/SortMedia/Exceptions/PolicyVerificationError.o
SortMedia-obj += source/SortMedia/Adaptors/TagLibAdaptor.o
SortMedia-obj += source/SortMedia/FileLocators/AnyFileLocator.o

SortMedia-obj += source/SortMedia/Factories/OrganizationalSchemaFactory.o
SortMedia-obj += source/SortMedia/Factories/FileLocatorFactory.o

SortMedia-obj += source/SortMedia/Logging/StreamLogger.o
SortMedia-obj += source/SortMedia/Logging/NullLogger.o

SortMedia-obj += source/SortMedia/MediaSorter.o

Test-objs += test/TestMain.o
Test-objs += test/Logging/LogSystemTest.o
Test-objs += test/FileLocator/AnyFileLocatorTest.o

###############################################################################
