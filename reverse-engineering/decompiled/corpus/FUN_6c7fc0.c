/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c7fc0; label: FUN_006c7fc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006c7fc0(undefined4 param_1,undefined4 param_2,float param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  float10 fVar5;
  
  iVar3 = (int)param_3;
  uVar2 = param_1;
  fVar4 = (float10)FUN_006c0a10(param_1,param_2,(int)param_3 + 0x10,0);
  uVar1 = *(undefined4 *)(in_ECX + 8);
  fVar5 = (float10)FUN_006c0a10(param_1,param_2,(int)param_3 + 0x20,0);
  param_1 = uVar1;
  param_3 = (float)fVar4;
  if ((float)fVar5 < (float)fVar4) {
    param_1 = *(undefined4 *)(in_ECX + 0xc);
    param_3 = (float)fVar5;
  }
  fVar4 = (float10)FUN_006c0a10(uVar2,param_2,iVar3 + 0x30,0);
  if ((float)fVar4 < param_3) {
    param_1 = *(undefined4 *)(in_ECX + 0x10);
    param_3 = (float)fVar4;
  }
  fVar4 = (float10)(param_3 - _DAT_0081f9b4 * _DAT_0081fa04);
  if (fVar4 < (float10)0) {
    fVar4 = (float10)(float)(float10)0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = param_1;
  }
  return fVar4;
}

