/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x609ce0; label: FUN_00609ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00609ce0(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return CONCAT31((int3)((uint)in_ECX[1] >> 8),in_ECX[1] != param_1[1]);
}

