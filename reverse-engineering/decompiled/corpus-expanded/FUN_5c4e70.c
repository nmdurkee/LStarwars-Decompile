/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4e70; label: FUN_005c4e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4e70(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  FUN_00605b60(uVar1,0,*(undefined4 *)(in_ECX + 0x14),0);
  return;
}

