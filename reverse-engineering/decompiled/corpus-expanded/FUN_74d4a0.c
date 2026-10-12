/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d4a0; label: FUN_0074d4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0074d4a0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 8);
  uVar2 = *(uint *)(in_ECX + 4);
  *param_1 = 0;
  if (uVar1 < uVar2) {
    FUN_006e9fe6();
  }
  *param_1 = in_ECX;
  param_1[1] = uVar1;
  return param_1;
}

