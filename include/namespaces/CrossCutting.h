///////////////////////////////////////////////////////////////////////////////
// NAME:            CrossCutting.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This namespace encapsulates the major cross-cutting
//                  concerns of the application. It should be understood by
//                  developers that they could potentially be used in any given
//                  class. Modifying the interfaces contained herein is VERY
//                  DANGEROUS AND SHOULD BE DONE UNDER NO CIRCUMSTANCES, as it
//                  will likely result in breaking half of the classes in the
//                  ecosystem. Due to the nature of these concerns, they have
//                  been implemented in a more imperative (C-style) way. This
//                  is to avoid poisoning the design with potentially
//                  complicated idioms.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/18/2019
////

namespace CrossCutting
{
  namespace Logging
  {
    class NullLogger;
    class Logger;
    class LoggerConfiguration;
    class LoggerFactory;
  }
}

///////////////////////////////////////////////////////////////////////////////
