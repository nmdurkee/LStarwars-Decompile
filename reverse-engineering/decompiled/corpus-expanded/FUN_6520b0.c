/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x6520b0; label: FUN_006520b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006520b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004fc860(param_1);
  if (iVar1 != 0) {
    FUN_004f10e0(iVar1,&PTR_s_Audio_00810470);
    iVar2 = FUN_004fc5b0(iVar1);
    while (iVar2 != 0) {
      FUN_004f7fb0(iVar1);
      if (**(char **)(iVar1 + 0x510) != '\0') {
        FUN_004fa020(iVar1);
      }
      iVar2 = FUN_004fc5b0(iVar1);
    }
    FUN_004fa300(iVar1);
  }
  iVar1 = DAT_02962014 * 0x1c;
  *(undefined4 *)(iVar1 + DAT_02947d70) = 0;
  *(undefined4 *)(iVar1 + 4 + DAT_02947d70) = 0;
  *(undefined4 *)(iVar1 + 8 + DAT_02947d70) = 0;
  *(undefined4 *)(iVar1 + 0xc + DAT_02947d70) = 0xffffffff;
  FUN_00697a50(DAT_02947d70,param_2,param_3);
  _memset(&DAT_02921760,0,200);
  if (DAT_02962034 == 0) {
    FUN_00698710(&DAT_02921760,100);
  }
  FUN_00698e70();
  return;
}

