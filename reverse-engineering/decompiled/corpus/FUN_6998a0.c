/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x6998a0; label: FUN_006998a0
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

