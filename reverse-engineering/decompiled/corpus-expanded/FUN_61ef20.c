/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ef20; label: FUN_0061ef20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0061ef20(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_02912b40 = param_5;
  iVar1 = (**(code **)(param_1 + 0x40))(param_2,param_1,param_3,param_4,param_5,param_6);
  if (param_6 != 0) {
    uVar2 = DAT_0080f548;
    if ((*(byte *)(param_1 + 0x11) & 4) == 0) {
      uVar2 = DAT_0080f544;
    }
    if (DAT_02912eb8 == 0) {
      FUN_005dbbf0(param_3 << 4,param_4 * 8 + 8,DAT_02912b40 << 4,iVar1 * 8 + -0x10,uVar2,
                   (&DAT_02900c70)[DAT_02912e94]);
    }
  }
  FUN_00619570(param_1,param_3,param_5);
  return iVar1;
}

