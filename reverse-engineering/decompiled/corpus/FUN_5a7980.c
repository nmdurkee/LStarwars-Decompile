/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a7980; label: FUN_005a7980
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a7980(undefined4 param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  FUN_005a4eb0(param_1,param_2,param_3,param_2 + 7);
  fVar3 = _DAT_00805a74;
  fVar1 = param_2[7];
  if (fVar1 != 0.0) {
    param_2[1] = *(float *)(*(int *)((int)fVar1 + 0x58) + 4) + *(float *)((int)fVar1 + 0xc0) +
                 _DAT_00805a74;
  }
  fVar1 = param_2[0x16];
  fVar2 = (param_2[0x2d] + *(float *)((int)fVar1 + 4)) - param_2[1];
  *param_2 = fVar2;
  if (fVar3 + 0.0 < fVar2) {
    *(float *)((int)fVar1 + 4) = *(float *)((int)fVar1 + 4) - fVar2;
    *param_2 = 0.0;
    return;
  }
  return;
}

