/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65cf40; label: FUN_0065cf40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065cf40(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined1 local_c [12];
  
  DAT_02962964 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065cf20,"Post Select");
  if ((DAT_02962964 != 0) && (DAT_02962114 != 0)) {
    uVar1 = FUN_00627b80(0xffffffff,&DAT_008109d8,DAT_0292fdb4 == -1,1,FUN_0065cf10,&DAT_00763b90);
    FUN_00618e10(DAT_02962964,uVar1);
    iVar2 = FUN_005cfed0(DAT_02962114);
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        bVar4 = DAT_0292fdb4 == iVar3;
        FUN_005da860(local_c,DAT_02962114,iVar3);
        uVar1 = FUN_005cfa50(local_c);
        uVar1 = FUN_00627b80(iVar3,&DAT_008109d8,bVar4,1,FUN_0065cf10,uVar1);
        FUN_00618e10(DAT_02962964,uVar1);
        if (bVar4) {
          *(undefined4 *)(DAT_02962964 + 8) = DAT_02900c84;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    FUN_006279b0(param_1,DAT_02962964);
    *(int *)(DAT_02962964 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962964 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

