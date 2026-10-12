/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501ea0; label: FUN_00501ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00501ea0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x14) + param_2);
    *(int **)(param_1 + 0x14) = piVar1;
    if (*piVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *piVar1 + param_2;
    }
    *piVar1 = iVar4;
    if ((iVar4 != 0) && (iVar4 = 0, (short)piVar1[1] != 0)) {
      iVar6 = 0;
      do {
        iVar2 = *(int *)(*piVar1 + 0x40 + iVar6);
        iVar7 = *piVar1 + iVar6;
        if (iVar2 != 0) {
          iVar3 = param_2;
          if (param_4 == 0) {
            iVar3 = *(int *)(param_1 + 0xc) + -1;
          }
          *(int *)(iVar7 + 0x40) = iVar3 + iVar2;
        }
        if (param_3 != 0) {
          if (*(int *)(iVar7 + 0x4c) != 0) {
            uVar5 = FUN_005e91f0(*(int *)(iVar7 + 0x4c),param_3,param_4,0);
            *(undefined4 *)(iVar7 + 0x4c) = uVar5;
          }
          uVar5 = FUN_005da600(*(undefined4 *)(iVar7 + 0x50),param_3);
          *(undefined4 *)(iVar7 + 0x50) = uVar5;
        }
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 0x5c;
      } while (iVar4 < (int)(uint)*(ushort *)(piVar1 + 1));
    }
  }
  return;
}

