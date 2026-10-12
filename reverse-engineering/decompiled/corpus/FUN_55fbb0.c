/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55fbb0; label: FUN_0055fbb0
 */

void FUN_0055fbb0(int param_1)

{
  ushort *puVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x5048) != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x504c))) {
    puVar1 = (ushort *)(*(int *)(param_1 + 0x5048) + 0xc);
    do {
      *puVar1 = *puVar1 & 0xfff9;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 8;
    } while (iVar2 < *(int *)(param_1 + 0x504c));
  }
  return;
}

