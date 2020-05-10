/*#########################################################################*/
#if 1                                                     /* DOCUMENTATION */
/* ---------------------------------------------------------------------------
 * HARDFORM.H : minimalist single-header platform wrangler
 * ---------------------------------------------------------------------------
 *  Created on: 11 mar 2019
 *  Updated on: 11 apr 2020
 *  Updated on:  8 may 2020
 *      Author: Martin Andreasson
 *     Version: 0.1
 *     License: Mozilla Public License Version 2.0
 * ---------------------------------------------------------------------------
 * This is a single-header library for detecting compiler and platform.
 * Usage: Simply #include "HARDFORM.H"!
 * ---------------------------------------------------------------------------
 * MOST OF IT IS UNDER THE HF_/hf_ NAMESPACES EXCEPT FOR BASIC TYPES +5 MACROS
 * ---------------------------------------------------------------------------
 * Types in the global namespace:
 * ---------------------------------------------------------------------------
 *    s08     (  1 byte  of data, signed.        )
 *    s16     (  2 bytes of data, signed.        )
 *    s32     (  4 bytes of data, signed.        )
 *    s64     (  8 bytes of data, signed.        )
 *    u08     (  1 byte  of data, unsigned.      )
 *    u16     (  2 bytes of data, unsigned.      )
 *    u32     (  4 bytes of data, unsigned.      )
 *    u64     (  8 bytes of data, unsigned.      )
 *   byte     (  ONE BYTE                        )
 *   cstr     (  const char c-string.            )
 *    f32     (  4 byte float.                   )
 *    f64     (  8 byte float.                   )
 *    ldf     (  8+ byte long double float.      )
 * bool08     (  8-bit boolean.                  )
 * bool16     ( 16-bit boolean.                  )
 * bool32     ( 32-bit boolean.                  )
 * bool64     ( 64-bit boolean.                  )
 * hbool      ( fastest type for a boolean.      )
 * char08     (  1 byte char, signed.   (UTF-8)  )
 * char16     (  2 byte char, unsigned. (UTF-16) )
 * char32     (  4 byte char, unsigned. (UTF-32) )
 * char64     (  8 byte char. (UTF-64/codepoint) )
 *    any     ( opaque pointer for all compilers )
 *   hf_u     ( integer, platform based size, unsigned, same as size_t )
 *   hf_i     ( signed integer, platform based size, same as ptrdiff_t )
 * hf_size    ( alias of hf_u, to self-document your code for measures )
 * hf_idx     ( alias of hf_u, to self-document your code for indexing )
 * hf_count   ( alias of hf_u, to self-document your code for counting )
 * hf_addr    ( alias of hf_u, to self-document your code - addressing )
 * ---------------------------------------------------------------------------
 * Macros in the global namespace:
 * ---------------------------------------------------------------------------
 * INVALID
 * HEADER_HARDFORM_H_INCLUDED_
 * NULL
 * null
 * NIL
 * ---------------------------------------------------------------------------
 * The following "known" compilers are not identified:
 * > 
 */
#endif                                                    /* DOCUMENTATION */
/*#########################################################################*/
#if defined(_MSC_VER) && (_MSC_VER >= 1020)                  /* MSVC GUARD */
#	pragma once
#endif                                                       /* MSVC GUARD */
/*#########################################################################*/
#ifndef HEADER_HARDFORM_H_INCLUDED_
#define HEADER_HARDFORM_H_INCLUDED_               /* STANDARD HEADER GUARD */
/*#########################################################################*/
#if !defined( _WIN32 ) &&                         /* ONE _WIN32 DEFINITION */\
	( defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__) )
#	define _WIN32
#endif
/*#########################################################################*/
#if 0                                           /* KNOWN LANGUAGE STANDARD */
#	define HF_STANDARD_SUPPORT_KR_C
#	define HF_STANDARD_SUPPORT_ANSI_C89
#	define HF_STANDARD_SUPPORT_ISO_C90
#	define HF_STANDARD_SUPPORT_ISO_C94
#	define HF_STANDARD_SUPPORT_ISO_C99
#	define HF_STANDARD_SUPPORT_ISO_C11
#	define HF_STANDARD_SUPPORT_ISO_C20
#	define HF_STANDARD_SUPPORT_ISO_CPP_98
#	define HF_STANDARD_SUPPORT_ISO_CPP_11
#	define HF_STANDARD_SUPPORT_ISO_CPP_14
#	define HF_STANDARD_SUPPORT_ISO_CPP_17
#	define HF_STANDARD_SUPPORT_ISO_CPP_20
#	define HF_STANDARD_SUPPORT_ECMA_CLI_CPP
#	define HF_STANDARD_SUPPORT_DSP_C
#	define HF_STANDARD_SUPPORT_EMBEDDED_C
#endif                                          /* KNOWN LANGUAGE STANDARD */
/*#########################################################################*/
#ifndef HF_COMPILER                                     /* DETECT COMPILER */
#	if defined(__GNUC__) /* GCC */
#		define HF_COMPILED_BY_GCC_COMPILER
		/* GCC AND MINGW AREN'T MUTUALLY EXCLUSIVE ! */
#		if defined(__MINGW32__) || defined(__MINGW64__)
#			define HF_COMPILED_BY_MINGW_COMPILER
#		endif
#		if defined(__GNUC_PATCHLEVEL__)
#			define HF_COMPILED_BY_COMPILER_VERSION ( \
            __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ )
#		else
#			define HF_COMPILED_BY_COMPILER_VERSION ( \
            __GNUC__ * 10000 + __GNUC_MINOR__ * 100 )
#		endif
#	elif defined(__clang__)
#		if defined(__apple_build_version__)
#			define HF_COMPILED_BY_APPLE_CLANG_COMPILER
#		else
#			define HF_COMPILED_BY_CLANG_COMPILER
#		endif
#		define HF_COMPILED_BY_COMPILER_VERSION __clang_version__
#	elif defined( _MSC_VER )
#		define HF_COMPILED_BY_MSVC_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION _MSC_VER
#		define HF_STANDARD_SUPPORT_ANSI_C89
		/* TODO: Implement standards selection for MSVC (partial support) */
//#		if ( _MSC_VER >= 1914 )
//#			define HF_STANDARD_SUPPORT_ISO_C99
//#			define HF_STANDARD_SUPPORT_ISO_C11
//#		endif
#	elif defined( __POCC__ )
#		define HF_COMPILED_BY_PELLES_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __POCC__
#	elif defined( __TINYC__ )
#		define HF_COMPILED_BY_TINY_C_COMPILER
#	elif defined( __DJGPP__ )
#		define HF_COMPILED_BY_DJGPP_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __DJGPP__
#	elif defined( __PGI )
#		define HF_COMPILED_BY_PORTLAND_GROUP_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION ( \
        __PGIC__ * 10000 + __PGIC_MINOR__ * 100 + __PGIC_PATCHLEVEL__ )
#	elif defined( _ACC_ )
#		define HF_COMPILED_BY_ACC_C_COMPILER
#	elif defined( __CMB__ )
#		define HF_COMPILED_BY_MICROBLAZE_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __VERSION__
#	elif defined( __CHC__ )
#		define HF_COMPILED_BY_ALTIUM_C_TO_HARDWARE_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __VERSION__
#	elif defined( __ACK__ )
#		define HF_COMPILED_BY_AMSTERDAM_COMPILER
#	elif defined( __CC_ARM )
#		define HF_COMPILED_BY_ARM_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __ARMCC_VERSION
#	elif defined( __AZTEC_C__ )
#		define HF_COMPILED_BY_AZTEC_C_COMPILER
#	elif defined( __BORLANDC__ ) || defined( __CODEGEARC__ )
#		define HF_COMPILED_BY_BORLAND_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __BORLANDC__
#	elif defined( __CC65__ )
#		define HF_COMPILED_BY_CC65_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __CC65__
#	elif defined( __COMO__ )
#		define HF_COMPILED_BY_COMEAU_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __COMO_VERSION__
#	elif defined( __DECC )
#		define HF_COMPILED_BY_COMPAQ_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __DECC_VER
#	elif defined( __DECCXX )
#		define HF_COMPILED_BY_COMPAQ_CPP_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __DECCXX_VER
#	elif defined( __VAXC ) || defined( VAXC )
#		define HF_COMPILED_BY_OBSOLETE_COMPAQ_COMPILER
#	elif defined( __convexc__ )
#		define HF_COMPILED_BY_CONVEX_C_COMPILER
#	elif defined( __COMPCERT__ )
#		define HF_COMPILED_BY_COMPCERT_CLIGHT_COMPILER
#	elif defined( __COVERITY__ )
#		define HF_COMPILED_BY_COVERITY_STATIC_ANALYZER
#	elif defined( _CRAYC )
#		define HF_COMPILED_BY_CRAY_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION _RELEASE
#	elif defined( __DCC__ )
#		define HF_COMPILED_BY_DIAB_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __VERSION_NUMBER__
#	elif defined( __DMC__ )
#		define HF_COMPILED_BY_DIGITAL_MARS_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __DMC__
#	elif defined( __SYSC__ )
#		define HF_COMPILED_BY_DIGNUS_SYSTEMS_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __SYSC_VER__
#	elif defined( __EDG__ )
#		define HF_COMPILED_BY_EDG_CPP_FRONTEND_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __EDG_VERSION__
#	elif defined( __PATHCC__ )
#		define HF_COMPILED_BY_EKOPATH_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __PATHCC__
#	elif defined( __FCC_VERSION )
#		define HF_COMPILED_BY_FUJITSU_COMPILER
#	elif defined( __ghs__ )
#		define HF_COMPILED_BY_GREEN_HILL_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __GHS_VERSION_NUMBER__
#	elif defined( __HP_cc )
#		define HF_COMPILED_BY_HP_ANSI_C_COMPILER
#	elif defined( __HP_aCC )
#		define HF_COMPILED_BY_HP_ANSI_CPP_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __HP_aCC
#		define HF_STANDARD_SUPPORT_ISO_CPP_98
#	elif defined( __IAR_SYSTEMS_ICC__ )
#		define HF_COMPILED_BY_IAR_CC_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __VER__
#	elif defined( __ibmxl__ )
#		define HF_COMPILED_BY_IBM_XL_CC_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __ibmxl_vrm__
#	elif defined( __xlC__ )
#		define HF_COMPILED_BY_IBM_XL_CC_LEGACY_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __IBMC__
#	elif defined(__IBMC__)
#		if defined(__COMPILER_VER__)
#			define HF_COMPILED_BY_IBM_ZOS_XL_C_COMPILER
#		else
#			define HF_COMPILED_BY_IBM_XL_C_COMPILER
#		endif
#		define HF_COMPILED_BY_COMPILER_VERSION __IBMC__
#	elif defined(__IBMCPP__)
#		if defined(__COMPILER_VER__)
#			define HF_COMPILED_BY_IBM_ZOS_XL_CPP_COMPILER
#		else
#			define HF_COMPILED_BY_IBM_XL_CPP_COMPILER
#		endif
#		define HF_COMPILED_BY_COMPILER_VERSION __IBMCPP__
#	elif defined( __IMAGECRAFT__ )
#		define HF_COMPILED_BY_IMAGECRAFT_C_COMPILER
#	elif defined( __INTEL_COMPILER )
#		define HF_COMPILED_BY_INTEL_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __INTEL_COMPILER
#	elif defined( __ICL )
#		define HF_COMPILED_BY_INTEL_COMPILER
#	elif defined( __ECC ) || defined( __ICC )
#		define HF_COMPILED_BY_OBSOLETE_INTEL_COMPILER
#	elif defined( __KCC )
#		define HF_COMPILED_BY_KAI_CPP_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __KCC_VERSION
#	elif defined( __CA__ ) || defined( __KEIL__ )
#		define HF_COMPILED_BY_KEIL_CARM_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __CA__
#	elif defined( __C166__ )
#		define HF_COMPILED_BY_KEIL_C166_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __C166__
#	elif defined( __C51__ ) || defined( __CX51__ )
#		define HF_COMPILED_BY_KEIL_C51_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __C51__
#	elif defined( __LCC__ )
#		define HF_COMPILED_BY_LCC_COMPILER
#	elif defined( __llvm__ )
#		define HF_COMPILED_BY_LLVM_COMPILER
#	elif defined( __HIGHC__ )
#		define HF_COMPILED_BY_METAWARE_HIGH_C_COMPILER
#	elif defined( __CWCC__ )
#		define HF_COMPILED_BY_CODEWARRIOR_CC_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __CWCC__
#	elif defined( __MWERKS__ )
#		define HF_COMPILED_BY_METROWERKS_CODEWARRIOR_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __MWERKS__
#	elif defined( _MRI )
#		define HF_COMPILED_BY_MICROTEC_C_COMPILER
#	elif defined( __NDPC__ ) || defined( __NDPX__ )
#		define HF_COMPILED_BY_MICROWAY_NDP_C_COMPILER
#	elif defined( __sgi ) || defined( sgi )
#		define HF_COMPILED_BY_MIPSPRO_COMPILER
#		ifdef _SGI_COMPILER_VERSION
#			define HF_COMPILED_BY_COMPILER_VERSION _SGI_COMPILER_VERSION
#		else
#			define HF_COMPILED_BY_COMPILER_VERSION _COMPILER_VERSION
#		endif
#	elif defined( MIRACLE )
#		define HF_COMPILED_BY_MIRACLE_C_COMPILER
#	elif defined( __MRC__ ) || defined( MPW_C ) || defined( MPW_CPLUS )
#		define HF_COMPILED_BY_MPW_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __MRC__
#	elif defined( __CC_NORCROFT )
#		define HF_COMPILED_BY_NORCROFT_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __ARMCC_VERSION /* A FLOAT! */
#	elif defined( __NWCC__ )
#		define HF_COMPILED_BY_NWCC_C_COMPILER
#	elif defined( __OPEN64__ )
#		define HF_COMPILED_BY_OPEN64_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __OPEN64__ /* A STRING */
#	elif defined( ORA_PROC )
#		define HF_COMPILED_BY_ORACLE_PRO_C_PRECOMPILER
#	elif defined( __SUNPRO_C )
#		define HF_COMPILED_BY_ORACLE_SOLARIS_STUDIO_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __SUNPRO_C
#	elif defined( __SUNPRO_CC )
#		define HF_COMPILED_BY_ORACLE_SOLARIS_STUDIO_CPP_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __SUNPRO_CC
#	elif defined( __PACIFIC__ )
#		define HF_COMPILED_BY_PACIFIC_C_COMPILER
#	elif defined( _PACC_VER )
#		define HF_COMPILED_BY_PALM_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION _PACC_VER
#	elif defined( __RENESAS__ )
#		define HF_COMPILED_BY_RENESAS_COMPILER
#		ifdef __RENESAS_VERSION__
#			define HF_COMPILED_BY_COMPILER_VERSION __RENESAS_VERSION__
#		else
#			define HF_COMPILED_BY_COMPILER_VERSION __HITACHI_VERSION__
#		endif
#	elif defined( SASC ) || defined( __SASC ) || defined( __SASC__ )
#		define HF_COMPILED_BY_SAS_C_COMPILER
#		ifdef __SASC__
#			define HF_COMPILED_BY_COMPILER_VERSION __SASC__
#		else
#			define HF_COMPILED_BY_COMPILER_VERSION __VERSION__
#		endif
#	elif defined( _SCO_DS )
#		define HF_COMPILED_BY_SCO_OPENSERVER_C_COMPILER
#	elif defined( SDCC )
#		define HF_COMPILED_BY_SMALL_DEVICE_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION SDCC
#	elif defined( __SNC__ )
#		define HF_COMPILED_BY_SN_C_COMPILER
#	elif defined( __VOSC__ )
#		define HF_COMPILED_BY_STRATUS_VOS_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __VOSC__
#		if __VOSC__ == 0
#			define HF_STANDARD_SUPPORT_KR_C
#		else
#			define HF_STANDARD_SUPPORT_ANSI_C89
#		endif
#	elif defined( __SC__ )
#		define HF_COMPILED_BY_SYMANTEC_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __SC__
#	elif defined( __TenDRA__ )
#		define HF_COMPILED_BY_TENDRA_COMPILER
#	elif defined( __TI_COMPILER_VERSION__ ) || defined( _TMS320C6X )
#		define HF_COMPILED_BY_TEXAS_INSTRUMENTS_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __TI_COMPILER_VERSION__
#	elif defined( THINKC3 ) || defined( THINKC4 )
#		define HF_COMPILED_BY_THINK_C_COMPILER
#		ifdef THINKC4
#			define HF_COMPILED_BY_COMPILER_VERSION 4
#		else
#			define HF_COMPILED_BY_COMPILER_VERSION 3
#		endif
#	elif defined( __TURBOC__ )
#		define HF_COMPILED_BY_TURBO_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __TURBOC__
#	elif defined( _UCC )
#		define HF_COMPILED_BY_ULTIMATE_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION (_MAJOR_REV * 10 + _MINOR_REV)
#	elif defined( __USLC__ )
#		define HF_COMPILED_BY_USL_C_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __SCO_VERSION__
#	elif defined( __VBCC__ )
#		define HF_COMPILED_BY_VBCC_C_COMPILER
#	elif defined( __WATCOMC__ )
        /* Watcom C++ became Open Watcom C++ after version 11.0 */
        /* The official numbering restarted, but not the macro */
#		define HF_COMPILED_BY_WATCOM_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __WATCOMC__
#	elif defined( __ZTC__ )
#		define HF_COMPILED_BY_ZORTECH_COMPILER
#		define HF_COMPILED_BY_COMPILER_VERSION __ZTC__
#	else
#		error "unknown compiler!" 
#	endif
#endif                                                  /* DETECT COMPILER */
/*#########################################################################*/
#ifndef HF_PLATFORM                                     /* DETECT PLATFORM */
#	define HF_PLATFORM_NONE    0 /* Suspended :) */
#	define HF_PLATFORM_DOS     1 /* DOS BOX     */
#	define HF_PLATFORM_WIN     2 /* Windows    */
#	define HF_PLATFORM_LINUX   3 /* LiNUX     */
#	define HF_PLATFORM_OSX     4 /* MAC      */
#	define HF_PLATFORM_ANDROID 5 /* Android */
#	if defined(_WIN32)
#		define HF_PLATFORM HF_PLATFORM_WIN
#	elif defined(ANDROID)||defined(PLATFORM_ANDROID)||defined(__ANDROID_API__)
#		define HF_PLATFORM HF_PLATFORM_ANDROID
#		define HF_UNIX_PLATFORM
#	elif defined(__linux__)
#		define HF_PLATFORM HF_PLATFORM_LINUX
#		define HF_UNIX_PLATFORM
#	elif defined(__APPLE_CC__) || defined(BSD)
#		define HF_PLATFORM HF_PLATFORM_OSX
#		define HF_UNIX_PLATFORM
#	else
#		define HF_PLATFORM HF_PLATFORM_NONE
#		error unknown platform
#	endif
#endif                                                  /* DETECT PLATFORM */
/*#########################################################################*/
#ifndef HF_STANDARD_IS_KNOWN                            /* KNOWN STANDARD? */
#	if  defined( HF_STANDARD_SUPPORT_KR_C          ) || \
		defined( HF_STANDARD_SUPPORT_ANSI_C89      ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C90       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C94       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C99       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C11       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C20       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_98    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_11    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_14    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_17    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_20    ) || \
		defined( HF_STANDARD_SUPPORT_ECMA_CLI_CPP  ) || \
		defined( HF_STANDARD_SUPPORT_DSP_C         ) || \
		defined( HF_STANDARD_SUPPORT_EMBEDDED_C    )
#			define HF_STANDARD_IS_KNOWN
#	endif
#endif                                                  /* KNOWN STANDARD? */
/*#########################################################################*/
#ifndef HF_STANDARD_IS_KNOWN                            /* WHICH STANDARD? */
#	if defined( __embedded_cplusplus )
#		define HF_STANDARD_SUPPORT_EMBEDDED_C
#	elif defined(__STDC__)
#		if defined( __STDC_VERSION__ )
#			if   ( __STDC_VERSION__ >= 202000L ) /* C20 */
#				define HF_STANDARD_SUPPORT_ISO_C20
#				define HF_STANDARD_SUPPORT_ISO_C11
#				define HF_STANDARD_SUPPORT_ISO_C99
#				define HF_STANDARD_SUPPORT_ISO_C94
#				define HF_STANDARD_SUPPORT_ISO_C90
#				define HF_STANDARD_SUPPORT_ANSI_C89
#			elif ( __STDC_VERSION__ >= 201112L ) /* C11 */
#				define HF_STANDARD_SUPPORT_ISO_C11
#				define HF_STANDARD_SUPPORT_ISO_C99
#				define HF_STANDARD_SUPPORT_ISO_C94
#				define HF_STANDARD_SUPPORT_ISO_C90
#				define HF_STANDARD_SUPPORT_ANSI_C89
#			elif ( __STDC_VERSION__ >= 199901L ) /* C99 */
#				define HF_STANDARD_SUPPORT_ISO_C99
#				define HF_STANDARD_SUPPORT_ISO_C94
#				define HF_STANDARD_SUPPORT_ISO_C90
#				define HF_STANDARD_SUPPORT_ANSI_C89
#			elif ( __STDC_VERSION__ >= 199409L ) /* C94 */
#				define HF_STANDARD_SUPPORT_ISO_C94
#				define HF_STANDARD_SUPPORT_ISO_C90
#				define HF_STANDARD_SUPPORT_ANSI_C89
#			endif
#		else
// WHICH ONE ?
//#A:		define HF_STANDARD_SUPPORT_ANSI_C89
//#B:		define HF_STANDARD_SUPPORT_ISO_C90
#		endif
#	elif defined( __cplusplus )
#		if   ( __cplusplus >= 201900L ) /* C++20 */
#			define HF_STANDARD_SUPPORT_ISO_CPP_20
#		elif ( __cplusplus >= 201600L ) /* C++17 */
#			define HF_STANDARD_SUPPORT_ISO_CPP_17
#		elif ( __cplusplus >= 201402L ) /* C++14 */
#			define HF_STANDARD_SUPPORT_ISO_CPP_14
#		elif ( __cplusplus >= 201103L ) /* C++11 */
#			define HF_STANDARD_SUPPORT_ISO_CPP_11
#		elif ( __cplusplus >= 199711L ) /* C++98 */
#			define HF_STANDARD_SUPPORT_ISO_CPP_98
#		endif
#	else
#		define HF_STANDARD_SUPPORT_DSP_C /* just left with DSP-C :( */
#	endif
#endif                                                  /* WHICH STANDARD? */
/*#########################################################################*/
#ifndef HF_STANDARD_IS_KNOWN                            /* KNOWN STANDARD? */
#	if defined( HF_STANDARD_SUPPORT_KR_C           ) || \
		defined( HF_STANDARD_SUPPORT_ANSI_C89      ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C90       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C94       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C99       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C11       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_C20       ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_98    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_11    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_14    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_17    ) || \
		defined( HF_STANDARD_SUPPORT_ISO_CPP_20    ) || \
		defined( HF_STANDARD_SUPPORT_ECMA_CLI_CPP  ) || \
		defined( HF_STANDARD_SUPPORT_DSP_C         ) || \
		defined( HF_STANDARD_SUPPORT_EMBEDDED_C    )
#			define HF_STANDARD_IS_KNOWN
#	endif
#endif                                                  /* KNOWN STANDARD? */
/*#########################################################################*/
#if 1                                                           /* PRE-C89 */
#	if !defined( HF_STANDARD_SUPPORT_ANSI_C89 ) \
	&& !defined( __cplusplus ) 
#		define const
#		define volatile
#	endif
#endif                                                          /* PRE-C89 */
/*#########################################################################*/
#if 1                                                           /* DEBUG ? */
#	if defined( NDEBUG ) || defined( _NDEBUG )
#		define HF_RELEASE
#	elif defined( DEBUG ) || defined( _DEBUG )
#		define HF_DEBUG
#	else
#		error "cannot tell if build is for debugging or releasing..."
#	endif
#endif                                                          /* DEBUG ? */
/*#########################################################################*/
#ifndef HF_PLATFORM_BASED_SELECT                   /* PLATFORM COMPILATION */
#	if HF_PLATFORM == HF_PLATFORM_WIN
#		define HF_PLATFORM_BASED_SELECT(win,lin,mac) win
#	elif HF_PLATFORM == HF_PLATFORM_LINUX
#		define HF_PLATFORM_BASED_SELECT(win,lin,mac) lin
#	elif HF_PLATFORM == HF_PLATFORM_OSX
#		define HF_PLATFORM_BASED_SELECT(win,lin,mac) mac
#	endif
#endif                                             /* PLATFORM COMPILATION */
/*#########################################################################*/
#ifndef HF_FUNCTION_NAME                         /* INSTUMENTATION SUPPORT */
#	if   HF_COMPILER == HF_COMPILER_MSVC
#		define HF_FUNCTION_NAME __FUNCSIG__ /* __FUNCTION__  */
#	elif HF_COMPILER == HF_COMPILER_GCC
#		define HF_FUNCTION_NAME __PRETTY_FUNCTION__ // __func__
#	elif HF_COMPILER == HF_COMPILER_CLANG
#		define HF_FUNCTION_NAME __func__
#	elif HF_COMPILER == HF_COMPILER_PELLE
#		define HF_FUNCTION_NAME __func__
#	else
#		error "no function name macro defined for this compiler"
#	endif
#endif                                           /* INSTUMENTATION SUPPORT */
/*#########################################################################*/
/** This should be set in the compiler settings */
#ifndef HF_WORKSPACE_PATH                                /* WORKSPACE PATH */
#	define HF_WORKSPACE_PATH R"(C:\)" /* R"($(SolutionDir)) for MSVC */
#endif                                                   /* WORKSPACE PATH */
/*#########################################################################*/
#ifndef HF_PLATFORM_ADDRESSWIDTH                          /* ADDRESS WIDTH */
#	if defined( HF_COMPILE_64 )
#		define HF_PLATFORM_ADDRESSWIDTH 64
#	elif defined( __GNUC__ ) // GCC
#		if defined( __x86_64__ ) || defined( __ppc64__ )
#			define HF_PLATFORM_ADDRESSWIDTH 64
#		else
#			define HF_PLATFORM_ADDRESSWIDTH 32
#		endif
#	elif defined( HF_COMPILED_BY_MSVC_COMPILER )
#		if defined( _WIN32 )
#			if defined( _WIN64 )
#				define HF_PLATFORM_ADDRESSWIDTH 64
#			else
#				define HF_PLATFORM_ADDRESSWIDTH 32
#			endif
#		else
#			define HF_PLATFORM_ADDRESSWIDTH 32
#		endif
#	elif defined(MP_COMPILED_BY_ACC_COMPILER)
#		define HF_PLATFORM_ADDRESSWIDTH 32 /* ACC pointers always 32 bit */
#	endif
#endif                                                    /* ADDRESS WIDTH */
/*#########################################################################*/
#if !defined( HF_DEBUG_COMPILE )                      /* COMPILE FOR DEBUG */
#	if defined( HF_DEBUG )
#		define HF_DEBUG_COMPILE(x) x
#	else
#		define HF_DEBUG_COMPILE(x) ((void)0)
#	endif
#endif                                                /* COMPILE FOR DEBUG */
/*#########################################################################*/
#if !defined( HF_RELEASE_COMPILE )                  /* COMPILE FOR RELEASE */
#	if defined( HF_DEBUG )
#		define HF_RELEASE_COMPILE(x) ((void)0)
#	else
#		define HF_RELEASE_COMPILE(x) x
#	endif
#endif                                              /* COMPILE FOR RELEASE */
/*#########################################################################*/
#ifndef HF_INLINE                                                /* INLINE */
#	if   defined( HF_COMPILED_BY_GCC_COMPILER )
#		define HF_INLINE inline __attribute__((__always_inline__))
#	elif defined( HF_COMPILED_BY_MSVC_COMPILER )
#		define HF_INLINE __forceinline
#	elif defined( HF_COMPILED_BY_CLANG_COMPILER )
#		define HF_INLINE inline
#	elif defined( HF_COMPILED_BY_PELLES_C_COMPILER )
#		define HF_INLINE inline
#	elif defined( HF_COMPILED_BY_TINYCC_C_COMPILER )
#		define HF_INLINE /* no inline support */
#	else
#		define HF_INLINE 
#		pragma message("WARNING: Implement HF_INLINE macro for this compiler!")
#	endif
#endif                                                           /* INLINE */
/*#########################################################################*/
#if !defined(MP_DEPRECATED)                                 /* DEPRECATION */
#	if   defined( HF_COMPILED_BY_GCC_COMPILER )
#		define HF_DEPRECATED __attribute__((deprecated))
#	elif defined( HF_COMPILED_BY_MSVC_COMPILER )
#		define HF_DEPRECATED __declspec(deprecated)
#	elif defined( HF_COMPILED_BY_CLANG_COMPILER )
#		define HF_DEPRECATED //TODO: Clang function deprecation macro
#	elif defined( HF_COMPILED_BY_PELLES_C_COMPILER )
#		define HF_DEPRECATED //TODO: Pelles C function deprecation macro
#	elif defined( HF_COMPILED_BY_TINYCC_C_COMPILER )
#		define HF_DEPRECATED //TODO: TCC function deprecation macro
#	else
#		pragma message("WARNING: Implement HF_DEPRECATED for this compiler!")
#		define HF_DEPRECATED
#	endif
#endif                                                      /* DEPRECATION */
/*#########################################################################*/
#if !defined(MP_UNUSED)                                          /* IGNORE */
#	define HF_UNUSED(x) (void)(sizeof(x)) //(void)(x)
#endif                                                           /* IGNORE */
/*#########################################################################*/
#if !defined(MP_Min)                                             /* MINMAX */
#	define HF_Min(a,b) ( ((a)<(b)) ? (a) : (b) )
#	define HF_Max(a,b) ( ((a)>(b)) ? (a) : (b) )
#endif                                                           /* MINMAX */
/*#########################################################################*/
#if 1                                                             /* TYPES */
typedef signed char            s08;   /** 1 byte  integer, signed.         */
typedef signed short           s16;   /** 2 bytes integer, signed.         */
typedef signed int             s32;   /** 4 bytes integer, signed.         */
#if defined( HF_COMPILED_BY_MSVC_COMPILER )
    typedef signed __int64     s64;   /** 8 bytes integer, signed.         */
#else
    typedef signed long long   s64;   /** 8 bytes integer, signed.         */
#endif
typedef unsigned char          u08;   /** 1 byte  integer, unsigned.       */
typedef unsigned short         u16;   /** 2 bytes integer, unsigned.       */
typedef unsigned int           u32;   /** 4 bytes integer, unsigned.       */
#if defined( HF_COMPILED_BY_MSVC_COMPILER )
    typedef unsigned __int64   u64;   /** 8 bytes integer, unsigned.       */
#else
    typedef unsigned long long u64;   /** 8 bytes integer, unsigned.       */
#endif
typedef unsigned char         byte;   /** ONE BYTE                         */
typedef const char*           cstr;   /** const char c-string.             */
typedef float                  f32;   /**  4 byte float.                   */
typedef double                 f64;   /**  8 byte float.                   */
typedef long double            ldf;   /**  8+ byte long double float.      */
typedef u08                 bool08;   /**   8-bit boolean.                 */
typedef u16                 bool16;   /**  16-bit boolean.                 */
typedef u32                 bool32;   /**  32-bit boolean.                 */
typedef u64                 bool64;   /**  64-bit boolean.                 */
typedef u08                 char08;   /**  1 byte char, signed.   (UTF-8)  */
typedef u16                 char16;   /**  2 byte char, unsigned. (UTF-16) */
typedef u32                 char32;   /**  4 byte char, unsigned/codepoint */
typedef s64                 char64;   /**  8 byte char...                  */
/*-------------------------------------------------------------------------*/
/* GENERIC OPAQUE POINTER */
#if defined(__STDC__) || defined(__cplusplus) || defined(_MSC_EXTENSIONS)
	typedef void*              any;   /**  VOID*        (anything...)      */
#else
	typedef char*              any;   /**  VOID*        (anything...)      */
#endif /* GENERIC OPAQUE POINTER */
/*-------------------------------------------------------------------------*/
#endif                                                            /* TYPES */
/*#########################################################################*/
#ifndef HF_EOL_TYPE                                                 /* EOL */
#define HF_EOL_TYPE hf_eol_t
enum hf_eol { hf_eol_native, hf_eol_dos, hf_eol_unix };
typedef enum hf_eol hf_eol_t;
#endif                                                              /* EOL */
/*#########################################################################*/
#ifndef NULL                                                       /* NULL */
//#	define NULL (any)(0)
#endif                                                             /* NULL */
/*#########################################################################*/
#ifndef nullp                                                     /* nullp */
#	define nullp (void*)(0)
#endif                                                            /* nullp */
/*#########################################################################*/
#ifndef NIL                                /** NIL (REPEAT INITIALIZATION) */
#	define NIL {0,}
#endif                                     /** NIL (REPEAT INITIALIZATION) */
/*#########################################################################*/
#if defined( HF_COMPILED_BY_MSVC_COMPILER )             /* VARIADIC MACROS */
#	if (_MSC_VER >= 1300)
#		define HF_COMPILER_SUPPORTS_VARIADIC_MACRO
#	endif
#elif defined( HF_COMPILED_BY_CLANG_COMPILER )
#	define HF_COMPILER_SUPPORTS_VARIADIC_MACRO
#elif defined( HF_COMPILED_BY_GCC_COMPILER )
#	define HF_COMPILER_SUPPORTS_VARIADIC_MACRO
#else
#	error "TODO: add test for this compiler's variadic macro support"
#endif                                                  /* VARIADIC MACROS */
/*#########################################################################*/
#ifndef HF_MACRO_MAGIC                                      /* MACRO MAGIC */
#define HF_MACRO_MAGIC 1

#define HF_CONCAT_HELP(a, b) a##b
#define HF_CONCAT(a, b) HF_CONCAT_HELP(a, b)

/* These can't be used after statements in c89 */
#	ifdef __COUNTER__ 
#		define HF_CASSERT( e, m ) /** Constant Assertion **/ \
		enum { HF_CONCAT(static_assert_, __COUNTER__) = 1/(int)(!!(e)) }
#	else /** can't be used twice on the same line */
#		define HF_CASSERT( e, m ) \
		enum { HF_CONCAT(assert_line_, __LINE__) = 1/(int)(!!(e)) }
#	endif

#endif                                                      /* MACRO MAGIC */
/*#########################################################################*/
#if 1                                                            /* LIMITS */

#define HF_BYTES_IN_S08 sizeof( s08 )
#define HF_BYTES_IN_S16 sizeof( s16 )
#define HF_BYTES_IN_S32 sizeof( s32 )
#define HF_BYTES_IN_S64 sizeof( s64 )

#define HF_BYTES_IN_U08 sizeof( u08 )
#define HF_BYTES_IN_U16 sizeof( u16 )
#define HF_BYTES_IN_U32 sizeof( u32 )
#define HF_BYTES_IN_U64 sizeof( u64 )

#define HF_BITS_IN_S08 (8 * HF_BYTES_IN_S08)
#define HF_BITS_IN_S16 (8 * HF_BYTES_IN_S16)
#define HF_BITS_IN_S32 (8 * HF_BYTES_IN_S32)
#define HF_BITS_IN_S64 (8 * HF_BYTES_IN_S64)

#define HF_BITS_IN_U08 (8 * HF_BYTES_IN_U08)
#define HF_BITS_IN_U16 (8 * HF_BYTES_IN_U16)
#define HF_BITS_IN_U32 (8 * HF_BYTES_IN_U32)
#define HF_BITS_IN_U64 (8 * HF_BYTES_IN_U64)


#define L0s 0LL
#define L1s 1LL
#define L0u 0ULL
#define L1u 1ULL

#define HF_LIMIT_MIN_S08 (( s08 )-(L1s << (HF_BITS_IN_S08 - L1s)))
#define HF_LIMIT_MIN_S16 (( s16 )-(L1s << (HF_BITS_IN_S16 - L1s)))
#define HF_LIMIT_MIN_S32 (( s32 )-(L1s << (HF_BITS_IN_S32 - L1s)))
#define HF_LIMIT_MIN_S64 (( s64 )((u64)(L1u << (HF_BITS_IN_S64 - L1u))))

#define HF_LIMIT_MAX_S08 (( s08 )((L1u << (HF_BITS_IN_S08 - L1u))-L1u))
#define HF_LIMIT_MAX_S16 (( s16 )((L1u << (HF_BITS_IN_S16 - L1u))-L1u))
#define HF_LIMIT_MAX_S32 (( s32 )((L1u << (HF_BITS_IN_S32 - L1u))-L1u))
#define HF_LIMIT_MAX_S64 (( s64 )((L1u << (HF_BITS_IN_S64 - L1u))-L1u))

#define HF_LIMIT_MIN_U08 (( u08 )L0u)
#define HF_LIMIT_MIN_U16 (( u16 )L0u)
#define HF_LIMIT_MIN_U32 (( u32 )L0u)
#define HF_LIMIT_MIN_U64 (( u64 )L0u)

#define HF_LIMIT_MAX_U08 (( u08 )0xFFU)                 /* 255 */
#define HF_LIMIT_MAX_U16 (( u16 )0xFFffU)               /* 65535 */
#define HF_LIMIT_MAX_U32 (( u32 )0xFFffFFffU)           /* 4294967295 */
#define HF_LIMIT_MAX_U64 (( u64 )0xFFffFFffFFffFFffULL) /* ... */

#define HF_MIDDLE_U08 (( u08 )(L1u << (HF_BITS_IN_U08 - L1u))) /* 127 */
#define HF_MIDDLE_U16 (( u16 )(L1u << (HF_BITS_IN_U16 - L1u))) /* 32K */
#define HF_MIDDLE_U32 (( u32 )(L1u << (HF_BITS_IN_U32 - L1u))) /* 2 G */
#define HF_MIDDLE_U64 (( u64 )(L1u << (HF_BITS_IN_U64 - L1u))) /* ... */

#endif                                                           /* LIMITS */
/*#########################################################################*/
#if 1                                                       /* SIZE CHECKS */
	HF_CASSERT( sizeof(u08) == 1, u08 ); /* check the fixed size data type */
	HF_CASSERT( sizeof(s08) == 1, s08 ); /* check the fixed size data type */
	HF_CASSERT( sizeof(u16) == 2, u16 ); /* check the fixed size data type */
	HF_CASSERT( sizeof(s16) == 2, s16 ); /* check the fixed size data type */
	HF_CASSERT( sizeof(u32) == 4, u32 ); /* check the fixed size data type */
	HF_CASSERT( sizeof(s32) == 4, s32 ); /* check the fixed size data type */
	HF_CASSERT( sizeof(u64) == 8, u64 ); /* check the fixed size data type */
	HF_CASSERT( sizeof(s64) == 8, s64 ); /* check the fixed size data type */
#endif                                                      /* SIZE CHECKS */
/*#########################################################################*/
#ifndef HF_PLATFORM_SIZE_TYPE_DEFINED                            /* SIZE_T */
#	if HF_PLATFORM_ADDRESSWIDTH == 8                        /** 8-Bit Era */
		typedef s08 sval;                                  /**  Signed   */
		typedef u08 uval;                                 /** Unsigned  */
		typedef u08 hf_size;                             /** Size Type */
		typedef bool08 hbool;                           /** Bool Type */
		HF_CASSERT( sizeof( void * ) == 1, pointer_not_8_bit );
#	elif HF_PLATFORM_ADDRESSWIDTH == 16                    /** 16-Bit Era */
		typedef s16 sval;                                 /**   Signed   */
		typedef u16 uval;                                /**  Unsigned  */
		typedef u16 hf_size;                            /**  Size Type */
		typedef bool16 hbool;                          /**  Bool Type */
		HF_CASSERT( sizeof( void * ) == 2, pointer_not_16_bit );
#	elif HF_PLATFORM_ADDRESSWIDTH == 32                    /** 32-Bit Era */
		typedef s32 sval;                                 /**   Signed   */
		typedef u32 uval;                                /**  Unsigned  */
		typedef u32 hf_size;                            /**  Size Type */
		typedef bool32 hbool;                          /**  Bool Type */
		HF_CASSERT( sizeof( void * ) == 4, pointer_not_32_bit );
#	elif HF_PLATFORM_ADDRESSWIDTH == 64                    /** 64-Bit Era */
		typedef s64 sval;                                 /**   Signed   */
		typedef u64 uval;                                /**  Unsigned  */
		typedef u64 hf_size;                            /**  Size Type */
		typedef bool32 hbool;                          /**  Bool Type */
		HF_CASSERT( sizeof( void * ) == 8, pointer_not_64_bit );
#	elif HF_PLATFORM_ADDRESSWIDTH == 128                  /** 128-Bit Era */
		typedef s128 sval;                               /**    Signed   */
		typedef u128 uval;                              /**   Unsigned  */
		typedef u128 hf_size;                          /**   Size Type */
		typedef bool64 hbool;                         /**   Bool Type */
		HF_CASSERT( sizeof( void * ) == 16, pointer_not_128_bit );
#	else
#		error "Address Width Unknown. Define HF_COMPILE_xx"
#	endif
#endif                                                           /* SIZE_T */
/*#########################################################################*/
/** For performance, bools are stored in the most performant native format */
#ifndef HF_BOOL_TYPE
#	define HF_BOOL_TYPE hbool
/**/enum { hf_false = 0, hf_true = 1 };
#endif
/*#########################################################################*/
typedef hf_size hf_idx;         /** Alias of hf_size used during indexing. */
typedef hf_size hf_count;       /** Alias of hf_size used during counting. */
typedef hf_size hf_addr;        /** Alias of hf_size used  for addressing. */
typedef hf_size hf_result;      /** Alias of hf_size used as a returncode. */
/*#########################################################################*/
#ifndef INVALID /* INVALID Indicates an invalid index, end of buffer, etc. */
#define INVALID (~((hf_idx)0))
#define INVALID_U32 (~((u32)0))
#endif
#ifndef HF_BIT
#define HF_BIT(x) (1 << x)
#endif
#ifndef HF_TEST
#define HF_TEST( FLAGS, FLAG ) ( (FLAGS & FLAG) == FLAG )
#endif
#ifndef HF_PACK_BYTES_IN_UINT32
#define HF_PACK_BYTES_IN_UINT32( c0, c1, c2, c3 ) \
    (((u32)(u08)(c0) << 24u) | \
    ( (u32)(u08)(c1) << 16u) | \
    ( (u32)(u08)(c2) <<  8u) | \
    ( (u32)(u08)(c3)         ) )
#endif
/*#########################################################################*/
/**
 * This sets the macro which is expected future logger and memory tracker.
 * The macro is called HF_SOURCE_FILEPATH and works like a __FILE__ macro.
 * 
 * The difference here is that this one has a bit of user-overhead, but
 * in exchange for this overhead (user must call my installation macro)
 * we will get nice and short but always full relative paths to sources.
 * 
 * We use this in the logger and memory tracker so we get nice messages.
 * 
 * TODO: Create a better solution for a custom __FILE__ macro.
 */
#ifndef HF_SOURCE_FILEPATH_INSTALL
#define HF_SOURCE_FILEPATH_INSTALL( ENTER_FILEPATH_HERE ) \
    static const char* const HF_SOURCE_FILEPATH = ENTER_FILEPATH_HERE
#endif
/*#########################################################################*/
#ifndef HF_ARRAY_LEN                         /** Compile-Time Array Length */
#define HF_ARRAY_LEN( ARRAY ) ( (sizeof (ARRAY))/(sizeof *(ARRAY) ) )
#endif                                       /** Compile-Time Array Length */
/*#########################################################################*/
/**
 * @def HF_THREAD_LOCAL
 * Thread local storage keyword macro.
 */
#ifndef HF_THREAD_LOCAL
#	if   defined( HF_COMPILED_BY_GCC_COMPILER )
#		define HF_THREAD_LOCAL __thread
#	elif defined( HF_COMPILED_BY_CLANG_COMPILER )
#		define HF_THREAD_LOCAL _Thread_local
#	elif defined( HF_COMPILED_BY_MSVC_COMPILER )
#		define HF_THREAD_LOCAL __declspec(thread)
#	elif __STDC_VERSION__ >= 201112L
#		define HF_THREAD_LOCAL _Thread_local
#	else
#		define HF_THREAD_LOCAL 
#		error "Thread local storage is not supported; Implement the macro."
#	endif
#endif                                                              /* TLS */
/*#########################################################################*/
#ifndef HF_RESTRICT                                         /* RESTRICTION */
#	if defined( HF_COMPILED_BY_MSVC_COMPILER )
		/* "the use of 'restrict' is unsupported in msvc" */
#		if (_MSC_VER <= 1200)
#			define HF_RESTRICT /* not available in VC++ 6 */
#		else
#			define HF_RESTRICT __restrict
#		endif
#	elif defined( HF_COMPILED_BY_CLANG_COMPILER )
#		define HF_RESTRICT __restrict /* supported by gcc,clang,msvc */
#	elif defined( HF_COMPILED_BY_GCC_COMPILER )
#		define HF_RESTRICT restrict
#	else
#		error "restrict is not supported - check compiler support"
#	endif
#endif
#ifndef HF_RES /** (shorter) alias */
#	define HF_RES HF_RESTRICT
#endif                                                      /* RESTRICTION */
/*#########################################################################*/
#endif                                      /* HEADER_HARDFORM_H_INCLUDED_ */
/*#########################################################################*/
/* EOF */
