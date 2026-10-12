/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a01f0; label: FUN_005a01f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a01f0(float param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  
  iVar2 = (int)param_1;
  uVar3 = FUN_0054fa60();
  iVar4 = FUN_0054fa60();
  fVar1 = (float)iVar4 * 1.5259022e-05 * 0.09 + 0.01;
  *(float *)((int)param_1 + 0x68) = fVar1 * (float)(&DAT_029899a0)[(uVar3 & 0xffff) >> 1];
  *(float *)((int)param_1 + 0x70) =
       fVar1 * (float)(&DAT_029899a0)[(int)((uVar3 & 0xffff) + 0x4000) >> 1 & 0x7fff];
  FUN_00561ba0(param_1,0);
  *(byte *)((int)param_1 + 0x7c5) = *(byte *)((int)param_1 + 0x7c5) | 1;
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  *(undefined4 *)((int)param_1 + 0x70) = 0;
  *(int *)((int)param_1 + 0xd1c) = param_2;
  *(undefined4 *)(*(int *)((int)param_1 + 0xca4) + 4) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0xca4) + 8) = 0;
  param_1 = *(float *)(param_2 + 0x194);
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x94) & 0x20000) != 0) {
    param_1 = _DAT_00805714 + param_1;
  }
  iVar4 = *(int *)(*(int *)(iVar2 + 0x54) + 0x24);
  fVar1 = (param_1 - *(float *)(iVar2 + 0x1a0)) + 0.1;
  if (*(float *)(iVar4 + 0x34) < fVar1) {
    fVar5 = (float10)FUN_005c0240(*(float *)(iVar4 + 0x24) * -2.0 * fVar1);
    *(float *)(iVar2 + 0x6c) = (float)fVar5;
    return;
  }
  return;
}

