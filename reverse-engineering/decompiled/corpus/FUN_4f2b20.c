/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f2b20; label: FUN_004f2b20
 */

void FUN_004f2b20(int param_1,short *param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  short local_48 [34];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_48;
  psVar2 = local_48;
  if (param_1 < 0) {
    param_1 = -param_1;
    *param_2 = 0x2d;
    param_2 = param_2 + 1;
  }
  do {
    iVar1 = param_1 / param_3;
    psVar3 = psVar2 + 1;
    *psVar2 = (short)(param_1 % param_3) + 0x30;
    param_1 = iVar1;
    psVar2 = psVar3;
  } while (iVar1 != 0);
  if (psVar3 != local_48) {
    do {
      psVar2 = psVar3 + -1;
      psVar3 = psVar3 + -1;
      *param_2 = *psVar2;
      param_2 = param_2 + 1;
    } while (psVar3 != local_48);
  }
  *param_2 = 0;
  __security_check_cookie(local_4 ^ (uint)local_48);
  return;
}

