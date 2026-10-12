/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x609e00; label: FUN_00609e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00609e00(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x14) = param_1;
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    *(undefined1 *)(*(int *)(in_ECX + 4) + param_1) = 0;
    return;
  }
  *(undefined1 *)(in_ECX + 4 + param_1) = 0;
  return;
}

