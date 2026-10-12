/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ea50; label: FUN_0061ea50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061ea50(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  
  FUN_005d0e80(DAT_02912b38);
  FUN_005d0eb0(DAT_02912b38);
  bVar2 = DAT_02912eb8 == 0;
  *(int *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  if (bVar2) {
    FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,0x40,
                 *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                 (&DAT_02900c70)[DAT_02912e90]);
    if (DAT_02912eb8 == 0) {
      iVar1 = param_4 * 8 + 0x20;
      FUN_005db5b0((param_3 + 4) * 0x10,iVar1,(param_3 + -4 + param_5) * 0x10,iVar1,0xff000000,
                   (&DAT_02900c70)[DAT_02912e90]);
    }
    return 8;
  }
  return 8;
}

