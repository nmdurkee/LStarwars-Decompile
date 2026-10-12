/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cda40; label: FUN_004cda40
 */

int FUN_004cda40(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x6c) == 0) {
      FUN_004ccad0(param_1);
    }
    cVar1 = *(char *)(param_1 + 0x37);
    if (cVar1 == '\x01') {
      return *(int *)(param_1 + 0x6c) + 0x80;
    }
    if (cVar1 == '\x02') {
      iVar2 = FUN_005cf9c0();
      return iVar2;
    }
    if (cVar1 == '\x03') {
      iVar2 = FUN_0055a360(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),
                           *(undefined4 *)(param_1 + 0x6c));
      return iVar2;
    }
  }
  return 0;
}

