/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c2730; label: FUN_004c2730
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c2730(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  
  iVar2 = param_2 * 0x74 + param_1;
  switch(*(undefined1 *)(iVar2 + 0x62)) {
  case 0:
    uVar1 = *(ushort *)(iVar2 + 0x60);
    if (*(char *)(iVar2 + 99) == '\x01') {
      return 1;
    }
    if (*(uint *)(iVar2 + 100) == 0) {
      return 1;
    }
    if (*(uint *)(iVar2 + 100) <= DAT_0086e4dc) {
      FUN_0055c820(DAT_0093b304);
      iVar2 = FUN_00576480((int)(short)(&DAT_007fcb18)[uVar1]);
      if (iVar2 != 0) {
        *(byte *)(iVar2 + 2) = *(byte *)(iVar2 + 2) | 2;
      }
LAB_004c27d2:
      FUN_004c2660(param_1,param_2,1);
      return 1;
    }
    break;
  case 1:
    if (*(char *)(iVar2 + 99) == '\x01') {
      return 0;
    }
    uVar1 = *(ushort *)(iVar2 + 0x60);
    if (DAT_0093b278 <= (int)(uint)uVar1) {
      return 0;
    }
    iVar4 = FUN_004c1050();
    if (iVar4 == 0) {
LAB_004c2777:
      FUN_00547930(0x32,0,0,0);
      _DAT_0087c570 = 0x3fc00000;
      return 0;
    }
    if (*(uint *)(iVar2 + 100) <= DAT_0086e4dc) {
      iVar2 = FUN_00594a90((uint)uVar1);
      if (iVar2 == 0) {
        return 1;
      }
      FUN_0055c820(DAT_0093b2d8);
      goto LAB_004c27d2;
    }
    break;
  case 2:
    uVar1 = *(ushort *)(iVar2 + 0x60);
    if (*(char *)(iVar2 + 99) == '\x01') {
      return 0;
    }
    uVar7 = 1 << ((byte)uVar1 & 0x1f);
    uVar3 = (&DAT_0086e4c8)[(int)(uint)uVar1 >> 5];
    if ((uVar7 & uVar3) != 0) {
      return 0;
    }
    if (((&DAT_007f3da3)[(uint)uVar1 * 0x20] != -1) &&
       ((&DAT_0086e0fa)[(char)(&DAT_007f3da3)[(uint)uVar1 * 0x20] * 0xc] == '\0'))
    goto LAB_004c2777;
    if (*(uint *)(iVar2 + 100) <= DAT_0086e4dc) {
      (&DAT_0086e4c8)[(int)(uint)uVar1 >> 5] = uVar3 | uVar7;
      FUN_0055c820(DAT_0093b300);
      goto LAB_004c27d2;
    }
    break;
  default:
    goto switchD_004c274d_caseD_3;
  case 4:
    if (*(char *)(iVar2 + 99) == '\x01') {
      return 0;
    }
    if (*(uint *)(iVar2 + 100) == 0) {
      return 0;
    }
    if (_DAT_0086e4e8 < (float)(param_2 * 0xe10)) goto LAB_004c2777;
    if (*(uint *)(iVar2 + 100) <= DAT_0086e4dc) {
      FUN_0055c820(DAT_0093b308);
      FUN_0055c8a0();
      goto LAB_004c27d2;
    }
    break;
  case 5:
    iVar2 = FUN_0057e720(param_2);
    if (iVar2 == 0) {
      FUN_00681f40("MenuNoEntry",0);
      _DAT_0087c570 = 0x3fc00000;
      return 0;
    }
    _DAT_0087ff94 = _DAT_0087c55c;
    _DAT_0087c484 = _DAT_0087bf30;
    _DAT_0088000c = DAT_008800a0;
    _DAT_008800fc = DAT_0087c4e0;
    _DAT_008800ac = DAT_008801c0;
    _DAT_00880100 = DAT_0087c4e4;
    _DAT_008800b0 = DAT_008801c4;
    _DAT_00880104 = DAT_0087c4e8;
    _DAT_008800b4 = DAT_008801c8;
    _DAT_0088041c = DAT_008800e0;
    _DAT_0087bf34 = DAT_0087bf8c;
    _DAT_0087c4f8 = DAT_008800f8;
    _DAT_008800f4 = DAT_00880154;
    DAT_0087ffe4 = DAT_008801ac;
    DAT_008800a0 = 0;
    DAT_0087c4e0 = 0;
    DAT_008801c0 = 0;
    DAT_0087c4e4 = 0;
    DAT_008801c4 = 0;
    DAT_0087c4e8 = 0;
    DAT_008801c8 = 0;
    DAT_008800f8 = 0;
    DAT_00880154 = 0;
    DAT_00880474 = 0;
    FUN_004c2660(param_1,param_2,0);
    _DAT_0088048c = 0;
    uVar3 = 0x7e4c;
    _DAT_0085e838 = _DAT_0086e4e8;
    pbVar5 = (byte *)&DAT_008668c8;
    pbVar6 = (byte *)&DAT_00856c18;
    do {
      if (*(int *)pbVar6 != *(int *)pbVar5) goto LAB_004c2a68;
      uVar3 = uVar3 - 4;
      pbVar5 = pbVar5 + 4;
      pbVar6 = pbVar6 + 4;
    } while (3 < uVar3);
    if (uVar3 == 0) {
LAB_004c2ac5:
      iVar4 = 0;
    }
    else {
LAB_004c2a68:
      iVar2 = (uint)*pbVar6 - (uint)*pbVar5;
      if (iVar2 == 0) {
        if (uVar3 == 1) goto LAB_004c2ac5;
        iVar2 = (uint)pbVar6[1] - (uint)pbVar5[1];
        if (iVar2 == 0) {
          if (uVar3 == 2) goto LAB_004c2ac5;
          iVar2 = (uint)pbVar6[2] - (uint)pbVar5[2];
          if (iVar2 == 0) {
            if ((uVar3 == 3) || (iVar2 = (uint)pbVar6[3] - (uint)pbVar5[3], iVar2 == 0))
            goto LAB_004c2ac5;
          }
        }
      }
      iVar4 = 1;
      if (iVar2 < 1) {
        iVar4 = -1;
      }
    }
    if (iVar4 != 0) {
      _DAT_00879b2c = 1;
    }
    FUN_0057e7e0(param_2);
    return 1;
  }
  _DAT_0087b93c = 0x3fc00000;
switchD_004c274d_caseD_3:
  return 0xffffffff;
}

