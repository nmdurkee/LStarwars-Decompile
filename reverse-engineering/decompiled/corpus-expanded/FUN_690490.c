/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x690490; label: FUN_00690490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00690490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_00684790(param_2,param_7);
  if (iVar1 != -1) {
    FUN_00690180(param_1,iVar1,param_3,param_4,param_5,param_6);
  }
  return;
}

