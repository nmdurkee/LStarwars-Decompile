/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x42b730; label: FUN_0042b730
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b730(void)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  
  uVar3 = 0;
  iVar5 = 0;
  pcVar4 = &DAT_007f3da3;
  do {
    puVar2 = PTR_DAT_00802c54;
    (&DAT_0086e4c8)[uVar3 >> 5] = (&DAT_0086e4c8)[uVar3 >> 5] | 1 << ((byte)uVar3 & 0x1f);
    if (*(int *)(puVar2 + 0x128) == DAT_00951b94) {
      *(undefined1 *)(iVar5 + 99 + DAT_00880480) = 1;
    }
    cVar1 = *pcVar4;
    if ((cVar1 != -1) && ((&DAT_0086e0fa)[cVar1 * 0xc] == '\0')) {
      (&DAT_0086e0fa)[cVar1 * 0xc] = 1;
    }
    pcVar4 = pcVar4 + 0x20;
    uVar3 = uVar3 + 1;
    iVar5 = iVar5 + 0x74;
  } while ((int)pcVar4 < 0x7f4323);
  DAT_0086e4b8 = 0xffffffff;
  _DAT_0086e4bc = 0xffffffff;
  return;
}

