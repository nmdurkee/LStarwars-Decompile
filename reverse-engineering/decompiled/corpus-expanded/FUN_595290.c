/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x595290; label: FUN_00595290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00595290(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  *in_ECX = *param_1;
  in_ECX[1] = uVar1;
  in_ECX[2] = uVar2;
  in_ECX[3] = 0x3f800000;
  return;
}

