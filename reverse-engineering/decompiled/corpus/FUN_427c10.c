/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x427c10; label: FUN_00427c10
 */

void FUN_00427c10(int param_1)

{
  uint uVar1;
  
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0a0) &&
     ((DAT_0087b014 == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0x23;
    uVar1 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined4 *)(param_1 + 0x784) = 0x3f000000;
    *(ushort *)(param_1 + 0x7aa) = ~(ushort)(uVar1 >> 0xb) & 4 | 1;
  }
  return;
}

