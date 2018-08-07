#pragma once
#include "pthread.h"
class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void Lock();
	void Unlock();

public:
	class AutoLoad
	{
	private:
		MutexLock &sp_;
		AutoLoad(MutexLock const &);
		AutoLoad & operator = (MutexLock const &);


	public:
		explicit AutoLoad(MutexLock & sp) :sp_(sp)
		{
			sp.Lock();
		}

		~AutoLoad()
		{
			sp_.Unlock();
		}
	};
private:
	pthread_mutex_t m_Lock;
};

