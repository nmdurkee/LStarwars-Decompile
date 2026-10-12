/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a6860; label: FUN_006a6860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006a6860(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,float param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  undefined4 uStack_3c;
  undefined1 auStack_38 [4];
  int aiStack_34 [4];
  undefined1 auStack_24 [4];
  undefined4 uStack_20;
  
  piVar4 = param_1;
  iVar1 = param_1[10];
  iVar2 = *param_1;
  uStack_20 = 0x6a6880;
  iVar3 = iVar1 * -4;
  param_5 = *(float *)(param_1[1] + 4) + param_5;
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      *(undefined4 *)(&stack0xffffffe4 + iVar5 * 4 + iVar3) = 0xc61c3c00;
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1[10]);
  }
  if (param_5 < *(float *)(param_1[1] + 8)) {
    param_5 = *(float *)(param_1[1] + 8);
  }
  iVar5 = 0;
  if (3 < iVar2) {
    iVar7 = (iVar2 - 4U >> 2) + 1;
    param_1 = (int *)0x8;
    iVar5 = iVar7 * 4;
    pfVar6 = (float *)(param_3 + 8);
    do {
      pfVar6[-2] = *(float *)((int)pfVar6 + piVar4[4] + -param_3 + -8) + param_5;
      pfVar6[-1] = *(float *)((int)pfVar6 + piVar4[4] + -param_3 + -4) + param_5;
      iVar7 = iVar7 + -1;
      *pfVar6 = *(float *)((int)param_1 + piVar4[4]) + param_5;
      pfVar6[1] = *(float *)((int)pfVar6 + piVar4[4] + (4 - param_3)) + param_5;
      pfVar6 = pfVar6 + 4;
      param_1 = (int *)((int)param_1 + 0x10);
    } while (iVar7 != 0);
  }
  while (iVar5 < iVar2) {
    iVar7 = iVar5 * 4;
    iVar5 = iVar5 + 1;
    *(float *)(param_3 + -4 + iVar5 * 4) = *(float *)(piVar4[4] + iVar7) + param_5;
  }
  (&uStack_20)[-iVar1] = &stack0xffffffe4 + iVar3;
  (&uStack_20)[-iVar1] = param_4;
  *(undefined1 **)(auStack_24 + iVar3) = &stack0xffffffe4 + iVar3;
  iVar2 = piVar4[2];
  aiStack_34[3 - iVar1] = param_3;
  aiStack_34[2 - iVar1] = param_2;
  aiStack_34[1 - iVar1] = iVar2;
  aiStack_34[-iVar1] = 0x6a698b;
  FUN_006a5640();
  aiStack_34[-iVar1] = param_3;
  *(undefined1 **)(auStack_38 + iVar3) = &stack0xffffffe4 + iVar3;
  (&uStack_3c)[-iVar1] = 0x6a6995;
  FUN_006a58e0();
  return;
}

