/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53d4a0; label: FUN_0053d4a0
 */

void FUN_0053d4a0(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = FUN_004f1ff0(param_1);
    puVar2 = (undefined1 *)(*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 4));
    *puVar2 = (char)iVar1;
    FUN_004ef660(puVar2 + 1,param_1,iVar1);
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + iVar1 + 1;
  }
  return;
}

