/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63ce90; label: FUN_0063ce90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063ce90(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x14) == 1)) {
    FUN_00623e00(param_1 + 0x20,*(undefined4 *)(param_1 + 0x1c),
                 *(uint *)(param_1 + 8) & 0xffffff | 0x80000000,DAT_0080ff40,0);
  }
  return;
}

