/* Ghidra pseudocode, not original source.
 * ev_6ea325c01e2f5d3a14c4ac5085e7df4745032b0fec5c1eb605a31240a38307be
 * Entry: 0x53fe70; label: FUN_0053fe70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

