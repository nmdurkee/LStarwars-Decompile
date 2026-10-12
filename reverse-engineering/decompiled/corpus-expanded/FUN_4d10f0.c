/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d10f0; label: FUN_004d10f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d10f0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0xffffffff;
  }
  return;
}

