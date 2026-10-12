/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c6c30; label: FUN_005c6c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c6c30(int param_1,int param_2,int param_3)

{
  if (*(char *)(param_3 + 0x268) != '\0') {
    return param_2 * 0x380 + 0x2e8 + param_1;
  }
  return param_2 * 0x380 + 0x2a4 + param_1;
}

