/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d5f0; label: FUN_0074d5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074d5f0(void)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  undefined1 local_8 [8];
  
  uVar1 = *(uint *)(in_ECX + 8);
  if (uVar1 < *(uint *)(in_ECX + 4)) {
    FUN_006e9fe6();
  }
  uVar2 = *(uint *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 8) < uVar2) {
    FUN_006e9fe6();
  }
  FUN_0074d4d0(local_8,in_ECX,uVar2,in_ECX,uVar1);
  return;
}

