/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x631c30; label: FUN_00631c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00631c30(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00827610 == 0) {
    _BinkSetVolume_12(*param_1,0,0);
    DAT_02913200 = 1;
    return;
  }
  if (DAT_02913200 != 0) {
    uVar1 = FUN_006e6b90();
    _BinkSetVolume_12(*param_1,0,uVar1);
    DAT_02913200 = 0;
  }
  iVar2 = _BinkWait_4(*param_1);
  if (iVar2 == 0) {
    FUN_006317b0(param_1,param_1[2],3);
    FUN_00631440(param_1);
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0xc) == *(int *)(iVar2 + 8)) {
      param_1[4] = 0;
      return;
    }
    _BinkNextFrame_4(iVar2);
    return;
  }
  FUN_00631360();
  return;
}

