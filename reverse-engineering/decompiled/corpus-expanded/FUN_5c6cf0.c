/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c6cf0; label: FUN_005c6cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c6cf0(int param_1,int param_2)

{
  if (param_2 == 4) {
    return *(undefined4 *)(param_1 + 0x800);
  }
  if (param_2 != 5) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x804);
}

