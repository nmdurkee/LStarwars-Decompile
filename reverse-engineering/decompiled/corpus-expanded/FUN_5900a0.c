/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x5900a0; label: FUN_005900a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

