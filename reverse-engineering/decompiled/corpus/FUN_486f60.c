/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x486f60; label: FUN_00486f60
 */

int FUN_00486f60(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 0x28d);
  uVar1 = DAT_0093d500;
  do {
    uVar1 = uVar1 - 1;
    if ((int)uVar1 < 1) {
      return -1;
    }
    uVar3 = uVar3 + 1;
    if (uVar3 == DAT_0093d500) {
      uVar3 = 0;
    }
    iVar2 = uVar3 * 0x10d8 + DAT_0093d504;
  } while ((((((iVar2 == 0) || (iVar2 == param_1)) || ((*(uint *)(iVar2 + 0x1fc) & 1) == 0)) ||
            (((*(uint *)(iVar2 + 0x1fc) & 0x1000) == 0 || (*(char *)(iVar2 + 0x28b) != '\0')))) ||
           ((*(char *)(iVar2 + 0x280) == -1 ||
            (((*(byte *)(iVar2 + 0x7c5) & 2) != 0 || ((*(byte *)(iVar2 + 0xef4) & 2) != 0)))))) ||
          ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar2 + 0x7b5) * 0x10 + 8) & 0x800) != 0));
  return (int)*(char *)(iVar2 + 0x280);
}

