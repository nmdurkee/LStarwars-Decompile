/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8550; label: FUN_005f8550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f8550(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_006e5630(param_2,*param_1);
    return;
  }
  FUN_006e5630(param_2,0);
  return;
}

