/* Ghidra analysis pseudocode, not original source.
 * ev_9fbce418ff706a0b7b075125bb388321a8b7253f9fe5e73a40a3ba0c9cf38ba0
 * Entry: 0x587630; label: FUN_00587630
 */

void FUN_00587630(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_0057a240(*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00954404 + 0xec) = uVar1;
  }
  return;
}

