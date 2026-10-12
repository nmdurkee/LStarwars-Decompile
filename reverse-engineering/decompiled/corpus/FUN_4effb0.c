/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4effb0; label: FUN_004effb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004effb0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_8;
  int local_4;
  
  local_8 = 0;
  local_4 = 0;
  iVar2 = 0;
  if (0 < DAT_0297e064) {
    puVar4 = &DAT_0297e080;
    puVar3 = &DAT_029803e0;
    do {
      uVar1 = (*(code *)puVar3[0x8c])(puVar3);
      if ((uVar1 & 2) == 0) {
        local_8 = local_8 + 1;
        puVar5 = puVar3;
        puVar6 = puVar4;
        for (iVar2 = 0x8d; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        puVar4 = puVar4 + 0x8d;
      }
      local_4 = local_4 + 1;
      puVar3 = puVar3 + 0x8d;
      iVar2 = local_8;
    } while (local_4 < DAT_0297e064);
  }
  *param_1 = &DAT_0297e080;
  _DAT_029838d0 = iVar2;
  return;
}

