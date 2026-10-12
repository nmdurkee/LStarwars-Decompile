/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x6964d0; label: FUN_006964d0
 */

void FUN_006964d0(int param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 local_208;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_208;
  iVar4 = *(int *)(in_ECX + 0xc);
  local_208 = 0;
  if (0x7ff < iVar4) {
    iVar4 = FUN_00693b60();
  }
  *(int *)(in_ECX + 0xc) = iVar4 + 1;
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 8) + iVar4 * 0x3c;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    piVar1 = (int *)(*(int *)(in_ECX + 0x1c) + 8);
    *piVar1 = *piVar1 + 1;
  }
  _memset(*(void **)(in_ECX + 0x20),0,0x3c);
  *(int *)(*(int *)(in_ECX + 0x20) + 0x18) = *(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x14) * 4;
  *(int *)(*(int *)(in_ECX + 0x20) + 0x14) = param_1;
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x28) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x2c) = 0x3f800000;
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x30) = 0x3f800000;
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x34) = 0x3f800000;
  if (((param_1 == 4) || (param_1 == 8)) || (param_1 == 0x10)) {
    puVar2 = (uint *)(*(int *)(in_ECX + 0x20) + 0x38);
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  else {
    puVar2 = (uint *)(*(int *)(in_ECX + 0x20) + 0x38);
    *puVar2 = *puVar2 | 2;
  }
  FUN_004f7fb0(param_2);
  FUN_004f1f10(local_104,in_ECX + 0x24);
  FUN_004f1e80(local_104,*(undefined4 *)(param_2 + 0x510));
  FUN_00694740(local_204,local_104,"$lang",*(undefined4 *)(in_ECX + 0x1d4));
  iVar4 = FUN_006946b0(local_204);
  if (iVar4 == 0) {
    iVar4 = *(int *)(in_ECX + 300);
    iVar5 = FUN_004f1ff0(local_204);
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + iVar5 + 1;
    FUN_004f1f10(iVar4,local_204);
  }
  **(int **)(in_ECX + 0x20) = iVar4;
  pcVar8 = (char *)**(int **)(in_ECX + 0x20);
  cVar3 = *pcVar8;
  pcVar9 = (char *)0x0;
  pcVar7 = pcVar8;
  if (cVar3 != '\0') {
    do {
      if ((cVar3 == '\\') || (cVar3 == '/')) {
        pcVar9 = pcVar7;
      }
      cVar3 = pcVar7[1];
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    if (pcVar9 != (char *)0x0) {
      pcVar8 = pcVar9 + 1;
    }
  }
  (*(int **)(in_ECX + 0x20))[2] = (int)pcVar8;
  uVar6 = local_208;
  if (*(char *)(in_ECX + 0x124) != '\0') {
    uVar6 = FUN_004f1200(&LAB_00694590);
  }
  FUN_004f1120(param_2,&PTR_s_IDENT_00810c18);
  cVar3 = **(char **)(param_2 + 0x510);
  while ((cVar3 != '\0' && (cVar3 != ';'))) {
    FUN_004f7fb0(param_2);
    FUN_004fa180(param_2);
    cVar3 = **(char **)(param_2 + 0x510);
  }
  FUN_004f11e0(param_2);
  if (*(char *)(in_ECX + 0x124) != '\0') {
    FUN_004f1200(uVar6);
  }
  __security_check_cookie(local_4 ^ (uint)&local_208);
  return;
}

