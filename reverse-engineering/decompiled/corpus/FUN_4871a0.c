/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x4871a0; label: FUN_004871a0
 */

void FUN_004871a0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x113);
  if ((iVar2 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) != 0)) {
    iVar1 = iVar2 * 0x40 + 0x834 + param_1;
    *param_2 = *(undefined4 *)(iVar2 * 0x40 + 0x834 + param_1);
    param_2[1] = *(undefined4 *)(iVar1 + 4);
    param_2[2] = *(undefined4 *)(iVar1 + 8);
    return;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x5c);
  param_2[1] = *(undefined4 *)(param_1 + 0x194);
  param_2[2] = *(undefined4 *)(param_1 + 100);
  return;
}

