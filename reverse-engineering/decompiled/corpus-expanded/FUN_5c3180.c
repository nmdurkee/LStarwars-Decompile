/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3180; label: FUN_005c3180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3180(void)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_0076440c;
  return;
}

