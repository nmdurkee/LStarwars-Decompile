/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d6db0; label: FUN_006d6db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006d6db0(int param_1,int param_2)

{
  int in_ECX;
  
  if (param_1 - 10U < 4) {
    if (param_2 != *(int *)(in_ECX + 0x6608)) {
      param_1 = param_1 + 1;
    }
    if (-1 < param_2) {
      param_1 = param_1 + param_2 * 2;
    }
  }
  return param_1;
}

