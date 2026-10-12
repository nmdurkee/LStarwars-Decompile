/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4ed0; label: FUN_005c4ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4ed0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_006056f0(param_1,param_2,1,1,2);
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  return;
}

