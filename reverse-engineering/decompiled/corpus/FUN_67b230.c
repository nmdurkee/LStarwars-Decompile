/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67b230; label: FUN_0067b230
 */

void FUN_0067b230(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_0292186c;
  if (DAT_0292186c != 0) {
    *param_1 = *(undefined4 *)(DAT_0292186c + 0xa8);
    param_1[1] = *(undefined4 *)(iVar1 + 0xac);
    param_1[2] = *(undefined4 *)(iVar1 + 0xb0);
  }
  return;
}

