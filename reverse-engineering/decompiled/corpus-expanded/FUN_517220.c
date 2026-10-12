/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x517220; label: FUN_00517220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00517220(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  float local_c;
  float local_8;
  float local_4;
  
  *(undefined4 *)(param_1 + 0x90) = 0x7f7fffff;
  *(undefined4 *)(param_1 + 0x94) = 0x7f7fffff;
  *(undefined4 *)(param_1 + 0x98) = 0x7f7fffff;
  pfVar1 = (float *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0x9c) = 0xff7fffff;
  pfVar2 = (float *)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0xa0) = 0xff7fffff;
  iVar7 = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0xff7fffff;
  if (*(char *)(param_1 + 0x10) != '\0') {
    pfVar6 = (float *)(*(int *)(param_1 + 0x7c) + 0x10);
    do {
      fVar3 = pfVar6[2];
      fVar4 = pfVar6[-1];
      fVar5 = *pfVar6;
      if (pfVar6[-3] - *pfVar6 < *pfVar1) {
        *pfVar1 = pfVar6[-3] - *pfVar6;
      }
      if (fVar3 < *(float *)(param_1 + 0x94)) {
        *(float *)(param_1 + 0x94) = fVar3;
      }
      if (fVar4 - fVar5 < *(float *)(param_1 + 0x98)) {
        *(float *)(param_1 + 0x98) = fVar4 - fVar5;
      }
      local_c = *pfVar6 + pfVar6[-3];
      local_8 = pfVar6[4];
      local_4 = *pfVar6 + pfVar6[-1];
      if (*pfVar2 < local_c) {
        *pfVar2 = local_c;
      }
      if (*(float *)(param_1 + 0xa0) < local_8) {
        *(float *)(param_1 + 0xa0) = local_8;
      }
      if (*(float *)(param_1 + 0xa4) < local_4) {
        *(float *)(param_1 + 0xa4) = local_4;
      }
      iVar7 = iVar7 + 1;
      pfVar6 = pfVar6 + 0x17;
    } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x10));
  }
  FUN_005b3800(&local_c,pfVar2,pfVar1);
  FUN_005b3830(&local_c,&local_c,0x3dcccccd);
  FUN_005b3800(pfVar1,pfVar1,&local_c);
  FUN_005b37d0(pfVar2,pfVar2,&local_c);
  return;
}

