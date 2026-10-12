/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c6bb0; label: FUN_005c6bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005c6bb0(int param_1)

{
  return *(int *)(param_1 + 0x808) != 0;
}

