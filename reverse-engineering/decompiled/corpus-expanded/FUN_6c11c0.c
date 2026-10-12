/* Ghidra pseudocode, not original source.
 * ev_614da4738c60d4d314f1aae40ed3f18729decbec523d320f83fa909eb3c69e70
 * Entry: 0x6c11c0; label: FUN_006c11c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c11c0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) < 8) {
    *(undefined4 *)(in_ECX + *(int *)(in_ECX + 0x20) * 4) = param_1;
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
  }
  return;
}

