/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x651470; label: FUN_00651470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00651470(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00650dc0(param_1);
  if (iVar1 != -1) {
    FUN_00650f20(iVar1,param_2,param_3,0x3f800000);
  }
  return;
}

