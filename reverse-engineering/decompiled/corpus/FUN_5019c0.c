/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x5019c0; label: FUN_005019c0
 */

void FUN_005019c0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  float *pfVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  pfVar2 = (float *)(param_2 * 0x60 + *(int *)(param_1 + 0x16c));
  puVar3 = &DAT_00806680;
  puVar4 = param_3;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  while( true ) {
    if (((*pfVar2 != 1.0) || (pfVar2[5] != 1.0)) || (pfVar2[10] != 1.0)) {
      FUN_005c0500(param_3,pfVar2,param_3);
    }
    if (*(byte *)(pfVar2 + 0x14) == 0xff) break;
    pfVar2 = (float *)((uint)*(byte *)(pfVar2 + 0x14) * 0x60 + *(int *)(param_1 + 0x16c));
  }
  param_3[2] = -(float)param_3[2];
  param_3[6] = -(float)param_3[6];
  param_3[8] = -(float)param_3[8];
  param_3[9] = -(float)param_3[9];
  param_3[0xb] = -(float)param_3[0xb];
  param_3[0xe] = -(float)param_3[0xe];
  FUN_005b5930(param_3,param_3);
  return;
}

