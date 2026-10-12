/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54dcb0; label: FUN_0054dcb0
 */

void FUN_0054dcb0(int param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 local_48 [6];
  undefined4 local_30;
  undefined4 local_24 [6];
  undefined4 local_c;
  
  if (((((*(byte *)(*(int *)(param_1 + 0x798) + 0x1e) & 4) != 0) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0))
      || (iVar3 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),0,0), iVar3 != 0)) &&
     (*(char *)(param_1 + 0x7b3) != '\x01')) {
    local_30 = 0xff003f5f;
    if ((*(byte *)(*(int *)(param_1 + 0x798) + 0x1e) & 8) == 0) {
      local_30 = DAT_0080245c;
    }
    local_c = local_30;
    iVar4 = FUN_0054dc30();
    iVar3 = *(int *)(param_1 + 0x798);
    local_48[0] = *(undefined4 *)(iVar3 + 0x30);
    local_48[1] = *(undefined4 *)(iVar3 + 0x34);
    local_48[2] = *(undefined4 *)(iVar3 + 0x38);
    local_24[0] = *local_50;
    local_24[1] = local_50[1];
    local_24[2] = local_50[2];
    FUN_005dbed0(local_48,DAT_0093b108,0);
    if (iVar4 == 2) {
      local_48[0] = local_24[0];
      local_48[1] = local_24[1];
      local_48[2] = local_24[2];
      local_24[0] = *local_4c;
      local_24[1] = local_4c[1];
      local_24[2] = local_4c[2];
      FUN_005dbed0(local_48,DAT_0093b108,0);
    }
    bVar2 = *(byte *)(*(int *)(param_1 + 0x798) + 0x1e);
    if (((bVar2 & 4) != 0) && ((bVar2 & 8) == 0)) {
      if (DAT_00802464 != 0) {
        local_48[0] = local_24[0];
        local_48[1] = local_24[1];
        local_48[2] = local_24[2];
        FUN_004eeb10(local_48,*(int *)(param_1 + 0x798) + 0x5c,6,0,0);
        return;
      }
      iVar3 = 0;
      do {
        puVar1 = (undefined4 *)(iVar3 + 0x5c + *(int *)(param_1 + 0x798));
        puVar5 = local_24;
        puVar6 = local_48;
        for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        local_24[0] = *puVar1;
        local_24[1] = puVar1[1];
        local_24[2] = puVar1[2];
        local_c = DAT_0080245c;
        FUN_005dbed0(local_48,DAT_0093b108,0);
        iVar3 = iVar3 + 0xc;
      } while (iVar3 < 0x48);
    }
  }
  return;
}

