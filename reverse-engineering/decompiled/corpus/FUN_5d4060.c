/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d4060; label: FUN_005d4060
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005d4060(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,int param_8,int param_9)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  byte local_107d;
  undefined1 local_1070 [8];
  int local_1068;
  undefined1 local_1058 [8];
  int local_1050;
  undefined4 local_1040 [16];
  int local_1000 [256];
  undefined1 local_c00 [3060];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_009738e4 < *(int *)(param_1 + 0x168)) {
    DAT_009738e4 = *(int *)(param_1 + 0x168);
  }
  local_c = 0x3f800000;
  local_8 = 0x3f800000;
  local_4 = 0x3f800000;
  FUN_005c9b60(param_2,param_3,local_1058);
  iVar2 = *(int *)(*(int *)(param_2 + 0xc) + local_1050 * 4);
  FUN_005c9b60(param_4,param_5,local_1070);
  iVar3 = *(int *)(*(int *)(param_4 + 0xc) + local_1068 * 4);
  if (param_7 != 0) {
    _memset(local_1000,0,*(int *)(param_1 + 0x168) * 4);
    bVar9 = 0;
    if (0 < param_7) {
      iVar8 = *(int *)(param_1 + 0x178);
      uVar5 = 0;
      do {
        iVar7 = param_8 + uVar5 * 0x34;
        uVar5 = (uint)*(byte *)(iVar7 + 0x30);
        if (((int)uVar5 < iVar8) &&
           (bVar1 = *(byte *)(uVar5 + *(int *)(param_1 + 0x17c)), bVar1 != 0xff)) {
          local_1000[bVar1] = iVar7;
        }
        bVar9 = bVar9 + 1;
        uVar5 = (uint)bVar9;
      } while ((int)uVar5 < param_7);
    }
  }
  local_107d = 0;
  if (0 < *(int *)(param_1 + 0x168)) {
    uVar5 = 0;
    do {
      puVar11 = (undefined4 *)(uVar5 * 0x40 + param_9);
      if (param_7 == 0) {
        iVar8 = 0;
      }
      else {
        iVar8 = local_1000[uVar5];
      }
      iVar7 = *(int *)(iVar2 + 8);
      if ((*(int *)(iVar7 + uVar5 * 4) == 0) ||
         (iVar4 = *(int *)(iVar3 + 8), *(int *)(iVar4 + uVar5 * 4) == 0)) {
        puVar10 = (undefined4 *)(*(int *)(param_1 + 0x170) + uVar5 * 0x40);
      }
      else {
        iVar6 = uVar5 * 0x60 + *(int *)(param_1 + 0x16c);
        FUN_005ce820(*(undefined4 *)(iVar7 + uVar5 * 4),local_1058,
                     *(undefined4 *)(iVar4 + uVar5 * 4),local_1070,param_6,iVar6,
                     local_c00 + uVar5 * 0xc,local_c00 + (uint)*(byte *)(iVar6 + 0x50) * 0xc,
                     local_1040,iVar8);
        puVar10 = local_1040;
      }
      bVar9 = *(byte *)(uVar5 * 0x60 + 0x50 + *(int *)(param_1 + 0x16c));
      if (bVar9 == 0xff) {
        for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
      }
      else {
        FUN_005c0500(puVar11,puVar10,(uint)bVar9 * 0x40 + param_9);
      }
      local_107d = local_107d + 1;
      uVar5 = (uint)local_107d;
    } while ((int)uVar5 < *(int *)(param_1 + 0x168));
  }
  return;
}

