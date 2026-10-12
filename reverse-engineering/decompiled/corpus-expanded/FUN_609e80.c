/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x609e80; label: FUN_00609e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00609e80(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return in_ECX[1] - param_1[1] >> 3;
}

