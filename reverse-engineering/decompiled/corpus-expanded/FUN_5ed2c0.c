/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ed2c0; label: FUN_005ed2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ed2c0(undefined4 *param_1)

{
  if (((undefined4 *)param_1[1] != (undefined4 *)0x0) && (DAT_00973938 != 0)) {
    FUN_005ed1b0(param_1[8],*(undefined4 *)param_1[1],*param_1);
    param_1[10] = param_1[10] | 4;
    return;
  }
  param_1[10] = param_1[10] & 0xfffffffb;
  return;
}

