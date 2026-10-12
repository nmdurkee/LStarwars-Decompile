/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bd7d0; label: FUN_004bd7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004bd7d0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *param_1 + 0x80;
  }
  return 0;
}

