/** @file debuginfo.h ������Ϣ�ӿ� */
/***************************************************************************
 *   Copyright (C) 2012 by stargui   *
 *   stargui@localhost.localdomain   *
 *                                                                         * 
 ***************************************************************************/
#ifndef __DEBUGINFO_H__
#define __DEBUGINFO_H__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>
#include <errno.h>

int DebugSetLevel( int level );
int DebugGetLevel();

int DebugSetTarget( int target );
int DebugGetTarget();

void DebugPrintf(int level, const char *file, const char *func, int line, const char *fmt, ...);
int DebugFramerate( unsigned long *frames, unsigned long *ticks, int len, const char *fmt, ...);

void DebugSetDevelopMode(int sig);

#define LEVEL_ERROR		0
#define LEVEL_CRITICAL	1
#define LEVEL_WARNING	2
#define LEVEL_MESSAGE	3
#define LEVEL_DEBUG		4

#define TARGET_STDERR   0
#define TARGET_SYSLOG   1
#define TARGET_NULL     2

#define DEBUG_SETLEVEL(level) DebugSetLevel((level))

#define DEBUG_SETTARGET(target) DebugSetTarget((target))

#define DEBUG_SUPPORTSYSLOG() signal(SIGUSR1,DebugSetDevelopMode);

/** 
@def DEBUG_ERROR(fmt...)
@brief	������Ϣ��ӡ��. ������ʽͬprintf. \n
	@b Example: \n
		- DEBUG_ERROR("this is test %s, %d", "hello", 1234 );
		.	
 */
#define DEBUG_ERROR(fmt...) DebugPrintf(LEVEL_ERROR, __FILE__, __FUNCTION__, __LINE__, fmt)
/** 
@def DEBUG_CRITICAL(fmt...)
@brief	������Ϣ��ӡ��. ������ʽͬ DEBUG_ERROR. \n
 */
#define DEBUG_CRITICAL(fmt...) DebugPrintf(LEVEL_CRITICAL, __FILE__, __FUNCTION__, __LINE__, fmt)
/** 
@def DEBUG_WARNING(fmt...)
@brief	������Ϣ��ӡ��. ������ʽͬ DEBUG_ERROR. \n
 */
#define DEBUG_WARNING(fmt...) DebugPrintf(LEVEL_WARNING, __FILE__, __FUNCTION__, __LINE__, fmt)
/** 
@def DEBUG_MESSAGE(fmt...)
@brief	������Ϣ��ӡ��. ������ʽͬ DEBUG_ERROR. \n
 */
#define DEBUG_MESSAGE(fmt...) DebugPrintf(LEVEL_MESSAGE, __FILE__, __FUNCTION__, __LINE__, fmt)
/** 
@def DEBUG_DEBUG(fmt...)
@brief	������Ϣ��ӡ��. ������ʽͬ DEBUG_ERROR. \n
 */
#define DEBUG_DEBUG(fmt...) DebugPrintf(LEVEL_DEBUG, __FILE__, __FUNCTION__, __LINE__, fmt)
/** 
@def DEBUG_FRAMERATE(a,b,c,fmt...)
@brief ͳ�ƺ�����ͳ�����ʡ�
*/
#define DEBUG_FRAMERATE(a,b,c,fmt...) DebugFramerate((a),(b),(c),fmt)

#endif

