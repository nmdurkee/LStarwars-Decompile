/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x4945c0; label: FUN_004945c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004945c0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  _sprintf(local_104,"%s: %i/%i",*(undefined4 *)(DAT_00926c20 + DAT_008808f8 * 4),(uint)DAT_00876571
           ,10);
  _DAT_008009a8 = *(undefined4 *)(param_1 + 0x90);
  FUN_00574de0(param_1,local_104);
  FUN_004f1f10(local_104,*(undefined4 *)(DAT_00926c20 + DAT_0088091c * 4));
  FUN_004f1e80(local_104,&DAT_00759700);
  if (DAT_00876572 == '\0') {
    uVar1 = *(undefined4 *)(DAT_00926c20 + DAT_0088085c * 4);
  }
  else {
    uVar1 = *(undefined4 *)(DAT_00926c20 + DAT_00880858 * 4);
  }
  FUN_004f1e80(local_104,uVar1);
  _DAT_008009a8 = *(undefined4 *)(param_1 + 0x90);
  FUN_00574de0(param_1,local_104);
  uVar2 = 0xd;
  pbVar4 = &DAT_008668cc;
  pbVar5 = (byte *)&DAT_0087656c;
  do {
    if (*(int *)pbVar5 != *(int *)pbVar4) goto LAB_004946ca;
    uVar2 = uVar2 - 4;
    pbVar4 = pbVar4 + 4;
    pbVar5 = pbVar5 + 4;
  } while (3 < uVar2);
  if (uVar2 == 0) {
LAB_00494727:
    iVar3 = 0;
  }
  else {
LAB_004946ca:
    iVar6 = (uint)*pbVar5 - (uint)*pbVar4;
    if (iVar6 == 0) {
      if (uVar2 == 1) goto LAB_00494727;
      iVar6 = (uint)pbVar5[1] - (uint)pbVar4[1];
      if (iVar6 == 0) {
        if (uVar2 == 2) goto LAB_00494727;
        iVar6 = (uint)pbVar5[2] - (uint)pbVar4[2];
        if (iVar6 == 0) {
          if ((uVar2 == 3) || (iVar6 = (uint)pbVar5[3] - (uint)pbVar4[3], iVar6 == 0))
          goto LAB_00494727;
        }
      }
    }
    iVar3 = 1;
    if (iVar6 < 1) {
      iVar3 = -1;
    }
  }
  if ((int)*(short *)(param_1 + 10) == *(int *)(param_1 + 0x8c)) {
LAB_00494754:
    if (iVar3 == 0) goto LAB_00494770;
    uVar1 = *(undefined4 *)(DAT_00926c20 + DAT_00880864 * 4);
  }
  else {
    if (iVar3 != 0) {
      if (DAT_009213e4 != 0) {
        local_104[0] = '\0';
        goto LAB_0049478e;
      }
      goto LAB_00494754;
    }
LAB_00494770:
    uVar1 = *(undefined4 *)(DAT_00926c20 + DAT_0088086c * 4);
  }
  FUN_004f1f10(local_104,uVar1);
LAB_0049478e:
  _DAT_008009a8 = *(undefined4 *)(param_1 + 0x90);
  FUN_00574de0(param_1,local_104);
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

