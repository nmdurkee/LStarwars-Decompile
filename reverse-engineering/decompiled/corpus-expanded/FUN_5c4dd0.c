/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4dd0; label: FUN_005c4dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4dd0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_005f8a80(*(undefined4 *)(in_ECX + 8),0,0,0);
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_005fb7d0(uVar1,*(int *)(in_ECX + 0x10),param_1);
    return;
  }
  FUN_0060c260(uVar1,param_1);
  return;
}

