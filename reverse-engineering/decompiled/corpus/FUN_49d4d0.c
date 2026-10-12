/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49d4d0; label: FUN_0049d4d0
 */

void FUN_0049d4d0(int param_1,undefined1 param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x7b5) = 0x5d;
  *(undefined1 *)(param_1 + 0x7b3) = param_2;
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x2c4);
  *(undefined4 *)(param_1 + 0x778) = 0x4e6e6b28;
  *(ushort *)(param_1 + 0x7aa) = (-(ushort)(iVar1 != 0) & 0xb0) + 1;
  return;
}

