/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74ba60; label: FUN_0074ba60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074ba60(void)

{
  int *in_ECX;
  
  if (*in_ECX != 0) {
    thunk_FUN_006e85b0(*in_ECX);
    *in_ECX = 0;
  }
  FUN_00748490();
  return;
}

