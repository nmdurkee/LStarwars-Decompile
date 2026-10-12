/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e36d0; label: FUN_004e36d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e36d0(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_c;
  
  if (DAT_00951b50 != 0) {
    return;
  }
  if (param_1 == DAT_008895c0) {
    iVar2 = 0;
    local_c = 0;
  }
  else {
    if (param_1 != DAT_008895c4) goto LAB_004e37f9;
    local_c = 1;
    iVar2 = 1;
  }
  (&DAT_0088956c)[iVar2 * 3] = param_1[0xc];
  (&DAT_00889570)[iVar2 * 3] = param_1[0xd];
  (&DAT_00889574)[iVar2 * 3] = param_1[0xe];
  puVar3 = (undefined4 *)FUN_005d0330(&DAT_0087aad8 + iVar2 * 3);
  fVar1 = (float)param_1[0x3f];
  puVar5 = param_1;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  if (1.0 < fVar1) {
    puVar3 = param_1 + 0x20;
    FUN_005b3800(puVar3,param_1 + 0xc,&DAT_0088956c + iVar2 * 3);
    FUN_005b3830(puVar3,puVar3,1.0 / _DAT_00925018);
  }
  else {
    param_1[0x20] = DAT_0093b0cc;
    param_1[0x21] = DAT_0093b0d0;
    param_1[0x22] = DAT_0093b0d4;
  }
  if ((*(float *)((&DAT_0087a810)[local_c] + 0x4c) <= 1.0) ||
     ((*(byte *)((&DAT_0087a810)[local_c] + 0x50) & 1) != 0)) {
    if ((*(byte *)(param_1 + 0x51) & 1) == 0) {
      return;
    }
    FUN_00681f40();
    return;
  }
LAB_004e37f9:
  FUN_0064ac90(param_1,0);
  return;
}

