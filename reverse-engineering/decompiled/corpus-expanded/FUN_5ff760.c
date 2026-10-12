/* Ghidra pseudocode, not original source.
 * ev_84daf39e48317c5610d39db166d0a8d3fb26fedafe51c8456603b097e41224df
 * Entry: 0x5ff760; label: FUN_005ff760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ff760(void)

{
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  QueryPerformanceFrequency(&local_8);
  QueryPerformanceCounter(&local_10);
  FUN_006e6b90();
  return;
}

