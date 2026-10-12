/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58ed10; label: FUN_0058ed10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058ed10(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      FUN_005a15e0(*(undefined4 *)(param_1 + 0x10),0);
    }
    *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) & 0xfffd;
  }
  return;
}

