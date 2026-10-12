/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d2d10; label: FUN_005d2d10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d2d10(int *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *param_1;
  if (iVar8 == 0) {
    return;
  }
  if ((*(ushort *)(iVar8 + 0x1b8) & DAT_009736e4) == 0) {
    return;
  }
  iVar3 = param_1[0x37];
  if ((DAT_0096e534 & *(uint *)(iVar8 + 300)) != 0) {
    iVar6 = 0;
    do {
      if ((DAT_0096e534 & 1 << ((byte)iVar6 & 0x1f) & *(uint *)(iVar8 + 300)) != 0) {
        param_1[1] = *(int *)(iVar8 + 0xa8 + iVar6 * 4);
        param_1[0x36] = 0;
        param_1[0x33] = 0;
        param_1[0x22] = 0;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
  }
  if ((DAT_0096d8f4 & *(uint *)(iVar8 + 0x128)) != 0) {
    iVar6 = 0;
    do {
      if ((DAT_0096d8f4 & 1 << ((byte)iVar6 & 0x1f) & *(uint *)(iVar8 + 0x128)) != 0) {
        param_1[1] = *(int *)(iVar8 + 0x28 + iVar6 * 4);
        param_1[0x36] = 0;
        param_1[0x33] = 0;
        param_1[0x22] = 0;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
  }
  if (param_1[0x36] != 0) {
    param_1[0x36] = param_1[0x36] - _DAT_00963f50;
  }
  if (param_1[0x36] < 1) {
switchD_005d2e10_caseD_5:
    iVar6 = param_1[1];
    switch(*(undefined2 *)(iVar8 + 0x1ba + iVar6 * 2)) {
    case 0:
      goto switchD_005d2e10_caseD_0;
    case 1:
      iVar6 = FUN_005b9e90(&DAT_0096e56c);
      iVar6 = iVar6 % (int)*(short *)(iVar8 + 0x1bc + param_1[1] * 2);
      param_1[0x39] = iVar6;
      *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_1[0x38] + iVar6 * 2);
      *(uint *)(iVar3 + 0xb8) = *(ushort *)(param_1[0x38] + param_1[0x39] * 2) & 0x7fff;
      param_1[1] = param_1[1] + 2;
      param_1[0x36] = param_1[0x36] + param_1[0x34];
      goto LAB_005d3066;
    case 2:
      iVar6 = param_1[1];
      iVar5 = (int)*(short *)(iVar8 + 0x1bc + iVar6 * 2) + param_1[0x39];
      iVar7 = (int)*(short *)(iVar8 + 0x1be + iVar6 * 2);
      iVar4 = iVar7;
      if (iVar7 <= iVar5) {
        iVar4 = iVar5;
      }
      iVar8 = (int)*(short *)(iVar8 + 0x1c0 + iVar6 * 2);
      if ((iVar4 <= iVar8) && (iVar8 = iVar7, iVar7 <= iVar5)) {
        iVar8 = iVar5;
      }
      param_1[0x39] = iVar8;
      *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_1[0x38] + iVar8 * 2);
      *(uint *)(iVar3 + 0xb8) = *(ushort *)(param_1[0x38] + param_1[0x39] * 2) & 0x7fff;
      param_1[1] = param_1[1] + 4;
      goto LAB_005d305a;
    case 3:
      sVar1 = *(short *)(iVar8 + 0x1be + param_1[1] * 2);
      sVar2 = *(short *)(iVar8 + 0x1bc + param_1[1] * 2);
      iVar6 = param_1[1];
      iVar4 = FUN_005b9e90(&DAT_0096e56c);
      iVar5 = (int)*(short *)(iVar8 + 0x1c0 + iVar6 * 2);
      iVar7 = param_1[0x39] +
              iVar4 % (((int)sVar1 - (int)sVar2) + 1) + (int)*(short *)(iVar8 + 0x1bc + iVar6 * 2);
      iVar4 = iVar5;
      if (iVar5 <= iVar7) {
        iVar4 = iVar7;
      }
      iVar8 = (int)*(short *)(iVar8 + 0x1c2 + iVar6 * 2);
      if ((iVar4 <= iVar8) && (iVar8 = iVar5, iVar5 <= iVar7)) {
        iVar8 = iVar7;
      }
      param_1[0x39] = iVar8;
      *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_1[0x38] + iVar8 * 2);
      *(uint *)(iVar3 + 0xb8) = *(ushort *)(param_1[0x38] + param_1[0x39] * 2) & 0x7fff;
      param_1[1] = param_1[1] + 5;
      param_1[0x36] = param_1[0x36] + param_1[0x34];
      goto LAB_005d3066;
    case 4:
      iVar3 = param_1[1];
      param_1[0x36] = param_1[0x36] + (int)*(short *)(iVar8 + 0x1bc + iVar3 * 2);
      if (*(short *)(iVar8 + 0x1be + iVar3 * 2) != 0) {
        iVar6 = FUN_005b9e90(&DAT_0096e56c);
        param_1[0x36] = param_1[0x36] + iVar6 % (int)*(short *)(iVar8 + 0x1be + iVar3 * 2);
      }
      param_1[1] = iVar3 + 3;
      goto switchD_005d2e10_caseD_10;
    default:
      goto switchD_005d2e10_caseD_5;
    case 7:
      param_1[0x34] = (int)*(short *)(iVar8 + 0x1bc + iVar6 * 2);
      param_1[0x35] = (int)*(short *)(iVar8 + 0x1be + iVar6 * 2);
      param_1[1] = iVar6 + 3;
      goto switchD_005d2e10_caseD_5;
    case 9:
      param_1[1] = (int)*(short *)(iVar8 + 0x1bc + iVar6 * 2);
      goto switchD_005d2e10_caseD_5;
    case 10:
      if (0xf < param_1[0x33]) {
        FUN_005c12e0(iVar6);
      }
      param_1[param_1[0x33] + 0x23] = param_1[1] + 2;
      param_1[0x33] = param_1[0x33] + 1;
      param_1[1] = (int)*(short *)(iVar8 + 0x1bc + param_1[1] * 2);
      goto switchD_005d2e10_caseD_5;
    case 0xb:
      iVar4 = FUN_005d1d00((int)*(short *)(iVar8 + 0x1bc + iVar6 * 2));
      if (iVar4 == 0) {
        param_1[1] = iVar6 + 4;
      }
      else {
        param_1[1] = (int)*(short *)(iVar8 + 0x1c0 + iVar6 * 2);
      }
      goto switchD_005d2e10_caseD_5;
    case 0xc:
      if (param_1[0x33] == 0) {
        FUN_005c12e0(iVar6);
      }
      param_1[0x33] = param_1[0x33] + -1;
      param_1[1] = param_1[param_1[0x33] + 0x23];
      goto switchD_005d2e10_caseD_5;
    case 0xd:
      if (0xf < param_1[0x22]) {
        FUN_005c12e0(iVar6);
      }
      param_1[param_1[0x22] + 2] = (int)*(short *)(iVar8 + 0x1bc + param_1[1] * 2);
      if (*(short *)(iVar8 + 0x1be + param_1[1] * 2) != 0) {
        iVar6 = param_1[0x22];
        iVar4 = FUN_005b9e90(&DAT_0096e56c);
        param_1[iVar6 + 2] =
             param_1[iVar6 + 2] + iVar4 % (int)*(short *)(iVar8 + 0x1be + param_1[1] * 2);
      }
      param_1[1] = param_1[1] + 3;
      param_1[param_1[0x22] + 0x12] = param_1[1];
      param_1[0x22] = param_1[0x22] + 1;
      goto switchD_005d2e10_caseD_5;
    case 0xe:
      if (param_1[0x22] == 0) {
        FUN_005c12e0(iVar6);
      }
      iVar4 = param_1[0x22];
      if (param_1[iVar4 + 1] == 0) {
        param_1[1] = param_1[1] + 1;
        param_1[0x22] = iVar4 + -1;
        goto switchD_005d2e10_caseD_5;
      }
      break;
    case 0xf:
      if (param_1[0x22] == 0) {
        FUN_005c12e0(iVar6);
      }
      iVar6 = param_1[1];
      iVar4 = FUN_005d1d00((int)*(short *)(iVar8 + 0x1bc + iVar6 * 2));
      if ((iVar4 != 0) || (iVar4 = param_1[0x22], param_1[iVar4 + 1] == 0)) {
        param_1[0x22] = param_1[0x22] + -1;
        param_1[1] = iVar6 + 3;
        goto switchD_005d2e10_caseD_5;
      }
      break;
    case 0x10:
      goto switchD_005d2e10_caseD_10;
    case 0x11:
      goto switchD_005d2e10_caseD_11;
    }
    param_1[1] = param_1[iVar4 + 0x11];
    param_1[iVar4 + 1] = param_1[iVar4 + 1] + -1;
    goto switchD_005d2e10_caseD_5;
  }
switchD_005d2e10_caseD_10:
  if (param_1[0x36] < 0) {
    param_1[0x36] = 0;
  }
  return;
switchD_005d2e10_caseD_11:
  FUN_005d2c70((int)*(short *)(iVar8 + 0x1bc + iVar6 * 2),param_1);
  param_1[1] = param_1[1] + 2;
  goto switchD_005d2e10_caseD_5;
switchD_005d2e10_caseD_0:
  iVar8 = (int)*(short *)(iVar8 + 0x1bc + param_1[1] * 2);
  param_1[0x39] = iVar8;
  *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_1[0x38] + iVar8 * 2);
  *(uint *)(iVar3 + 0xb8) = *(ushort *)(param_1[0x38] + param_1[0x39] * 2) & 0x7fff;
  param_1[1] = param_1[1] + 2;
LAB_005d305a:
  param_1[0x36] = param_1[0x36] + param_1[0x34];
LAB_005d3066:
  if (param_1[0x35] != 0) {
    iVar8 = FUN_005b9e90(&DAT_0096e56c);
    param_1[0x36] = param_1[0x36] + iVar8 % param_1[0x35];
  }
  goto switchD_005d2e10_caseD_10;
}

