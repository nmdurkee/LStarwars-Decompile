/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x5806a0; label: FUN_005806a0
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

