/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x649020; label: FUN_00649020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00649020(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  
  DAT_029209ec = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00649000,"Debris Type");
  if ((DAT_029209ec != 0) && (DAT_02920970 != 0)) {
    iVar3 = -1;
    if (DAT_02920968 == 0) {
      iVar3 = *(int *)(DAT_02920970 + 0x118);
    }
    else if (DAT_02920968 == 1) {
      iVar3 = *(int *)(DAT_02920970 + 0x11c);
    }
    else if (DAT_02920968 == 2) {
      iVar3 = *(int *)(DAT_02920970 + 0x128);
    }
    else if (DAT_02920968 == 3) {
      iVar3 = *(int *)(DAT_02920970 + 300);
    }
    else if (DAT_02920968 == 4) {
      iVar3 = *(int *)(DAT_02920970 + 0x144);
    }
    iVar5 = 1;
    bVar4 = false;
    if (1 < DAT_02962098) {
      do {
        if ((*(int *)(DAT_0296209c + iVar5 * 4) != 0) &&
           (iVar1 = *(int *)(DAT_0296209c + iVar5 * 4), *(char *)(iVar1 + 0x10) == DAT_0292098c)) {
          uVar2 = FUN_00627b80(iVar5,&DAT_008109d8,iVar3 == iVar5,1,FUN_00648f90,iVar1);
          FUN_00618e10(DAT_029209ec,uVar2);
          if (iVar3 == iVar5) {
            *(undefined4 *)(DAT_029209ec + 8) = DAT_02900c84;
            bVar4 = true;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_02962098);
    }
    FUN_00619060(DAT_029209ec);
    uVar2 = FUN_00627b80(0xffffffff,&DAT_008109d8,iVar3 == -1,1,FUN_00648f90,&DAT_00763b90);
    FUN_00618e50(DAT_029209ec,uVar2);
    FUN_006279b0(param_1,DAT_029209ec);
    *(int *)(DAT_029209ec + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209ec + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    if (bVar4) {
      *(undefined4 *)(DAT_029209ec + 0xc) = *(undefined4 *)(DAT_029209ec + 8);
    }
  }
  return;
}

