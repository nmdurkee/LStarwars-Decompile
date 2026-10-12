/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x696f10; label: FUN_00696f10
 */

void FUN_00696f10(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  param_2 = param_2 * 0x40c;
  *(undefined1 *)(param_2 + 0x404 + *(int *)(in_ECX + 0xd0c)) = 1;
  FUN_004f1f10(param_2 + 4 + *(int *)(in_ECX + 0xd0c),param_1);
  iVar2 = param_2 + 4 + *(int *)(in_ECX + 0xd0c);
  FUN_004f8c60(iVar2,iVar2);
  iVar2 = FUN_004f1ff0(param_1);
  if (((2 < iVar2) &&
      (iVar1 = param_2 + iVar2 + *(int *)(in_ECX + 0xd0c),
      *(char *)(param_2 + iVar2 + 3 + *(int *)(in_ECX + 0xd0c)) == 'l')) &&
     (*(char *)(iVar1 + 2) == '_')) {
    *(undefined1 *)(iVar1 + 2) = 0;
  }
  FUN_004f1e80(param_2 + 4 + *(int *)(in_ECX + 0xd0c),PTR_DAT_00810d90);
  return;
}

