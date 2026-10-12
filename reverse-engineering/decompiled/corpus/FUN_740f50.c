/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x740f50; label: FUN_00740f50
 */

void FUN_00740f50(int param_1,int param_2)

{
  int iVar1;
  char *in_ECX;
  
  *in_ECX = '\0';
  in_ECX[4] = '\0';
  in_ECX[5] = '\0';
  in_ECX[6] = '\0';
  in_ECX[7] = '\0';
  in_ECX[0xc] = '\0';
  in_ECX[0xd] = '\0';
  in_ECX[0xe] = '\0';
  in_ECX[0xf] = '\0';
  in_ECX[8] = '\0';
  in_ECX[9] = '\0';
  in_ECX[10] = '\0';
  in_ECX[0xb] = '\0';
  iVar1 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar1 + param_2;
  if ((*in_ECX != '\0') && (*(void **)(in_ECX + 0xc) != (void *)0x0)) {
    _free(*(void **)(in_ECX + 0xc));
  }
  *(int *)(in_ECX + 4) = iVar1;
  *(int *)(in_ECX + 0xc) = iVar1;
  *(int *)(in_ECX + 8) = iVar1 + param_2;
  *in_ECX = '\0';
  return;
}

