/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x568760; label: FUN_00568760
 */

void FUN_00568760(void)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(PTR_DAT_00802c54 + 0x50c8) != 0) && (0 < *(int *)(PTR_DAT_00802c54 + 0x50c0))) {
    iVar1 = *(int *)(PTR_DAT_00802c54 + 0x50c8);
    iVar2 = 0;
    if (0 < *(int *)(PTR_DAT_00802c54 + 0x50c0)) {
      do {
        if (iVar1 != 0) {
          if (*(short *)(iVar1 + 0x102) != -1) {
            FUN_0067c930((int)*(short *)(iVar1 + 0x102));
            *(undefined2 *)(iVar1 + 0x102) = 0xffff;
          }
          if (*(short *)(iVar1 + 0x104) != -1) {
            FUN_0067c930((int)*(short *)(iVar1 + 0x104));
            *(undefined2 *)(iVar1 + 0x104) = 0xffff;
          }
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x114;
      } while (iVar2 < *(int *)(PTR_DAT_00802c54 + 0x50c0));
    }
  }
  return;
}

