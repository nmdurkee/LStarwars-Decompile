/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590ba0; label: FUN_00590ba0
 */

void FUN_00590ba0(int param_1)

{
  *(undefined1 *)(param_1 + 0x6d) = 2;
  if ((*(byte *)(param_1 + 0x72) & 2) != 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      FUN_005a15e0(*(undefined4 *)(param_1 + 0x10),0);
    }
    *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) & 0xfffd;
  }
  if (DAT_009555b4 != (code *)0x0) {
    (*DAT_009555b4)(param_1);
  }
  return;
}

