/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x5900a0; label: FUN_005900a0
 */

void FUN_005900a0(int param_1,int param_2)

{
  if (param_1 != 0) {
    FUN_005a15e0(*(undefined4 *)(param_1 + 0x10),param_2);
    *(ushort *)(param_1 + 0x7a) =
         *(ushort *)(param_1 + 0x7a) ^
         (byte)((param_2 != 0) * '\x02' ^ *(byte *)(param_1 + 0x7a)) & 2;
  }
  return;
}

