/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504dc0; label: FUN_00504dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00504dc0(undefined4 param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = *param_2 + 0xf & 0xfffffff0;
  *param_2 = uVar1;
  iVar2 = FUN_004fd5d0(param_1,uVar1,*param_3 - uVar1);
  iVar6 = 0;
  if (iVar2 != 0) {
    piVar3 = (int *)*param_2;
    *param_2 = iVar2 + (int)piVar3;
    if (*piVar3 != 1) {
      piVar3 = (int *)FUN_004fff00(param_1,*piVar3);
    }
    iVar2 = piVar3[1];
    piVar3[1] = (int)piVar3 - iVar2;
    if (piVar3[3] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = ((int)piVar3 - iVar2) + piVar3[3];
    }
    piVar3[3] = iVar2;
    if ((iVar2 != 0) && (param_2 = (uint *)0x0, 0 < piVar3[2])) {
      do {
        iVar2 = *(int *)(piVar3[3] + iVar6);
        piVar4 = (int *)(piVar3[3] + iVar6);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = piVar3[1] + iVar2;
        }
        *piVar4 = iVar2;
        if (piVar4[0xc] == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = piVar3[1] + piVar4[0xc];
        }
        piVar4[0xc] = iVar2;
        if ((iVar2 != 0) && (iVar2 = 0, 0 < (short)piVar4[0xb])) {
          do {
            iVar5 = *(int *)(piVar4[0xc] + 4 + iVar2 * 8);
            if (iVar5 == 0) {
              iVar5 = 0;
            }
            else {
              iVar5 = piVar3[1] + iVar5;
            }
            *(int *)(piVar4[0xc] + iVar2 * 8 + 4) = iVar5;
            iVar2 = iVar2 + 1;
          } while (iVar2 < (short)piVar4[0xb]);
        }
        param_2 = (uint *)((int)param_2 + 1);
        iVar6 = iVar6 + 0x34;
      } while ((int)param_2 < piVar3[2]);
    }
    return piVar3;
  }
  return (int *)0x0;
}

