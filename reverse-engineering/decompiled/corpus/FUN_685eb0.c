/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x685eb0; label: FUN_00685eb0
 */

void FUN_00685eb0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_029620a8;
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x1c8);
    if (*(short *)(iVar2 + 0x18e) != *(short *)(iVar2 + 0x186)) {
      FUN_00683560(iVar2);
    }
  }
  return;
}

