/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74c1a0; label: FUN_0074c1a0
 */

void FUN_0074c1a0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  FUN_0074bbc0();
  *(int *)(in_ECX + 0x118) = *(int *)(in_ECX + 0x130 + *(int *)(in_ECX + 0x2c4) * 4) + 0xc;
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
  *(undefined4 **)(in_ECX + 0x118) = puVar1 + 2;
  return;
}

