/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d0a0; label: FUN_0065d0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065d0a0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined1 local_c [12];
  
  DAT_02962960 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065d080,"Plank Select");
  if ((DAT_02962960 != 0) && (DAT_02962114 != 0)) {
    uVar1 = FUN_00627b80(0xffffffff,&DAT_008109d8,DAT_02920d80 == -1,1,&LAB_0065d070,&DAT_00763b90);
    FUN_00618e10(DAT_02962960,uVar1);
    iVar2 = FUN_005cfed0(DAT_02962114);
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        bVar4 = DAT_02920d80 == iVar3;
        FUN_005da860(local_c,DAT_02962114,iVar3);
        uVar1 = FUN_005cfa50(local_c);
        uVar1 = FUN_00627b80(iVar3,&DAT_008109d8,bVar4,1,&LAB_0065d070,uVar1);
        FUN_00618e10(DAT_02962960,uVar1);
        if (bVar4) {
          *(undefined4 *)(DAT_02962960 + 8) = DAT_02900c84;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    FUN_006279b0(param_1,DAT_02962960);
    *(int *)(DAT_02962960 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962960 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

