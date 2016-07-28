//
// trunk.cpp for  in /home/duttoo_e/tmp
//
// Made by Duttoo Ervin
// Login   <duttoo_e@epitech.net>
//
// Started on  Fri Apr 15 13:52:20 2016 Duttoo Ervin
// Last update Thu Jul 28 02:38:36 2016 Duttoo Ervin
//

#include "ex1.hpp"

#define	M 2

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

tmutex::tmutex()
{
}

void* tmutex::increment_counter(void *param)
{
  int *counter = static_cast<int*>(param);

  for (int i = 0; i < 100000; ++i)
    {
      pthread_mutex_lock(&mutex);
      ++(*counter);
      pthread_mutex_unlock(&mutex);
    }
  std::cout << "ok its running\n" << std::endl;
  return NULL;
}

int	main()
{
  pthread_t	threads[M];
  int		counter = 0;
  int		th1;
  int		th2;

  th1 = pthread_create(&threads[0], NULL, &tmutex::increment_counter, &counter);
  th2 = pthread_create(&threads[1], NULL, &tmutex::increment_counter, &counter);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  cout << "Fin du test : counter = " << counter << endl;
  if ( th1 != 0 || th2 != 0 )
    {
      cerr<<"Error in thread creation..."<<endl;
      exit(EXIT_FAILURE);
    }
  else
    printf("working\n");
  return 0;
}
