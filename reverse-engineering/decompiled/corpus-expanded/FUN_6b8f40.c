/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b8f40; label: FUN_006b8f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8f40(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    in_ECX[3] = &PTR_FUN_0076f7e8;
    *in_ECX = &PTR_FUN_0076b5b4;
    return;
  }
  ppuRam00000000 = &PTR_FUN_0076b5b4;
  return;
}

