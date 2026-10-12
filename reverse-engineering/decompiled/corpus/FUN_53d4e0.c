/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53d4e0; label: FUN_0053d4e0
 */

void FUN_0053d4e0(void *param_1,size_t param_2)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = (int)*(char *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 4));
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
    _memset(param_1,0,param_2);
    FUN_004ef660(param_1,*(int *)(in_ECX + 8) + *(int *)(in_ECX + 4),iVar1);
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
  }
  return;
}

