/* Ghidra analysis pseudocode, not original source.
 * ev_3c859e02b972a8e60701cf54913e5d4895bfb87c225b3b379a359b744e8ff688
 * Entry: 0x53fe70; label: FUN_0053fe70
 */

void FUN_0053fe70(undefined4 param_1)

{
  int iVar1;
  
  *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) | 0x40;
  iVar1 = FUN_004f9e70(param_1);
  iVar1 = (iVar1 % 0x168) * 0x10000;
  *(short *)(DAT_029838fc + 0x6e) =
       (short)((ulonglong)((longlong)iVar1 * 0xb60b60b7) >> 0x28) -
       ((short)(char)((char)(iVar1 / 0x1680000) + (char)(iVar1 >> 0x1f)) >> 0xf);
  return;
}

