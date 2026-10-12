/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74bc80; label: FUN_0074bc80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074bc80(byte param_1)

{
  int *in_ECX;
  
  if (*in_ECX != 0) {
    thunk_FUN_006e85b0(*in_ECX);
    *in_ECX = 0;
  }
  FUN_00748490();
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

