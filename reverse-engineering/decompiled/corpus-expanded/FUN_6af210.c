/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6af210; label: FUN_006af210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006af210(int *param_1,int param_2)

{
  void *pvVar1;
  
  *param_1 = param_2;
  pvVar1 = _calloc(param_2 * 3,4);
  param_1[1] = (int)pvVar1;
  pvVar1 = _calloc(0x20,4);
  param_1[2] = (int)pvVar1;
  if (param_2 != 1) {
    FUN_006a9e30(param_2,param_1[1] + param_2 * 4,pvVar1);
  }
  return;
}

