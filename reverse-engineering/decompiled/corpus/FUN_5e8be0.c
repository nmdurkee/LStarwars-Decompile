/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e8be0; label: FUN_005e8be0
 */

void FUN_005e8be0(void)

{
  undefined1 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x70c)) {
    puVar2 = (undefined4 *)(in_ECX + 0x2b4);
    do {
      puVar2[0x30] = 0;
      iVar4 = 2;
      puVar3 = puVar2;
      do {
        FUN_005fca40(puVar3[-2]);
        puVar1 = (undefined1 *)*puVar3;
        puVar3[1] = puVar1;
        puVar3 = puVar3 + 0x11;
        iVar4 = iVar4 + -1;
        *puVar1 = 0x8d;
        *(undefined4 *)(puVar1 + 4) = 0;
        puVar1[1] = 1;
      } while (iVar4 != 0);
      local_8 = local_8 + 1;
      puVar2 = puVar2 + 0xe0;
    } while (local_8 < *(int *)(in_ECX + 0x70c));
  }
  return;
}

