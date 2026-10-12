/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bd850; label: FUN_004bd850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004bd850(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0xffffffff;
    param_2[2] = 0;
  }
  return;
}

