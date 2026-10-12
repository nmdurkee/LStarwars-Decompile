/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x475850; label: FUN_00475850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00475850(undefined4 *param_1)

{
  if (DAT_0093b324 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
    }
    return -1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(&DAT_007fa138 + DAT_007fa190 * 0xc);
  }
  return (int)DAT_007fa190;
}

