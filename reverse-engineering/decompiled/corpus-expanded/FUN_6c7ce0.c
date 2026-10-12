/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7ce0; label: FUN_006c7ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_006c7ce0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = (undefined4 *)FUN_00633440(0x58,1);
  if (puVar2 != (undefined4 *)0x0) {
    puVar1 = puVar2 + 1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      puVar2[2] = 0;
    }
    *puVar2 = &PTR_FUN_0076fa4c;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    *(undefined2 *)(puVar2 + 0x11) = DAT_02973aa0;
    *puVar1 = 0;
    puVar2[2] = *(undefined4 *)(in_ECX + 0xc);
    if (*(int *)(in_ECX + 0xc) != 0) {
      *(undefined4 **)(*(int *)(in_ECX + 0xc) + 4) = puVar2;
    }
    *(undefined4 **)(in_ECX + 0xc) = puVar2;
    if (*(int *)(in_ECX + 8) == 0) {
      *(undefined4 **)(in_ECX + 8) = puVar2;
    }
    *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
    return puVar2;
  }
  return (undefined4 *)0x0;
}

