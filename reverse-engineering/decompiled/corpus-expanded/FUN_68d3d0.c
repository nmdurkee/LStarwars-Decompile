/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68d3d0; label: FUN_0068d3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068d3d0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  DAT_0292fc74 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00664920,"Quick Delete");
  if (DAT_0292fc74 != 0) {
    iVar4 = 1;
    if (1 < DAT_02962098) {
      do {
        if ((*(int *)(DAT_0296209c + iVar4 * 4) != 0) &&
           (iVar1 = *(int *)(DAT_0296209c + iVar4 * 4), *(char *)(iVar1 + 0x10) == DAT_0292118b)) {
          piVar2 = &DAT_02924b60;
          do {
            if (((*piVar2 != -1) && (*piVar2 != 99999)) && (piVar2[-1] == iVar4)) {
              uVar3 = FUN_00627a80(iVar4,&DAT_008109d8,0,1,FUN_0068cf30,iVar1);
              goto LAB_0068d46a;
            }
            piVar2 = piVar2 + 0x16;
          } while ((int)piVar2 < 0x292fb60);
          uVar3 = FUN_00627a80(iVar4,&DAT_008109f8,0,1,FUN_0068cf30,iVar1);
LAB_0068d46a:
          FUN_00618e10(DAT_0292fc74,uVar3);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_02962098);
    }
    FUN_006279b0(param_1,DAT_0292fc74);
    *(int *)(DAT_0292fc74 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0292fc74 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

