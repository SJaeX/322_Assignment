/**
 * A test program 1
 */
#include <climits>
#include <iostream>
#include <unistd.h>
#include "label_weight_pair.h"
#include "pq.h"

using namespace std;

unsigned get_rand_in_range (unsigned low, unsigned high);

int main()
{
  srand(static_cast<unsigned>(time(nullptr) % getpid()));
  PQ<LabelWeightPair> pq;

  for (size_t item {0}; item < 10; item++)
  {
    pq.push({item, get_rand_in_range(10, 100)});
  }
  cout << "at start, PQ is: " << pq.to_string() << endl;

  while (pq.size() != 0)
  {
    LabelWeightPair item {pq.top()};
    pq.pop();
    cout << "removed item: " << item.to_string() << endl;
    cout << "PQ is now: " << pq.to_string() << endl;
  }

  return 0;
}

unsigned get_rand_in_range (unsigned low, unsigned high)
{
  unsigned value {static_cast<unsigned>(rand()) % (high - low + 1) + low};
  return value;
}
