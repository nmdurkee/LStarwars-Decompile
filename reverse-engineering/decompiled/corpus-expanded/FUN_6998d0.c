/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x6998d0; label: FUN_006998d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

