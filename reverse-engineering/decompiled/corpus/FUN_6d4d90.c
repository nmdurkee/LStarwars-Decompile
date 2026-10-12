/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d4d90; label: FUN_006d4d90
 */

void FUN_006d4d90(void)

{
  undefined1 *puVar1;
  int in_ECX;
  int iVar2;
  
  puVar1 = (undefined1 *)(in_ECX + 0x67f2);
  iVar2 = 0x20;
  do {
    puVar1[-2] = 0;
    *puVar1 = 0xff;
    puVar1[-1] = 0xff;
    *(undefined2 *)(puVar1 + 2) = 0;
    puVar1 = puVar1 + 6;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(in_ECX + 0x67e4) = 0;
  return;
}

