/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4e30; label: FUN_005c4e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4e30(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0x3f800000;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[8] = 0;
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_00764440;
  in_ECX[6] = 0;
  return;
}

