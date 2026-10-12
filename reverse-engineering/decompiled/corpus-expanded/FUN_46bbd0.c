/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46bbd0; label: FUN_0046bbd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046bbd0(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  fVar2 = *(float *)(param_1 + 0x100) / _DAT_007f903c;
  iVar1 = *(int *)(param_1 + 0xd8);
  if ((DAT_0087b014 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)) {
    local_c = *(float *)(param_1 + 200);
    local_8 = *(undefined4 *)(param_1 + 0xcc);
    local_4 = *(float *)(param_1 + 0xd0);
    fVar3 = _DAT_007f9044;
  }
  else {
    FUN_005b37d0(&local_c,iVar1 + 0x80,param_1 + 200);
    fVar3 = _DAT_007f9040;
  }
  *(float *)(param_1 + 0x30) = (1.0 - fVar2) * (*(float *)(iVar1 + 0x80) - local_c) + local_c;
  iVar4 = FUN_006e6b90();
  *(float *)(param_1 + 0x34) =
       (float)((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * (float10)fVar3 + extraout_ST0)
  ;
  *(float *)(param_1 + 0x38) =
       (float)((float10)local_4 +
              ((float10)*(float *)(iVar1 + 0x88) - (float10)local_4) * extraout_ST1);
  return;
}

