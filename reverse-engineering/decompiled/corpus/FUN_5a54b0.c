/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a54b0; label: FUN_005a54b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a54b0(undefined4 param_1,float *param_2,undefined4 param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = *param_4;
  local_14 = 0.0;
  local_10 = param_4[2];
  *(float *)param_2[0x16] = *(float *)param_2[0x16] + local_18;
  *(float *)((int)param_2[0x16] + 8) = *(float *)((int)param_2[0x16] + 8) + local_10;
  pfVar1 = param_2 + 9;
  FUN_005ea660(pfVar1);
  iVar6 = 0;
  if (*(char *)((int)param_2 + 0xd1) != '\0') {
    pfVar7 = param_2 + 0x17;
    do {
      iVar5 = FUN_005d0370(pfVar7);
      puVar4 = (undefined4 *)param_2[0x16];
      local_c = *puVar4;
      local_8 = puVar4[1];
      local_4 = puVar4[2];
      *(undefined4 *)(iVar5 + 0x30) = local_c;
      *(undefined4 *)(iVar5 + 0x38) = local_4;
      FUN_005ea660(pfVar7);
      iVar6 = iVar6 + 1;
      pfVar7 = pfVar7 + 3;
    } while (iVar6 < (int)(uint)*(byte *)((int)param_2 + 0xd1));
  }
  iVar6 = FUN_005a4eb0(param_1,param_2,param_3,param_2 + 7);
  if (iVar6 == 0) {
    FUN_005a51f0(param_1,param_2,param_3,&local_18);
    if ((param_2[0xc] != 0.0) &&
       (((0.001 < ABS(local_18) || (0.001 < ABS(local_10))) &&
        (fVar8 = (float10)FUN_005b7d30(_DAT_0092505c,_DAT_00805b08), fVar8 < (float10)_DAT_00805b04)
        ))) {
      iVar6 = FUN_0054fa60(0);
      FUN_0054a850(**(undefined4 **)((int)param_2[0xc] + 0xca4),(float)iVar6 * 1.5259022e-05 * 0.05)
      ;
    }
  }
  else {
    param_2[0x32] = (float)((uint)param_2[0x32] | 0x400);
  }
  if (((uint)param_2[0x32] & 8) != 0) {
    local_18 = 0.0;
    local_14 = param_4[1];
    local_10 = 0.0;
    *(float *)((int)param_2[0x16] + 4) = *(float *)((int)param_2[0x16] + 4) - local_14;
    *param_2 = *param_2 - local_14;
    iVar6 = FUN_005a4eb0(param_1,param_2,param_3,param_2 + 7);
    if (iVar6 != 0) {
      fVar2 = *(float *)(*(int *)(iVar6 + 0x58) + 4);
      fVar3 = *(float *)(iVar6 + 0xc0);
      param_2[0x32] = (float)((uint)param_2[0x32] | 0x800);
      param_2[3] = fVar2 + fVar3;
      FUN_005ea660(pfVar1);
      return;
    }
    FUN_005a51f0(param_1,param_2,param_3,&local_18);
    FUN_005ea660(pfVar1);
  }
  return;
}

