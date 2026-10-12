/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f9aa0; label: FUN_004f9aa0
 */

void FUN_004f9aa0(int param_1,char *param_2)

{
  short *psVar1;
  char *pcVar2;
  undefined1 *puVar3;
  char cVar4;
  int iVar5;
  int local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  local_108 = param_1;
  if (*param_2 == '@') {
    param_2 = param_2 + 4;
  }
  pcVar2 = local_104;
  if ((param_2 != (char *)0x0) && (cVar4 = *param_2, cVar4 != '\0')) {
    do {
      *pcVar2 = cVar4;
      cVar4 = pcVar2[(int)(param_2 + (1 - (int)local_104))];
      pcVar2 = pcVar2 + 1;
    } while (cVar4 != '\0');
  }
  *pcVar2 = '\0';
  FUN_004efdf0(0,local_104);
  pcVar2 = local_104;
  if (*(short **)(param_1 + 0x10) == (short *)0x0) {
    FUN_004f76f0(param_1,pcVar2);
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  }
  iVar5 = (int)**(short **)(param_1 + 0x10);
  puVar3 = (undefined1 *)FUN_004f20a0(local_104,&DAT_0075a204);
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 0;
  }
  do {
    psVar1 = (short *)(*(int *)(param_1 + 0x10) + iVar5 * 8);
    iVar5 = FUN_004f8b10(*(undefined4 *)(*(int *)(param_1 + 0x10) + 4 + iVar5 * 8),pcVar2);
    if (iVar5 == 0) {
      if (puVar3 == (undefined1 *)0x0) break;
      iVar5 = (int)*psVar1;
      pcVar2 = puVar3 + 1;
      puVar3 = (undefined1 *)FUN_004f20a0(pcVar2,&DAT_0075a204);
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 0;
      }
    }
    else {
      iVar5 = (int)psVar1[1];
    }
    param_1 = local_108;
  } while (iVar5 != 0);
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

