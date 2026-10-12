/* Ghidra analysis pseudocode, not original source.
 * ev_9fbce418ff706a0b7b075125bb388321a8b7253f9fe5e73a40a3ba0c9cf38ba0
 * Entry: 0x5875a0; label: FUN_005875a0
 */

void FUN_005875a0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_0057a240(*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00954400 + 0x42) = uVar1;
    if ((*(short *)(DAT_00954400 + 0x42) == -1) && (DAT_009553c8 != 0)) {
      iVar2 = FUN_00579f60(*(undefined4 *)(param_1 + 0x510),3);
      if (iVar2 != 0) {
        uVar1 = FUN_0057a240(*(undefined4 *)(param_1 + 0x510));
        *(undefined2 *)(DAT_00954400 + 0x42) = uVar1;
        FUN_004f1e80(*(undefined4 *)(param_1 + 0x510),&DAT_00763618);
        FUN_00579f60(*(undefined4 *)(param_1 + 0x510),3);
      }
    }
  }
  return;
}

