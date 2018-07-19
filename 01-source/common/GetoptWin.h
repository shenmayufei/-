#ifndef __GETOPT_H__

#define __GETOPT_H__

/* All the headers include this file. */
#ifdef _MSC_VER
#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

	extern int optind;		/* index of first non-option in argv      */
	extern int optopt;		/* single option character, as parsed     */
	extern int opterr;		/* flag to enable built-in diagnostics... */
	/* (user may set to zero, to suppress)    */

	extern char *optarg;		/* pointer to argument of current option  */

	extern int getopt(int nargc, char * const *nargv, const char *options);

#ifdef _BSD_SOURCE
# define optreset  __mingw_optreset
	extern int optreset;
#endif
#ifdef __cplusplus
}
#endif


#if !defined(__UNISTD_H_SOURCED__) && !defined(__GETOPT_LONG_H__)
#define __GETOPT_LONG_H__

#ifdef __cplusplus
extern "C" {
#endif

	struct option		/* specification for a long form option...	*/
	{
		const char *name;		/* option name, without leading hyphens */
		int         has_arg;		/* does it take an argument?		*/
		int        *flag;		/* where to save its status, or NULL	*/
		int         val;		/* its associated status value		*/
	};

	enum    		/* permitted values for its `has_arg' field...	*/
	{
		no_argument = 0,      	/* option never takes an argument	*/
		required_argument,		/* option always requires an argument	*/
		optional_argument		/* option may take an argument		*/
	};

	extern int getopt_long(int nargc, char * const *nargv, const char *options,
		const struct option *long_options, int *idx);
	extern int getopt_long_only(int nargc, char * const *nargv, const char *options,
		const struct option *long_options, int *idx);

#ifndef HAVE_DECL_GETOPT
# define HAVE_DECL_GETOPT	1
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif /* !defined(__UNISTD_H_SOURCED__) && !defined(__GETOPT_LONG_H__) */
#endif