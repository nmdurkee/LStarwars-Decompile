/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c2b0; label: FUN_0074c2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c2b0(undefined1 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  FUN_0074bbc0();
  puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4);
  *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4) = puVar1 + 3;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 5;
    puVar1[1] = 0;
    *(undefined1 *)(puVar1 + 2) = param_1;
  }
  if (*(undefined4 **)(in_ECX + 0x118) == (undefined4 *)0x0) {
    *(undefined4 **)(in_ECX + 0x114) = puVar1;
    *(undefined4 **)(in_ECX + 0x118) = puVar1 + 1;
    return;
  }
  **(undefined4 **)(in_ECX + 0x118) = puVar1;
  *(undefined4 **)(in_ECX + 0x118) = puVar1 + 1;
  return;
}

