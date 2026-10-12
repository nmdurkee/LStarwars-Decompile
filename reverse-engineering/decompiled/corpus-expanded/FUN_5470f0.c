/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x5470f0; label: FUN_005470f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005470f0(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  piVar1 = (int *)(*param_3 + -1 + param_5 & ~(param_5 - 1U));
  uVar4 = param_2 + 0xf + param_5 & -param_5;
  uVar2 = uVar4 * param_1 + 0x20;
  *param_3 = (int)piVar1;
  if ((uint)(param_4 - (int)piVar1) <= uVar2) {
    return (int *)0x0;
  }
  *param_3 = uVar2 + (int)piVar1;
  piVar3 = piVar1 + 8;
  iVar5 = 1;
  *(short *)((int)piVar1 + 0x12) = (short)param_2;
  *piVar1 = (int)piVar3;
  piVar1[2] = 0;
  piVar1[3] = 0;
  *(short *)(piVar1 + 4) = (short)param_1;
  *(short *)(piVar1 + 5) = (short)uVar4;
  *(undefined2 *)((int)piVar1 + 0x16) = 0;
  piVar6 = piVar3;
  if (1 < param_1) {
    do {
      piVar6 = (int *)((int)piVar3 + uVar4);
      piVar3[1] = (int)piVar6;
      *(short *)(piVar3 + 3) = (short)iVar5 + -1;
      *piVar3 = (int)piVar1;
      iVar5 = iVar5 + 1;
      piVar3 = piVar6;
    } while (iVar5 < param_1);
  }
  piVar6[1] = 0;
  piVar1[1] = (int)piVar6;
  *(short *)(piVar6 + 3) = (short)iVar5 + -1;
  *piVar6 = (int)piVar1;
  piVar1[6] = DAT_0297ad54;
  return piVar1;
}

