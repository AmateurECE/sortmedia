///////////////////////////////////////////////////////////////////////////////
// NAME:            FileLocatorFactory.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Member functions for the FileLocatorFactory class.
//
// CREATED:         08/27/2019
////

#include <libsortmedia/Factories/FileLocatorFactory.h>

#include <libsortmedia/FileLocators/AnyFileLocator.h>

SortMedia::Factories::FileLocatorFactory
::FileLocatorFactory()
{}

std::unique_ptr<SortMedia::Interfaces::IFileLocator>
SortMedia::Factories::FileLocatorFactory
::makeFileLocator() const
{
  return std::make_unique<FileLocators::AnyFileLocator>();
}

///////////////////////////////////////////////////////////////////////////////
