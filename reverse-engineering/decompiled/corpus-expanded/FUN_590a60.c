/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x590a60; label: FUN_00590a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00590a60(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0xffffffff;
    param_2[3] = 0xffffffff;
    param_2[4] = 0xffffffff;
    param_2[5] = 0xffffffff;
    param_2[6] = 0;
    param_2[7] = 0;
    _memset(param_2 + 8,0,0x40);
  }
  return;
}

