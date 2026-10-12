/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c1140; label: FUN_006c1140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1140(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) < 8) {
    puVar1 = (undefined4 *)(in_ECX + *(int *)(in_ECX + 0x60) * 0xc);
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    *(int *)(in_ECX + 0x60) = *(int *)(in_ECX + 0x60) + 1;
  }
  return;
}

