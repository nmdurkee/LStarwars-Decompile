/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x5806a0; label: FUN_005806a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005806a0(int param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < *(int *)(PTR_PTR_008040bc + 4))) {
    return param_1 * 0xa4 + *(int *)PTR_PTR_008040bc;
  }
  if ((param_2 != 0) &&
     ((iVar1 = *(int *)(PTR_PTR_008040bc + 4), iVar1 <= param_1 && (param_1 < iVar1 + 8)))) {
    return (param_1 - iVar1) * 0xa4 + 0x4b14 + param_2;
  }
  return 0;
}

