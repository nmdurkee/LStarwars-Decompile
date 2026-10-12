/* Ghidra analysis pseudocode, not original source.
 * ev_9eaa74bb799d8967933988d6e124ea5c840b05143c454f375b97301964b1c1b3
 * Entry: 0x5791b0; label: FUN_005791b0
 */

void FUN_005791b0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f9e70(param_1);
  if (iVar1 < 10) {
    iVar1 = 10;
  }
  else if (20000 < iVar1) {
    *(undefined2 *)(DAT_00951b74 + 0x8c) = 20000;
    return;
  }
  *(short *)(DAT_00951b74 + 0x8c) = (short)iVar1;
  return;
}

