/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3150; label: FUN_005c3150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3150(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[0x27] = 0x3f800000;
  *in_ECX = &PTR_FUN_007643e0;
  return;
}

