/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x646670; label: FUN_00646670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646670(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if (DAT_02920970 != 0) {
    DAT_02920a18 = FUN_00619250(0x46,0x46,0xfa,200,DAT_02912e80,&LAB_00646650,"Sound ID");
    if (DAT_02920a18 != 0) {
      uVar1 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 9999,&DAT_008109d8,
                           *(int *)(DAT_02920970 + 0x148 + *(int *)(param_2 + 0xc) * 4) == -1,0,
                           FUN_006464f0,&DAT_007600a0);
      FUN_00618e10(DAT_02920a18,uVar1);
      iVar3 = 0;
      iVar2 = 0;
      do {
        if (*(int *)(DAT_02947b74 + iVar2) != 0) {
          bVar4 = *(int *)(DAT_02920970 + 0x148 + *(int *)(param_2 + 0xc) * 4) == iVar3;
          uVar1 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + iVar3,&DAT_008109d8,bVar4,1,
                               FUN_006464f0,*(int *)(DAT_02947b74 + iVar2));
          FUN_00618e10(DAT_02920a18,uVar1);
          if (bVar4) {
            *(undefined4 *)(DAT_02920a18 + 8) = DAT_02900c84;
          }
        }
        iVar2 = iVar2 + 0x40;
        iVar3 = iVar3 + 1;
      } while (iVar2 < 0x19000);
      FUN_006279b0(param_1,DAT_02920a18);
      *(int *)(DAT_02920a18 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920a18 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

