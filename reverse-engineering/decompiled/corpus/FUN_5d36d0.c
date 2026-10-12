/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d36d0; label: FUN_005d36d0
 */

void FUN_005d36d0(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  byte local_491;
  undefined4 local_48c;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_480 [16];
  undefined1 local_440 [64];
  int local_400 [256];
  
  if (param_2 != 0) {
    _memset(local_400,0,*(int *)(param_1 + 0x168) * 4);
    bVar6 = 0;
    if (0 < param_2) {
      iVar4 = *(int *)(param_1 + 0x178);
      uVar2 = 0;
      do {
        iVar3 = uVar2 * 0x34 + param_3;
        uVar2 = (uint)*(byte *)(iVar3 + 0x30);
        if (((int)uVar2 < iVar4) &&
           (bVar1 = *(byte *)(uVar2 + *(int *)(param_1 + 0x17c)), bVar1 != 0xff)) {
          local_400[bVar1] = iVar3;
        }
        bVar6 = bVar6 + 1;
        uVar2 = (uint)bVar6;
      } while ((int)uVar2 < param_2);
    }
  }
  local_491 = 0;
  if (0 < *(int *)(param_1 + 0x168)) {
    uVar2 = 0;
    do {
      iVar4 = uVar2 * 0x40;
      if ((param_2 == 0) || (iVar3 = local_400[uVar2], iVar3 == 0)) {
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0x170) + iVar4);
      }
      else {
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0x170) + iVar4);
        puVar8 = local_480;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar7 = local_480;
        local_48c = FUN_006e6b90();
        local_488 = FUN_006e6b90();
        local_484 = FUN_006e6b90();
        thunk_FUN_005b5300(local_440,&local_48c);
        FUN_005b4900(local_440,iVar3 + 0xc);
        FUN_005c0500(puVar7,local_440,puVar7);
      }
      bVar6 = *(byte *)(uVar2 * 0x60 + 0x50 + *(int *)(param_1 + 0x16c));
      if (bVar6 == 0xff) {
        puVar8 = (undefined4 *)(param_4 + iVar4);
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      else {
        FUN_005c0500((undefined4 *)(param_4 + iVar4),puVar7,(uint)bVar6 * 0x40 + param_4);
      }
      local_491 = local_491 + 1;
      uVar2 = (uint)local_491;
    } while ((int)uVar2 < *(int *)(param_1 + 0x168));
  }
  return;
}

