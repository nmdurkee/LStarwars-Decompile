/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69f540; label: FUN_0069f540
 */

int FUN_0069f540(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  byte *local_10;
  int local_c;
  byte *local_8;
  int local_4;
  
  piVar2 = param_1;
  iVar9 = param_1[2] - param_1[3];
  pbVar8 = (byte *)(*param_1 + param_1[3]);
  if (param_1[5] == 0) {
    if (iVar9 < 0x1b) {
      return 0;
    }
    uVar3 = 4;
    pbVar6 = (byte *)&DAT_0076f438;
    pbVar7 = pbVar8;
    do {
      if (*(int *)pbVar7 != *(int *)pbVar6) goto LAB_0069f598;
      uVar3 = uVar3 - 4;
      pbVar6 = pbVar6 + 4;
      pbVar7 = pbVar7 + 4;
    } while (3 < uVar3);
    if (uVar3 == 0) {
LAB_0069f5f5:
      iVar4 = 0;
    }
    else {
LAB_0069f598:
      iVar10 = (uint)*pbVar7 - (uint)*pbVar6;
      if (iVar10 == 0) {
        if (uVar3 == 1) goto LAB_0069f5f5;
        iVar10 = (uint)pbVar7[1] - (uint)pbVar6[1];
        if (iVar10 == 0) {
          if (uVar3 == 2) goto LAB_0069f5f5;
          iVar10 = (uint)pbVar7[2] - (uint)pbVar6[2];
          if (iVar10 == 0) {
            if ((uVar3 == 3) || (iVar10 = (uint)pbVar7[3] - (uint)pbVar6[3], iVar10 == 0))
            goto LAB_0069f5f5;
          }
        }
      }
      iVar4 = 1;
      if (iVar10 < 1) {
        iVar4 = -1;
      }
    }
    if (iVar4 != 0) goto LAB_0069f706;
    iVar10 = pbVar8[0x1a] + 0x1b;
    if (iVar9 < iVar10) {
      return 0;
    }
    if (pbVar8[0x1a] != 0) {
      iVar4 = 0;
      do {
        param_1[6] = param_1[6] + (uint)pbVar8[iVar4 + 0x1b];
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)pbVar8[0x1a]);
    }
    param_1[5] = iVar10;
  }
  if (iVar9 < param_1[5] + param_1[6]) {
    return 0;
  }
  piVar1 = *(int **)(pbVar8 + 0x16);
  pbVar7 = pbVar8 + 0x16;
  pbVar7[0] = 0;
  pbVar7[1] = 0;
  pbVar7[2] = 0;
  pbVar7[3] = 0;
  local_c = param_1[5];
  local_4 = param_1[6];
  local_8 = pbVar8 + local_c;
  param_1 = piVar1;
  local_10 = pbVar8;
  FUN_0069ef50(&local_10);
  uVar3 = 4;
  pbVar6 = (byte *)&param_1;
  do {
    if (*(int *)pbVar6 != *(int *)pbVar7) goto LAB_0069f69c;
    uVar3 = uVar3 - 4;
    pbVar7 = pbVar7 + 4;
    pbVar6 = pbVar6 + 4;
  } while (3 < uVar3);
  if (uVar3 == 0) {
LAB_0069f6f9:
    iVar4 = 0;
  }
  else {
LAB_0069f69c:
    iVar10 = (uint)*pbVar6 - (uint)*pbVar7;
    if (iVar10 == 0) {
      if (uVar3 == 1) goto LAB_0069f6f9;
      iVar10 = (uint)pbVar6[1] - (uint)pbVar7[1];
      if (iVar10 == 0) {
        if (uVar3 == 2) goto LAB_0069f6f9;
        iVar10 = (uint)pbVar6[2] - (uint)pbVar7[2];
        if (iVar10 == 0) {
          if ((uVar3 == 3) || (iVar10 = (uint)pbVar6[3] - (uint)pbVar7[3], iVar10 == 0))
          goto LAB_0069f6f9;
        }
      }
    }
    iVar4 = 1;
    if (iVar10 < 1) {
      iVar4 = -1;
    }
  }
  if (iVar4 == 0) {
    iVar9 = *piVar2;
    iVar10 = piVar2[3];
    if (param_2 != (int *)0x0) {
      *param_2 = iVar9 + iVar10;
      param_2[1] = piVar2[5];
      param_2[2] = piVar2[5] + iVar9 + iVar10;
      param_2[3] = piVar2[6];
    }
    iVar9 = piVar2[5];
    iVar10 = piVar2[6];
    piVar2[4] = 0;
    piVar2[3] = piVar2[3] + iVar9 + iVar10;
    piVar2[5] = 0;
    piVar2[6] = 0;
    return iVar9 + iVar10;
  }
  *(int **)(pbVar8 + 0x16) = param_1;
LAB_0069f706:
  piVar2[5] = 0;
  piVar2[6] = 0;
  pvVar5 = _memchr(pbVar8 + 1,0x4f,iVar9 - 1);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)(piVar2[2] + *piVar2);
  }
  piVar2[3] = (int)pvVar5 - *piVar2;
  return (int)pbVar8 - (int)pvVar5;
}

