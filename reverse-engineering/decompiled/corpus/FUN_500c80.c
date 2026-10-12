/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500c80; label: FUN_00500c80
 */

void FUN_00500c80(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + param_2);
    *(int **)(param_1 + 0x1c) = piVar1;
    if (*piVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *piVar1 + param_2;
    }
    *piVar1 = iVar4;
    if (((iVar4 != 0) && (param_3 != 0)) && (iVar4 = 0, (char)piVar1[2] != '\0')) {
      iVar6 = 0;
      do {
        iVar2 = *piVar1;
        iVar3 = *(int *)(iVar2 + 0x50 + iVar6);
        if (iVar3 != 0) {
          uVar5 = FUN_005e91f0(iVar3,param_3,param_4,0);
          *(undefined4 *)(iVar2 + iVar6 + 0x50) = uVar5;
        }
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 100;
      } while (iVar4 < (int)(uint)*(byte *)(piVar1 + 2));
    }
    if (piVar1[1] == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = piVar1[1] + param_2;
    }
    piVar1[1] = iVar4;
    if ((iVar4 != 0) && (iVar4 = 0, *(char *)((int)piVar1 + 9) != '\0')) {
      iVar6 = 0;
      do {
        iVar2 = *(int *)(piVar1[1] + iVar6);
        if (iVar2 != 0) {
          iVar3 = param_2;
          if (param_4 == 0) {
            iVar3 = *(int *)(param_1 + 0xc) + -1;
          }
          *(int *)(piVar1[1] + iVar6) = iVar3 + iVar2;
        }
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 0xc;
      } while (iVar4 < (int)(uint)*(byte *)((int)piVar1 + 9));
    }
  }
  return;
}

