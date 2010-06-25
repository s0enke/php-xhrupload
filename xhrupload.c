/* __header_here__ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_xhrupload.h"
#include "rfc1867.h" 
#include <syslog.h>

/* If you declare any globals in php_xhrupload.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(xhrupload)
*/

/* True global resources - no need for thread safety here */
static int le_xhrupload;

/* {{{ xhrupload_functions[]
 *
 * Every user visible function must have an entry in xhrupload_functions[].
 */
zend_function_entry xhrupload_functions[] = {
	PHP_FE(confirm_xhrupload_compiled,	NULL)		/* For testing, remove later. */
	/* __function_entries_here__ */
	{NULL, NULL, NULL}	/* Must be the last line in xhrupload_functions[] */
};
/* }}} */

/* {{{ xhrupload_module_entry
 */
zend_module_entry xhrupload_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"xhrupload",
	xhrupload_functions,
    PHP_MINIT(xhrupload),
    PHP_MSHUTDOWN(xhrupload),
    PHP_RINIT(xhrupload),     /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(xhrupload), /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(xhrupload),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_XHRUPLOAD_EXTVER, /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_XHRUPLOAD
ZEND_GET_MODULE(xhrupload)
#endif

PHPAPI extern int (*php_rfc1867_callback)(unsigned int , void *, void ** TSRMLS_DC); 

static int php_xhrupload_rfc1867_callback(unsigned int event, void *event_data, void **data TSRMLS_DC) 
{
    char* filename;

    //filename = (char *) SG(request_info).query_string;
    //filename = SG(request_info).post_entry->content_type;
    filename = sapi_module.name;

    if (filename != NULL) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "%s", filename);
    } else {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "BERND1");
    }


   switch (event) {

        case MULTIPART_EVENT_START :
            php_error_docref(NULL TSRMLS_CC, E_WARNING, "JIPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPIE");
            break;
    }

    return SUCCESS;
}


/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("xhrupload.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_xhrupload_globals, xhrupload_globals)
    STD_PHP_INI_ENTRY("xhrupload.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_xhrupload_globals, xhrupload_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_xhrupload_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_xhrupload_init_globals(zend_xhrupload_globals *xhrupload_globals)
{
	xhrupload_globals->global_value = 0;
	xhrupload_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(xhrupload)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
    php_rfc1867_callback = php_xhrupload_rfc1867_callback;
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(xhrupload)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
    php_rfc1867_callback = NULL;
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(xhrupload)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(xhrupload)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(xhrupload)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "xhrupload support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_xhrupload_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_xhrupload_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

    fprintf(stderr, "BERND IS BACK\n");
	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "xhrupload", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* __function_stubs_here__ */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
