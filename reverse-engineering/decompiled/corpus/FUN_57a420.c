/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a420; label: FUN_0057a420
 */

void FUN_0057a420(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  DAT_0092b0c8 = 0;
  _sprintf(local_84,"%s.txt",param_1 + 0x80);
  uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x104) = uVar1;
  iVar2 = FUN_004fd5d0(local_84,uVar1,0x10000);
  *(int *)(param_1 + 0x10c) = iVar2;
  if (0 < iVar2) {
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 0x104)) = 0;
    uVar3 = FUN_0054be70(*(undefined4 *)(param_1 + 0x104),&DAT_0092b0c8,1);
    *(undefined4 *)(param_1 + 0x10c) = uVar3;
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

