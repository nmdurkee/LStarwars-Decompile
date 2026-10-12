/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c6d20; label: FUN_005c6d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c6d20(int param_1,int param_2,undefined4 param_3)

{
  param_1 = param_2 * 0x380 + param_1;
  *(undefined4 *)(param_1 + 0x354 + *(int *)(param_1 + 0x374) * 4) = param_3;
  *(int *)(param_1 + 0x374) = *(int *)(param_1 + 0x374) + 1;
  return;
}

