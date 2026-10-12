/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a8e30; label: FUN_006a8e30
 */

float10 FUN_006a8e30(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  int unaff_ESI;
  int iVar5;
  float local_14;
  float *local_c;
  float *local_8;
  float *local_4;
  
  local_14 = 0.0;
  iVar5 = 0;
  if (3 < param_1) {
    iVar3 = (param_1 - 4U >> 2) + 1;
    iVar5 = iVar3 * 4;
    pfVar2 = (float *)(param_2 + 8);
    pfVar4 = param_3;
    local_c = param_3 + unaff_ESI;
    local_8 = param_3 + unaff_ESI * 2;
    local_4 = param_3 + unaff_ESI * 3;
    do {
      fVar1 = *pfVar4;
      pfVar4 = pfVar4 + unaff_ESI * 4;
      iVar3 = iVar3 + -1;
      local_14 = (pfVar2[1] - *local_4) * (pfVar2[1] - *local_4) +
                 (*pfVar2 - *local_8) * (*pfVar2 - *local_8) +
                 (pfVar2[-1] - *local_c) * (pfVar2[-1] - *local_c) +
                 (pfVar2[-2] - fVar1) * (pfVar2[-2] - fVar1) + local_14;
      pfVar2 = pfVar2 + 4;
      local_c = local_c + unaff_ESI * 4;
      local_8 = local_8 + unaff_ESI * 4;
      local_4 = local_4 + unaff_ESI * 4;
    } while (iVar3 != 0);
  }
  if (iVar5 < param_1) {
    param_3 = param_3 + iVar5 * unaff_ESI;
    do {
      iVar3 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      fVar1 = *(float *)(param_2 + iVar3) - *param_3;
      param_3 = param_3 + unaff_ESI;
      local_14 = fVar1 * fVar1 + local_14;
    } while (iVar5 < param_1);
  }
  return (float10)local_14;
}

