/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x479ed0; label: FUN_00479ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479ed0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined2 in_FPUControlWord;
  float10 fVar5;
  float local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined1 local_c4 [52];
  float local_90;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_d8;
  FUN_00425fa0(DAT_00856980);
  FUN_004c6c20();
  FUN_00478450(param_1);
  if (DAT_00921e9c != 0) {
    FUN_005b7d30(_DAT_0092505c,0x40a00000);
    iVar1 = FUN_006e6b90();
    iVar2 = (DAT_007fa218 * 0x10000) / 0x168;
    local_d4 = (float)CONCAT22((short)((uint)iVar2 >> 0x10),in_FPUControlWord);
    local_d8 = (float)(int)ROUND((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * 2730.0 + (float)iVar2
                                );
    FUN_005b7d30(_DAT_0092505c,0x404d70a4);
    iVar2 = FUN_006e6b90();
    local_d4 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * _DAT_007fa21c;
    iVar2 = FUN_006e6b90();
    local_d8 = (float)((uint)DAT_0086e4e0 * 100);
    _sprintf(local_84,"%.1f%%",(double)(int)local_d8 / (double)DAT_0093b2b8);
    uVar3 = FUN_00474940();
    FUN_005b4900(uVar3,&DAT_007f9300);
    local_90 = local_90 + local_d4;
    FUN_005d0880(4);
    FUN_005d0fb0(DAT_00921e9c);
    FUN_005d1030(DAT_00921e9c,local_c4);
    FUN_005d0940(4);
    FUN_005d1060(DAT_00921e9c,
                 (((uint)DAT_007fa224 | iVar2 << 8) << 8 | (uint)DAT_007fa220) << 8 |
                 (uint)DAT_00879b7c);
    FUN_005d0fe0(DAT_00921e9c,0x3b75c28f,0x3ba3d70a);
    fVar5 = (float10)FUN_005d0d60(DAT_00921e9c,local_84,0,0);
    local_d8 = (float)(-fVar5 * (float10)0.5);
    FUN_005eabb0(DAT_00921e9c,local_d8);
    FUN_005f3510(DAT_00921e9c,local_84);
    FUN_005d08c0();
    FUN_0054bbc0(_DAT_0086e4e8,1,1,1,local_84);
    uVar3 = FUN_00474940();
    FUN_005b4900(uVar3,&DAT_007f9300);
    local_d8 = local_90 + local_d4;
    local_90 = local_d8 + 0.16;
    FUN_005d0880(4);
    FUN_005d0fb0(DAT_00921e9c);
    FUN_005d1030(DAT_00921e9c,local_c4);
    FUN_005d0940(4);
    FUN_005d1060(DAT_00921e9c,
                 (((uint)DAT_007fa224 | iVar2 << 8) << 8 | (uint)DAT_007fa220) << 8 |
                 (uint)DAT_00879b7c);
    FUN_005d0fe0(DAT_00921e9c,0x3b3851eb,0x3b75c28f);
    fVar5 = (float10)FUN_005d0d60(DAT_00921e9c,local_84,0,0);
    local_d8 = (float)(-fVar5 * (float10)0.5);
    FUN_005eabb0(DAT_00921e9c,local_d8);
    FUN_005f3510(DAT_00921e9c,local_84);
    FUN_005d08c0();
    iVar2 = FUN_005cfac0(&DAT_0087ab8c);
    if (iVar2 != 0) {
      puVar4 = (undefined4 *)FUN_005cf9e0();
      local_d0 = *puVar4;
      local_cc = puVar4[1];
      local_c8 = puVar4[2];
      uVar3 = FUN_00474940();
      FUN_005b4900(uVar3,&local_d0);
      local_d8 = _DAT_00879b24 * 0.2 + 0.8;
      FUN_005ff7a0(&DAT_0087ab8c,local_c4,local_d8);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_d8);
  return;
}

