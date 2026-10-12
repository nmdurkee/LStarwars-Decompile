/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d4b00; label: FUN_004d4b00
 */

void FUN_004d4b00(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 local_40 [52];
  float local_c;
  
  iVar5 = param_1;
  if (param_1 != 0) {
    if (DAT_007ffaf4 == 0) {
      for (iVar5 = FUN_004f1440(param_1 + 0x77d8); iVar5 != 0;
          iVar5 = FUN_004f1460(param_1 + 0x77d8,iVar5)) {
        if (*(char *)(*(int *)(iVar5 + 8) + 0x139) == '\0') {
          FUN_005526c0(*(int *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),local_40,1);
          local_c = *(float *)(*(int *)(iVar5 + 8) + 0x24) + local_c;
          FUN_005f33b0(param_1 + 0x5000 + *(char *)(iVar5 + 0x10) * 0xc,local_40);
        }
      }
    }
    else {
      uVar7 = 0;
      iVar6 = 0;
      param_1 = 0;
      if (0 < *(int *)(*(int *)(PTR_DAT_00802c54 + 0x13c) + 0x74)) {
        do {
          param_1 = uVar7;
          if (0x1f < iVar6) break;
          if (*(char *)(iVar6 + *(int *)(PTR_DAT_00802c54 + 0x2a94)) != '\0') {
            uVar7 = uVar7 | 1 << ((byte)iVar6 & 0x1f);
          }
          iVar6 = iVar6 + 1;
          param_1 = uVar7;
        } while (iVar6 < *(int *)(*(int *)(PTR_DAT_00802c54 + 0x13c) + 0x74));
      }
      iVar6 = iVar5 + 0x77d8;
      iVar3 = FUN_004f1440(iVar6);
      if (iVar3 != 0) {
        do {
          iVar2 = *(int *)(iVar3 + 8);
          iVar4 = FUN_006e6b90();
          if (iVar4 < 0x100) {
            bVar1 = *(byte *)(iVar2 + 0x38 + iVar4);
            if (bVar1 == 0xff) {
              uVar7 = 0xffffffff;
            }
            else {
              uVar7 = 1 << (bVar1 & 0x1f);
            }
            bVar1 = *(byte *)(iVar2 + 0x39 + iVar4);
            if (((bVar1 == 0xff) || (uVar7 = uVar7 | 1 << (bVar1 & 0x1f), uVar7 == 0xffffffff)) ||
               ((param_1 & uVar7) != 0)) {
              FUN_005526c0(iVar2,*(undefined4 *)(iVar3 + 0xc),local_40,1);
              local_c = *(float *)(*(int *)(iVar3 + 8) + 0x24) + local_c;
              FUN_005f33b0(iVar5 + 0x5000 + *(char *)(iVar3 + 0x10) * 0xc,local_40);
            }
          }
          iVar3 = FUN_004f1460(iVar6,iVar3);
        } while (iVar3 != 0);
        return;
      }
    }
  }
  return;
}

