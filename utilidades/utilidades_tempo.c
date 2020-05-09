#include "utilidades_tempo.h"

#include <time.h>

float getTempoAtual() {
  return clock()/(float)CLOCKS_PER_SEC;
}

