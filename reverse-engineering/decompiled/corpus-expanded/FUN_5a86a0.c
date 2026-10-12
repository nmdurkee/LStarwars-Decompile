/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a86a0; label: FUN_005a86a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005a86a0(int *param_1)

{
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) && (*(char *)(*param_1 + 8) == '\x02')) {
    return (char)param_1[1] != '\0';
  }
  return true;
}

