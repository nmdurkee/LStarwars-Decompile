/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74bd90; label: FUN_0074bd90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074bd90(uint param_1,int param_2)

{
  int *in_ECX;
  
  *in_ECX = 0;
  if (((param_2 == 0) || (param_1 < *(uint *)(param_2 + 4))) || (*(uint *)(param_2 + 8) < param_1))
  {
    FUN_006e9fe6();
  }
  *in_ECX = param_2;
  in_ECX[1] = param_1;
  return;
}

