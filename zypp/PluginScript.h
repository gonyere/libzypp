/*---------------------------------------------------------------------\
|                          ____ _   __ __ ___                          |
|                         |__  / \ / / . \ . \                         |
|                           / / \ V /|  _/  _/                         |
|                          / /__ | | | | | |                           |
|                         /_____||_| |_| |_|                           |
|                                                                      |
\---------------------------------------------------------------------*/
/** \file	zypp/PluginScript.h
 *
*/
#ifndef ZYPP_PLUGINSCRIPT_H
#define ZYPP_PLUGINSCRIPT_H

#include <iosfwd>
#include <string>
#include <vector>

#include "zypp/base/PtrTypes.h"
#include "zypp/Pathname.h"

#include "zypp/PluginFrame.h"
#include "zypp/PluginScriptException.h"

///////////////////////////////////////////////////////////////////
namespace zypp
{ /////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////
  //
  //	CLASS NAME : PluginScript
  //
  /**
   * \brief Interface to pluigin scripts using a \c Stomp inspired communication protocol
   *
   * \note \ref PluginScript is copyable and assignable, but the connection is shared
   * among multiple copies. It gets automatically closed if the last copy goes out of
   * scope.
   *
   * \code
   *  // Setup comnnection to plugin script
   *  PluginScript scr;
   *  PluginScript::Arguments args;
   *  args.push_back( "-v" );
   *  scr.open( "/soem/testplugin", args );
   *
   *  // send frame to plugin
   *  PluginFrame f( "COMMAND" );
   *  f.setHeader( "key", "value" );
   *  f.setBody( "some\ndata" );
   *  scr.send( f );
   *
   *  // receive frame from plugin
   *  PluginFrame r( scr.receive() );
   *
   *  // explicitly close or let PluginScript go out of scope
   *  scr.close();
   * \endcode
   *
   * \see http://stomp.codehaus.org/
   */
  class PluginScript
  {
    friend std::ostream & operator<<( std::ostream & str, const PluginScript & obj );

    public:
      /** Commandline arguments passed to a script on \ref open */
      typedef std::vector<std::string> Arguments;

      /** \c pid_t(-1) constant indicating no connection */
      static const pid_t NotConnected = -1;

    public:
      /** Default ctor */
      PluginScript();

      /** Ctor taking script path and no arguments */
      PluginScript( const Pathname & script_r );

      /** Ctor taking script path and script arguments */
      PluginScript( const Pathname & script_r, const Arguments & args_r );

    public:
      /** Return the script path if set */
      const Pathname & script() const;

      /** Return the script arguments if set */
      const Arguments & args() const;

      /** Whether we are connected to a script */
      bool isOpen() const;

      /** Return a connected scripts pid or \ref NotConnected */
      pid_t getPid() const;

    public:
      /** Setup connection and execute script
       * \throw PluginScriptException if already connected to a script
       * \throw PluginScriptException if script does not exist or is not executable
       * \throw PluginScriptException on error
       */
      void open();

      /** \overload taking script path and no arguments */
      void open( const Pathname & script_r );

      /** \overload taking script path and script arguments */
      void open( const Pathname & script_r, const Arguments & args_r );

      /** Close any open connection. */
      void close();

    public:
      /** Send a \ref PluginFrame
       * \throw PluginScriptException on error
       */
      void send( const PluginFrame & frame_r ) const;

      /** Receive a \ref PluginFrame
       * \throw PluginScriptException on error
       */
      PluginFrame receive() const;

    public:
      /** Implementation  */
      class Impl;
    private:
      /** Pointer to implementation */
      RW_pointer<Impl> _pimpl;
  };
  ///////////////////////////////////////////////////////////////////

  /** \relates PluginScript Stream output */
  std::ostream & operator<<( std::ostream & str, const PluginScript & obj );

  /////////////////////////////////////////////////////////////////
} // namespace zypp
///////////////////////////////////////////////////////////////////
#endif // ZYPP_PLUGINSCRIPT_H
