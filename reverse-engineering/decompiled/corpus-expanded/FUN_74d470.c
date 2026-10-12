/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d470; label: FUN_0074d470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0074d470(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = *(uint *)(in_ECX + 4);
  uVar1 = *(uint *)(in_ECX + 8);
  *param_1 = 0;
  if (uVar1 < uVar2) {
    FUN_006e9fe6();
  }
  *param_1 = in_ECX;
  param_1[1] = uVar2;
  return param_1;
}

