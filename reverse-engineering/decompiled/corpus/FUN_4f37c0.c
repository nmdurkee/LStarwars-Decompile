/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f37c0; label: FUN_004f37c0
 */

void FUN_004f37c0(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined1 auStack_88 [126];
  undefined2 local_a;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_88;
  local_a = 0;
  pbVar9 = (byte *)(param_1 + 0x13);
  uVar2 = (uint)*(byte *)(param_1 + 0x12) * 4 + 2;
LAB_004f3802:
  while( true ) {
    uVar8 = uVar2 * 2;
    uVar3 = (uVar2 & 0x7fffffff) >> 7 & 1;
    pbVar10 = pbVar9;
    if (uVar3 != 0) break;
    *param_2 = *pbVar9;
    uVar8 = uVar2 * 4;
    pbVar10 = pbVar9 + 1;
    param_2 = param_2 + 1;
    uVar3 = (uVar2 & 0x3fffffff) >> 6 & 1;
    uVar2 = uVar8;
    if (uVar3 != 0) break;
LAB_004f383c:
    pbVar9 = pbVar10 + 1;
    *param_2 = *pbVar10;
    param_2 = param_2 + 1;
  }
  uVar2 = uVar8 & 0xff;
  if (uVar2 == 0) {
    uVar2 = uVar3 + (uint)*pbVar10 * 2;
    pbVar10 = pbVar10 + 1;
    if ((uVar2 & 0x100) == 0) goto LAB_004f383c;
  }
  uVar3 = 0;
  uVar4 = uVar2 >> 7 & 1;
  uVar2 = uVar2 * 2 & 0xff;
  uVar8 = 2;
  if (uVar2 == 0) {
    uVar2 = uVar4 + (uint)*pbVar10 * 2;
    uVar4 = uVar2 >> 8;
    pbVar10 = pbVar10 + 1;
  }
  if (uVar4 == 0) {
    uVar4 = uVar2 >> 7 & 1;
    uVar2 = uVar2 * 2 & 0xff;
    pbVar9 = pbVar10;
    if (uVar2 == 0) {
      uVar2 = uVar4 + (uint)*pbVar10 * 2;
      uVar4 = uVar2 >> 8;
      pbVar9 = pbVar10 + 1;
    }
    uVar8 = uVar4 + 4;
    uVar5 = uVar2 >> 7 & 1;
    uVar2 = uVar2 * 2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = uVar5 + (uint)*pbVar9 * 2;
      uVar5 = uVar2 >> 8;
      pbVar9 = pbVar9 + 1;
    }
    if (uVar5 == 0) goto LAB_004f3a01;
    uVar8 = uVar2 >> 7 & 1;
    uVar2 = uVar2 * 2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = uVar8 + (uint)*pbVar9 * 2;
      uVar8 = uVar2 >> 8;
      pbVar9 = pbVar9 + 1;
    }
    uVar8 = uVar8 + (uVar4 + 3) * 2;
    if (uVar8 == 9) {
      iVar7 = 3;
      do {
        uVar8 = uVar2 >> 7 & 1;
        uVar2 = uVar2 * 2 & 0xff;
        if (uVar2 == 0) {
          uVar2 = uVar8 + (uint)*pbVar9 * 2;
          uVar8 = uVar2 >> 8;
          pbVar9 = pbVar9 + 1;
        }
        iVar7 = iVar7 + -1;
        uVar3 = uVar8 + uVar3 * 2;
      } while (-1 < iVar7);
      iVar7 = uVar3 + 2;
      do {
        bVar1 = pbVar9[1];
        *param_2 = *pbVar9;
        param_2[1] = bVar1;
        bVar1 = pbVar9[3];
        param_2[2] = pbVar9[2];
        param_2[3] = bVar1;
        iVar7 = iVar7 + -1;
        pbVar9 = pbVar9 + 4;
        param_2 = param_2 + 4;
      } while (-1 < iVar7);
      goto LAB_004f3802;
    }
  }
  else {
    uVar4 = uVar2 >> 7 & 1;
    uVar2 = uVar2 * 2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = uVar4 + (uint)*pbVar10 * 2;
      uVar4 = uVar2 >> 8;
      pbVar10 = pbVar10 + 1;
    }
    if (uVar4 == 0) {
LAB_004f3afe:
      bVar1 = *pbVar10;
      pbVar6 = param_2 + -(bVar1 | uVar3);
      pbVar9 = pbVar10 + 1;
      pbVar10 = pbVar6 + -1;
      if ((uVar8 & 1) != 0) {
        *param_2 = pbVar6[-1];
        param_2 = param_2 + 1;
        pbVar10 = pbVar6;
      }
      iVar7 = (uVar8 >> 1) - 1;
      if ((bVar1 | uVar3) == 0) {
        bVar1 = *pbVar10;
        do {
          *param_2 = bVar1;
          iVar7 = iVar7 + -1;
          param_2[1] = bVar1;
          param_2 = param_2 + 2;
        } while (-1 < iVar7);
      }
      else {
        do {
          bVar1 = *pbVar10;
          param_2[1] = pbVar10[1];
          *param_2 = bVar1;
          iVar7 = iVar7 + -1;
          pbVar10 = pbVar10 + 2;
          param_2 = param_2 + 2;
        } while (-1 < iVar7);
      }
      goto LAB_004f3802;
    }
    uVar4 = uVar2 >> 7 & 1;
    uVar2 = uVar2 * 2 & 0xff;
    uVar8 = 3;
    if (uVar2 == 0) {
      uVar2 = uVar4 + (uint)*pbVar10 * 2;
      uVar4 = uVar2 >> 8;
      pbVar10 = pbVar10 + 1;
    }
    pbVar9 = pbVar10;
    if (uVar4 != 0) {
      pbVar9 = pbVar10 + 1;
      if (*pbVar10 != 0) {
        uVar8 = *pbVar10 + 8;
        goto LAB_004f3a01;
      }
      uVar8 = uVar2 >> 7 & 1;
      uVar2 = uVar2 * 2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = uVar8 + (uint)*pbVar9 * 2;
        uVar8 = uVar2 >> 8;
        pbVar9 = pbVar10 + 2;
      }
      if (uVar8 == 0) {
        __security_check_cookie(local_4 ^ (uint)auStack_88);
        return;
      }
      goto LAB_004f3802;
    }
  }
LAB_004f3a01:
  uVar4 = uVar2 >> 7 & 1;
  uVar2 = uVar2 * 2 & 0xff;
  pbVar10 = pbVar9;
  if (uVar2 == 0) {
    uVar2 = uVar4 + (uint)*pbVar9 * 2;
    uVar4 = uVar2 >> 8;
    pbVar10 = pbVar9 + 1;
  }
  if (uVar4 != 0) {
    uVar3 = uVar2 >> 7 & 1;
    uVar2 = uVar2 * 2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = uVar3 + (uint)*pbVar10 * 2;
      uVar3 = uVar2 >> 8;
      pbVar10 = pbVar10 + 1;
    }
    uVar4 = uVar2 >> 7 & 1;
    uVar2 = uVar2 * 2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = uVar4 + (uint)*pbVar10 * 2;
      uVar4 = uVar2 >> 8;
      pbVar10 = pbVar10 + 1;
    }
    if (uVar4 == 0) {
      if (uVar3 == 0) {
        uVar3 = 1;
        goto LAB_004f3ad0;
      }
    }
    else {
      uVar4 = uVar2 >> 7 & 1;
      uVar2 = uVar2 * 2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = uVar4 + (uint)*pbVar10 * 2;
        uVar4 = uVar2 >> 8;
        pbVar10 = pbVar10 + 1;
      }
      uVar3 = uVar4 + uVar3 * 2 | 4;
      uVar4 = uVar2 >> 7 & 1;
      uVar2 = uVar2 * 2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = uVar4 + (uint)*pbVar10 * 2;
        uVar4 = uVar2 >> 8;
        pbVar10 = pbVar10 + 1;
      }
      if (uVar4 == 0) {
LAB_004f3ad0:
        uVar4 = uVar2 >> 7 & 1;
        uVar2 = uVar2 * 2 & 0xff;
        if (uVar2 == 0) {
          uVar2 = uVar4 + (uint)*pbVar10 * 2;
          uVar4 = uVar2 >> 8;
          pbVar10 = pbVar10 + 1;
        }
        uVar3 = uVar4 + uVar3 * 2;
      }
    }
    uVar3 = uVar3 << 8;
  }
  goto LAB_004f3afe;
}

