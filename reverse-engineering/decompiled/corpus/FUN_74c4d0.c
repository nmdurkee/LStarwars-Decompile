/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74c4d0; label: FUN_0074c4d0
 */

void FUN_0074c4d0(undefined4 param_1)

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
    *puVar1 = 6;
    puVar1[1] = 0;
    puVar1[2] = param_1;
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

