/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41ade0; label: FUN_0041ade0
 */

void FUN_0041ade0(void)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  short *psVar8;
  int local_8;
  int local_4;
  
  local_4 = 0;
  if (0 < *(int *)(DAT_029130e4 + 0x10)) {
    local_8 = 0;
    iVar3 = DAT_029130e4;
    do {
      psVar8 = (short *)(*(int *)(iVar3 + 0x18) + local_8);
      iVar4 = 0;
      iVar6 = *psVar8 * 0x120 + DAT_0093b284;
      if (*(char *)(iVar6 + 0x11f) != '\0') {
        iVar5 = 0;
        do {
          uVar2 = FUN_005dab70(*(int *)(iVar6 + 4) + iVar5,*(undefined4 *)(psVar8 + 2));
          *(undefined2 *)(*(int *)(iVar6 + 4) + 0x1a + iVar5) = uVar2;
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x1c;
          iVar3 = DAT_029130e4;
        } while (iVar4 < (int)(uint)*(byte *)(iVar6 + 0x11f));
      }
      local_8 = local_8 + 0x54;
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(iVar3 + 0x10));
  }
  ppuVar7 = &PTR_DAT_007f23b0;
  do {
    ppuVar7[2] = (undefined *)0x0;
    if (((short *)*ppuVar7 != (short *)0x0) && (iVar3 = (int)*(short *)*ppuVar7, iVar3 != -1)) {
      bVar1 = FUN_0055bac0(iVar3 * 0x120 + DAT_0093b284,ppuVar7[1]);
      ppuVar7[2] = (undefined *)(1 << (bVar1 & 0x1f));
    }
    ppuVar7 = ppuVar7 + 3;
  } while ((int)ppuVar7 < 0x7f25a8);
  return;
}

