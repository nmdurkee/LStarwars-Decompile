/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cc320; label: FUN_006cc320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cc320(int param_1)

{
  int iVar1;
  undefined1 local_20 [28];
  
  if (2 < *(int *)(param_1 + 8)) {
    FUN_006cbc00(param_1);
  }
  iVar1 = FUN_006ca2f0(local_20);
  if (iVar1 != 0) {
    FUN_006bd3b0(local_20);
  }
  return;
}

