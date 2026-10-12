/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f3650; label: FUN_004f3650
 */

void FUN_004f3650(undefined2 *param_1,undefined2 *param_2,short *param_3)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  undefined1 local_208 [4];
  undefined1 local_204 [512];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_208;
  iVar5 = 0;
  if (param_2 != param_1) {
    FUN_004f2280(param_1,param_2);
  }
  FUN_004f26e0(local_204,param_1);
  iVar3 = *DAT_0091eef8;
  piVar1 = DAT_0091eef8;
  while (iVar3 != 0) {
    psVar4 = (short *)*piVar1;
    sVar2 = *psVar4;
    if (sVar2 == 0x21) {
      psVar4 = psVar4 + 1;
    }
    iVar3 = FUN_004f34f0(local_204,psVar4,local_208,sVar2 == 0x21);
    if (iVar3 != 0) {
      if (param_3 == (short *)0x0) {
        *param_1 = 0;
      }
      else {
        psVar4 = param_3;
        do {
          *(short *)(((int)param_1 - (int)param_3) + (int)psVar4) = *psVar4;
          sVar2 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar2 != 0);
      }
    }
    iVar5 = iVar5 + 1;
    piVar1 = DAT_0091eef8 + iVar5;
    iVar3 = DAT_0091eef8[iVar5];
  }
  __security_check_cookie(local_4 ^ (uint)local_208);
  return;
}

