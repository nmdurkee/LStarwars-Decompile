/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a74e0; label: FUN_004a74e0
 */

undefined4 FUN_004a74e0(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  
  if (((((DAT_00951288 != 0) || ((*(uint *)(param_1 + 0xef4) & 0x400) != 0)) ||
       (*(char *)(param_1 + 0x7b5) == '+')) ||
      ((((*(char *)(param_1 + 0x7b5) == '\x1f' ||
         (sVar1 = *(short *)(param_1 + 0x1064), sVar1 == DAT_007f18f4)) ||
        ((sVar1 == DAT_007f1af4 || ((sVar1 == DAT_007f18f8 || (sVar1 == DAT_007f1914)))))) ||
       (sVar1 == DAT_007f1ae4)))) || (sVar1 == DAT_007f1af8)) {
    return 0;
  }
  iVar2 = FUN_004a7490(param_1,(int)*(char *)(param_1 + 0x285));
  if (((param_2 != 0) && (*(char *)(param_1 + 0x281) == '\0')) || (iVar2 == 0)) {
    if (*(char *)(param_1 + 0x1078) == '\0') {
      return 0;
    }
    if (iVar2 == 0) {
      return 0;
    }
    if (*(float *)(param_1 + 0x84) <= *(float *)(param_1 + 0x6ac)) {
      return 0;
    }
    iVar2 = FUN_004a7490(param_1,(int)*(char *)(param_1 + 0x6c0));
    if (iVar2 == 0) {
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 0x7b5) = 0x33;
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x1a8);
  *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
  *(ushort *)(param_1 + 0x7aa) = (-(ushort)(iVar2 != 0) & 0x65) + 5;
  *(undefined1 *)(param_1 + 0xe32) = 0;
  return 1;
}

