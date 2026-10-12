/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x609dd0; label: FUN_00609dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00609dd0(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  if (*(uint *)(*in_ECX + 8) <= (uint)in_ECX[1]) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + 8;
  return;
}

