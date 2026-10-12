/* Ghidra pseudocode, not original source.
 * ev_614da4738c60d4d314f1aae40ed3f18729decbec523d320f83fa909eb3c69e70
 * Entry: 0x6c11e0; label: FUN_006c11e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c11e0(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + -1;
  return *(undefined4 *)(in_ECX + *(int *)(in_ECX + 0x20) * 4);
}

