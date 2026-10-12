/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f9570; label: FUN_004f9570
 */

void FUN_004f9570(size_t param_1,int param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  if (param_2 == 0) {
    uVar6 = 0;
  }
  else {
    bVar2 = 0x20 - (char)param_2;
    uVar5 = DAT_0297e024 >> (bVar2 & 0x1f);
    FUN_004f5d00(param_2);
    if (uVar5 != 0) {
      iVar7 = 0;
      iVar3 = iVar7;
      if (0 < (int)uVar5) {
        do {
          uVar4 = DAT_0297e024 >> 0x1d;
          if (uVar4 == 7) {
            uVar1 = 0x10000000;
            if ((DAT_0297e024 & 0x10000000) != 0) {
              uVar4 = 7;
              do {
                uVar1 = uVar1 >> 1;
                uVar4 = uVar4 + 1;
              } while ((uVar1 & DAT_0297e024) != 0);
              goto LAB_004f961c;
            }
LAB_004f9623:
            iVar7 = uVar4 - 3;
          }
          else {
LAB_004f961c:
            iVar7 = 3;
            if (6 < (int)uVar4) goto LAB_004f9623;
          }
          FUN_004f5d00(iVar7);
          (&DAT_0091ce68)[iVar3] = (char)uVar4;
          iVar7 = iVar3 + 1;
          if (iVar7 == param_3) {
            uVar4 = DAT_0297e024 >> 0x1e;
            FUN_004f5d00(2);
            if (-1 < (int)(uVar4 - 1)) {
              _memset(&DAT_0091ce69 + iVar3,0,uVar4);
              iVar7 = iVar7 + uVar4;
            }
          }
          iVar3 = iVar7;
        } while (iVar7 < (int)uVar5);
      }
      if (iVar7 < (int)param_1) {
        _memset(&DAT_0091ce68 + iVar7,0,param_1 - iVar7);
      }
      FUN_004f6000(param_1,&DAT_0091ce68,8,&DAT_008cf398);
      return;
    }
    uVar6 = (undefined2)(DAT_0297e024 >> (bVar2 & 0x1f));
    FUN_004f5d00(param_2);
  }
  if (0 < (int)param_1) {
    _memset(&DAT_0091ce68,0,param_1);
  }
  puVar8 = &DAT_008cf398;
  for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = CONCAT22(uVar6,uVar6);
    puVar8 = puVar8 + 1;
  }
  return;
}

