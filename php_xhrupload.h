/* __header_here__ */

#ifndef PHP_XHRUPLOAD_H
#define PHP_XHRUPLOAD_H

extern zend_module_entry xhrupload_module_entry;
//#define phpext_xhrupload_ptr &xhrupload_module_entry

#define PHP_XHRUPLOAD_EXTNAME "xhrupload"
#define PHP_XHRUPLOAD_EXTVER  "0.0"

#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#include "config.h"

PHP_MINIT_FUNCTION(xhrupload);
PHP_MSHUTDOWN_FUNCTION(xhrupload);
PHP_RINIT_FUNCTION(xhrupload);
PHP_RSHUTDOWN_FUNCTION(xhrupload);
PHP_MINFO_FUNCTION(xhrupload);

extern zend_module_entry xhrupload_module_entry;
#define phpext_xhrupload_ptr &xhrupload_module_entry

PHP_FUNCTION(confirm_xhrupload_compiled);	/* For testing, remove later. */
/* __function_declarations_here__ */

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(xhrupload)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(xhrupload)
*/

/* In every utility function you add that needs to use variables 
   in php_xhrupload_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as XHRUPLOAD_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#endif	/* PHP_XHRUPLOAD_H */

/* __footer_here__ */
