/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x5243b0; label: FUN_005243b0
 */

void FUN_005243b0(undefined4 param_1,int param_2,int param_3,float *param_4,int *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  float *unaff_EDI;
  float10 fVar6;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [2];
  undefined4 local_1c;
  float local_18 [3];
  undefined1 local_c [12];
  
  puVar5 = (undefined4 *)(param_2 + 0x18);
  FUN_005b3800(local_24,(undefined4 *)(param_3 + 0x18),puVar5);
  fVar6 = (float10)FUN_005bec80(local_24);
  fVar1 = (float)fVar6;
  FUN_005b3830(local_24,local_24,1.0 / fVar1);
  FUN_005b3800(local_18,param_1,puVar5);
  fVar6 = (float10)FUN_005b39e0(local_24,local_18);
  fVar2 = (float)fVar6 / fVar1;
  *unaff_EDI = fVar2;
  if (0.0 < fVar2) {
    if (NAN(fVar2) || 1.0 < fVar2 == (fVar2 == 1.0)) {
      FUN_005b3830(&local_30,local_24,(float)fVar6);
      FUN_005b37d0(&local_30,&local_30,puVar5);
      fVar2 = *(float *)(param_3 + 0x24) * *unaff_EDI +
              (1.0 - *unaff_EDI) * *(float *)(param_2 + 0x24);
    }
    else {
      local_30 = *(undefined4 *)(param_3 + 0x18);
      local_2c = *(undefined4 *)(param_3 + 0x1c);
      fVar2 = *(float *)(param_3 + 0x24);
      local_28 = *(undefined4 *)(param_3 + 0x20);
    }
  }
  else {
    local_30 = *puVar5;
    local_2c = *(undefined4 *)(param_2 + 0x1c);
    local_28 = *(undefined4 *)(param_2 + 0x20);
    fVar2 = *(float *)(param_2 + 0x24);
  }
  fVar6 = (float10)FUN_005b3cf0(&local_30,param_1,local_c);
  FUN_005bfe00(local_24[0],local_1c);
  iVar4 = FUN_006e6b90();
  *param_5 = iVar4;
  FUN_005b3620(local_18,local_18,-iVar4);
  if (0.0 < *unaff_EDI) {
    fVar3 = *unaff_EDI;
    if (NAN(fVar3) || 1.0 < fVar3 == (fVar3 == 1.0)) {
      fVar6 = (float10)FUN_005c0240((float)fVar6);
      *param_4 = (float)(fVar6 / (float10)(fVar2 + param_6));
      goto LAB_00524597;
    }
    fVar3 = *unaff_EDI - 1.0;
  }
  else {
    fVar3 = -*unaff_EDI;
  }
  fVar1 = (float)fVar6 - fVar3 * fVar1 * fVar3 * fVar1;
  *param_4 = fVar1;
  fVar6 = (float10)FUN_005c0240(fVar1);
  *param_4 = (float)(fVar6 / (float10)(fVar2 + param_6));
LAB_00524597:
  if (local_18[0] < 0.0) {
    *param_4 = -*param_4;
  }
  return;
}

