/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x524b70; label: FUN_00524b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524b70(void)

{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_c;
  
  if ((*(int *)(DAT_009238e4 + 0x31b94) != 0) &&
     (iVar3 = **(int **)(*(int *)(DAT_009238e4 + 0x31b94) + 4), iVar3 != 0)) {
    sVar2 = *(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x30);
    if (((-1 < sVar2) &&
        ((((int)sVar2 < (int)(uint)*(byte *)(iVar3 + 0x10) &&
          (sVar2 = *(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x32), -1 < sVar2)) &&
         (uVar6 = (uint)sVar2, (int)uVar6 < (int)(uint)*(byte *)(iVar3 + 0x10))))) &&
       (uVar4 = (uint)*(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x30), uVar4 != uVar6)) {
      do {
        uVar6 = (uint)*(byte *)(*(int *)(*(int *)(iVar3 + 0x84) + uVar4 * 4) + uVar6);
        if (uVar6 == 0xff) {
          return;
        }
        iVar7 = uVar4 * 0x5c;
        iVar5 = *(int *)(*(int *)(*(int *)(iVar3 + 0x7c) + 0x34 + iVar7) + uVar6 * 4);
        uVar6 = (uint)*(byte *)(iVar5 + 0x10);
        bVar8 = uVar6 == uVar4;
        uVar4 = uVar6;
        if (bVar8) {
          uVar4 = (uint)*(byte *)(iVar5 + 0x11);
        }
        puVar1 = (undefined4 *)(*(int *)(iVar3 + 0x7c) + 4 + iVar7);
        iVar5 = uVar4 * 0x5c + *(int *)(iVar3 + 0x7c);
        local_48 = *puVar1;
        local_40 = puVar1[2];
        local_24 = *(undefined4 *)(iVar5 + 4);
        local_44 = _DAT_00801ccc + (float)puVar1[1];
        local_1c = *(undefined4 *)(iVar5 + 0xc);
        local_20 = _DAT_00801ccc + *(float *)(iVar5 + 8);
        local_30 = 0xff0000ff;
        local_c = 0xff0000ff;
        FUN_00512b00(&local_48,0,0);
        uVar6 = (uint)*(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x32);
      } while (uVar4 != uVar6);
    }
  }
  return;
}

