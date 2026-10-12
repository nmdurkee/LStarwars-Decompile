/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627b40; label: FUN_00627b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00627b40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = FUN_00627a80(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    *(code **)(iVar1 + 0x40) = FUN_00619800;
  }
  return;
}

