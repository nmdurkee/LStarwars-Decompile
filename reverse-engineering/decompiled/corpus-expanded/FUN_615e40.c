/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x615e40; label: FUN_00615e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00615e40(int param_1)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(DAT_028572e0 + 0x84);
    FUN_00612ac0(param_1);
    FUN_006157f0(*(undefined2 *)(param_1 + 2));
    FUN_0060e4c0(param_1,*(undefined4 *)(param_1 + 8));
  }
  return;
}

