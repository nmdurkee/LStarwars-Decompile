/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43c130; label: FUN_0043c130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0043c130(int param_1)

{
  char cVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) {
    cVar1 = *(char *)(*(int *)(param_1 + 4) + 0x13f);
    if (cVar1 == '\0') {
      return (float10)(*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c) * _DAT_00925018)
      ;
    }
    if (cVar1 == '\x01') {
      return (float10)(*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x18) * _DAT_00925018)
      ;
    }
    if (cVar1 == '\x02') {
      return (float10)(*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x14) * _DAT_00925018)
      ;
    }
  }
  return (float10)0;
}

