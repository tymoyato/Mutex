//
// trunk.cpp for  in /home/duttoo_e/tmp
//
// Made by Duttoo Ervin
// Login   <duttoo_e@epitech.net>
//
// Started on  Fri Apr 15 13:52:20 2016 Duttoo Ervin
// Last update Thu Jul 28 02:43:02 2016 Duttoo Ervin
//

#include "ex3.hpp"
#include <stdio.h>

#define	M 2

Mutex::Mutex(void)
{
  int	result = 0;

  result = pthread_mutex_init(&this->mutex_, NULL);
  if (result == 0)
    {
      printf("°°°MUTEX INITIALIZED°°°\n");
    }
}

Mutex::~Mutex(void)
{
  int	result = 0;

  result = pthread_mutex_destroy(&this->mutex_);
  if (result == 0)
    {
      printf("°°°MUTEX DESTROYED°°°\n");
    }
}

IMutex::~IMutex()
{
}

ScopedLock::ScopedLock(void)
{
  Mutex	call;

  call.lock();
}

ScopedLock::~ScopedLock(void)
{
  Mutex	call;

  call.unlock();
}

void	*Mutex::increment_counter(void *param)
{
  int	*counter = static_cast<int*>(param);

  for (int i = 0; i < 100000; ++i)
    {
      ++(*counter);
    }
  std::cout << "ok its running\n" << std::endl;

  return (NULL);
}

void	Mutex::lock(void)
{
  int	result = 0;

  result = pthread_mutex_lock(&this->mutex_);
  if (result == 0)
    {
      printf("°°°MUTEX LOCKED°°°\n");
    }
}

void    Mutex::unlock(void)
{
  int	result = 0;

  result = pthread_mutex_unlock(&this->mutex_);
  if (result == 0)
    {
      printf("°°°MUTEX UNLOCKED°°°\n");
    }
}

int	main()
{
  pthread_t	threads[M];
  //Mutex	test;
  ScopedLock	scop;
  int		counter = 0;
  int		th1;
  int		th2;

  th1 = pthread_create(&threads[0], NULL, &Mutex::increment_counter, &counter);
  pthread_join(threads[0], NULL);

  th2 = pthread_create(&threads[1], NULL, &Mutex::increment_counter, &counter);
  pthread_join(threads[1], NULL);

  cout << "Fin du test : counter = " << counter << endl;
  if ( th1 != 0 || th2 != 0 )
    {
      cerr<<"Error in thread creation..."<<endl;
      exit(EXIT_FAILURE);
    }
  else
    printf("working\n");
  return (0);
}
