/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c6cc0; label: FUN_005c6cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c6cc0(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 4) {
    *(undefined4 *)(param_1 + 0x800) = param_3;
  }
  else if (param_2 == 5) {
    *(undefined4 *)(param_1 + 0x804) = param_3;
    return;
  }
  return;
}

