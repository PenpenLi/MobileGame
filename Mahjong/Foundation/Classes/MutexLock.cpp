#include "stdafx.h"
#include "MutexLock.h"


MutexLock::MutexLock(void)
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&m_Lock, &attr);
}


MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&m_Lock);
}

void MutexLock::Lock()
{
	pthread_mutex_lock(&m_Lock);
}

void MutexLock::Unlock()
{
	pthread_mutex_unlock(&m_Lock);
}