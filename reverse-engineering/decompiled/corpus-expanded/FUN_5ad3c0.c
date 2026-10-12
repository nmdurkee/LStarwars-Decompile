/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ad3c0; label: FUN_005ad3c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ad3c0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0xffffffff;
    param_2[2] = 0xffffffff;
    param_2[3] = 0xffffffff;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    param_2[9] = 0;
    param_2[10] = 0;
    param_2[0xb] = 0;
    _memset(param_2 + 0xc,0xff,0x40);
  }
  return;
}

