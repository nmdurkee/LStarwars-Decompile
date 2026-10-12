/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5df880; label: FUN_005df880
 */

void FUN_005df880(void)

{
  int iVar1;
  char *pcVar2;
  ushort *puVar3;
  int unaff_ESI;
  int iVar4;
  int local_8;
  int local_4;
  
  puVar3 = *(ushort **)(unaff_ESI + 0x18);
  if ((*(int *)(unaff_ESI + 0x68) != 0) && (local_4 = 0, 0 < *(int *)(unaff_ESI + 0x10))) {
    local_8 = 0;
    do {
      iVar1 = *(int *)(local_8 + 8 + *(int *)(unaff_ESI + 0x14));
      iVar4 = 0;
      if (*puVar3 != 0) {
        do {
          pcVar2 = (char *)(*(int *)(iVar1 + iVar4 * 4) * 0x10 + *(int *)(unaff_ESI + 8));
          if ((pcVar2[1] != '\0') && (*pcVar2 == -0x7e)) {
            FUN_00603ad0(pcVar2 + -0x10,pcVar2,
                         *(undefined4 *)(*(int *)(unaff_ESI + 0x68) + local_4 * 4));
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*puVar3);
      }
      local_8 = local_8 + 0xc;
      local_4 = local_4 + 1;
      puVar3 = puVar3 + 1;
    } while (local_4 < *(int *)(unaff_ESI + 0x10));
  }
  return;
}

