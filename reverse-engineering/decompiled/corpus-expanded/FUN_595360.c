/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x595360; label: FUN_00595360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00595360(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x800) = 0;
  FUN_005b79d0(in_ECX + 0x7c0,param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

