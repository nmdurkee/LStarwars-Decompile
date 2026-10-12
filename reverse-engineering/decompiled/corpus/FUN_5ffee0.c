/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x5ffee0; label: FUN_005ffee0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ffee0(float *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar4;
  
  iVar1 = FUN_006e6b90();
  fVar4 = extraout_ST0;
  iVar2 = FUN_006e6b90();
  iVar3 = FUN_006e6b90();
  *param_1 = (float)(extraout_ST1_00 +
                    (float10)(float)(extraout_ST1 - (float10)(iVar1 + -0x10000)) * fVar4);
  param_1[1] = _DAT_009715a8 * (float)(extraout_ST0_00 - (float10)(iVar2 + -0x10000)) +
               _DAT_0096d9c8;
  param_1[2] = _DAT_009715ac * (float)(extraout_ST0_01 - (float10)(iVar3 + -0x10000)) +
               _DAT_0096d9cc;
  return;
}

