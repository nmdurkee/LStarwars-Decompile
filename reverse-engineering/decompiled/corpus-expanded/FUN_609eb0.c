/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x609eb0; label: FUN_00609eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00609eb0(uint param_1,int param_2)

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

