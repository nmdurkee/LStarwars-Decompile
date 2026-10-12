/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x6998d0; label: FUN_006998d0
 */

void FUN_006998d0(void)

{
  int in_ECX;
  
  if (*(UINT *)(in_ECX + 100) != 0) {
    timeKillEvent(*(UINT *)(in_ECX + 100));
  }
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

