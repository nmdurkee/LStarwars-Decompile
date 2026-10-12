/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x578860; label: FUN_00578860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00578860(undefined4 param_1,byte *param_2,undefined1 *param_3,undefined1 *param_4,
                 undefined1 *param_5)

{
  *param_2 = (byte)((uint)param_1 >> 0x1a);
  *param_3 = (char)((uint)param_1 >> 0x10);
  *param_4 = (char)((uint)param_1 >> 8);
  *param_5 = (char)param_1;
  return;
}

