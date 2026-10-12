/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c0e0; label: FUN_0074c0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c0e0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  FUN_0074bbc0();
  puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4);
  *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4) = puVar1 + 5;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = param_1;
  }
  if (*(undefined4 **)(in_ECX + 0x118) == (undefined4 *)0x0) {
    *(undefined4 **)(in_ECX + 0x114) = puVar1;
    *(undefined4 **)(in_ECX + 0x118) = puVar1 + 1;
  }
  else {
    **(undefined4 **)(in_ECX + 0x118) = puVar1;
    *(undefined4 **)(in_ECX + 0x118) = puVar1 + 1;
  }
  *(undefined4 **)(in_ECX + 0x134 + *(int *)(in_ECX + 0x2c4) * 4) = puVar1;
  *(int *)(in_ECX + 0x2c4) = *(int *)(in_ECX + 0x2c4) + 1;
  *(undefined4 **)(in_ECX + 0x2c8 + *(int *)(in_ECX + 0x458) * 4) = puVar1;
  *(int *)(in_ECX + 0x458) = *(int *)(in_ECX + 0x458) + 1;
  *(undefined4 **)(in_ECX + 0x118) = puVar1 + 2;
  return;
}

