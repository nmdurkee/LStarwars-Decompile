/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x6904d0; label: FUN_006904d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006904d0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_00690180(param_1,param_2,param_3,0,0,param_4);
  if (*param_1 != -1) {
    *(undefined4 *)(*param_1 * 0x330 + 0x32c + DAT_029620a4) = param_5;
  }
  return;
}

