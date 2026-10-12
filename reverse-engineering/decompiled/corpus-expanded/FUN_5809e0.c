/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x5809e0; label: FUN_005809e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005809e0(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    cVar1 = *(char *)(*(int *)(param_1 + 4) + 0x280);
    if (cVar1 == '\0') {
      return 4;
    }
    if (cVar1 == '\x01') {
      return 5;
    }
  }
  return 3;
}

