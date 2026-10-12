/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x6998a0; label: FUN_006998a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006998a0(void)

{
  MMRESULT MVar1;
  int in_ECX;
  
  if (*(UINT *)(in_ECX + 100) != 0) {
    timeKillEvent(*(UINT *)(in_ECX + 100));
  }
  MVar1 = timeSetEvent(500,100,*(LPTIMECALLBACK *)(in_ECX + 0x5c),0,0x21);
  *(MMRESULT *)(in_ECX + 100) = MVar1;
  return;
}

