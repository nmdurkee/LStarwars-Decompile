/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74be00; label: FUN_0074be00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074be00(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  uVar1 = in_ECX[1] + param_1 * 4;
  if ((*(uint *)(*in_ECX + 8) < uVar1) || (uVar1 < *(uint *)(*in_ECX + 4))) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + param_1 * 4;
  return;
}

