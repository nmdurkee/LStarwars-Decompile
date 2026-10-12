/* Ghidra analysis pseudocode, not original source.
 * ev_9eaa74bb799d8967933988d6e124ea5c840b05143c454f375b97301964b1c1b3
 * Entry: 0x5795f0; label: FUN_005795f0
 */

void FUN_005795f0(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) | 0x8000;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) & 0xffff7fff;
    }
  }
  return;
}

