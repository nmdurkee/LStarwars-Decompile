/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5ff760; label: FUN_005ff760
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

