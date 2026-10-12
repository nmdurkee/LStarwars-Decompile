/* Ghidra analysis pseudocode, not original source.
 * ev_9fbce418ff706a0b7b075125bb388321a8b7253f9fe5e73a40a3ba0c9cf38ba0
 * Entry: 0x587130; label: FUN_00587130
 */

void FUN_00587130(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) | 0x8000;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) & 0xffff7fff;
    }
  }
  return;
}

