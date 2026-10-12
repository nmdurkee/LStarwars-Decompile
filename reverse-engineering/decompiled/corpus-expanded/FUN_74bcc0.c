/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74bcc0; label: FUN_0074bcc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0074bcc0(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  if (*(uint *)(*in_ECX + 8) <= (uint)in_ECX[1]) {
    FUN_006e9fe6();
    return in_ECX[1];
  }
  return in_ECX[1];
}

