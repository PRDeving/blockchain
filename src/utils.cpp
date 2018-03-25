#include <time.h>
#include "utils.hpp"

unsigned int Utils::timestamp() {
  time_t timestamp_sec;
  time(&timestamp_sec);
  return (int)timestamp_sec;
}
