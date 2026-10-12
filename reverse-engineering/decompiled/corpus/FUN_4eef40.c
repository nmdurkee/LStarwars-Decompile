/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4eef40; label: FUN_004eef40
 */

int * FUN_004eef40(uint param_1,char *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  
  if ((int)param_1 < 1) {
    FUN_004eeda0(param_1,param_2,param_3);
  }
  puVar3 = DAT_0088ab28;
  iVar1 = DAT_0088ab20;
  if (DAT_0088ab28 != (undefined4 *)0x0) {
    *(uint *)*DAT_0088ab28 = *(uint *)*DAT_0088ab28 + 0xf & 0xfffffff0;
    piVar5 = (int *)*puVar3;
    if (param_1 <= (uint)(puVar3[1] - *piVar5)) {
      piVar7 = (int *)*piVar5;
      *piVar5 = *piVar5 + param_1;
      return piVar7;
    }
    FUN_004eeda0(param_1,param_2,param_3);
    return (int *)0x0;
  }
  if (DAT_0088ab20 != 0) {
    piVar5 = (int *)(DAT_0088ab20 + 4);
    uVar6 = param_1 + 0xf & 0xfffffff0;
    if ((int)uVar6 < *piVar5) {
      piVar7 = *(int **)(DAT_0088ab20 + 8);
      *(uint *)(DAT_0088ab20 + 8) = (int)piVar7 + uVar6;
      *(uint *)(iVar1 + 4) = *piVar5 - uVar6;
      return piVar7;
    }
    return (int *)0x0;
  }
  pcVar4 = param_2;
  if (DAT_0088ab2c == 0) {
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    piVar5 = _malloc((size_t)(pcVar4 + param_1 + (0x2d - (int)(param_2 + 1))));
    if (piVar5 != (int *)0x0) {
      pcVar4 = param_2;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      _memset(piVar5,0,(size_t)(pcVar4 + param_1 + (0x2d - (int)(param_2 + 1))));
      goto LAB_004ef02f;
    }
  }
  else {
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    piVar5 = (int *)FUN_004f6740(DAT_0088ab2c,pcVar4 + param_1 + (0x2d - (int)(param_2 + 1)),4);
LAB_004ef02f:
    if (piVar5 != (int *)0x0) {
      pcVar4 = param_2;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      _memset(piVar5,0,(size_t)(pcVar4 + param_1 + (0x2d - (int)(param_2 + 1))));
      DAT_0088ab1c = DAT_0088ab1c + param_1;
      piVar5[4] = param_1;
      piVar5[5] = s_MEMBLKHEADER_00800444._0_4_;
      piVar5[6] = s_MEMBLKHEADER_00800444._4_4_;
      piVar5[7] = s_MEMBLKHEADER_00800444._8_4_;
      *(undefined4 *)((int)piVar5 + param_1 + 0x20) = s_MEMBLKTAIL01_00800454._0_4_;
      *(undefined4 *)((int)piVar5 + param_1 + 0x24) = s_MEMBLKTAIL01_00800454._4_4_;
      *(undefined4 *)((int)piVar5 + param_1 + 0x28) = s_MEMBLKTAIL01_00800454._8_4_;
      iVar1 = (param_1 + 0x2c) - (int)param_2;
      do {
        cVar2 = *param_2;
        param_2[(int)piVar5 + iVar1] = cVar2;
        param_2 = param_2 + 1;
      } while (cVar2 != '\0');
      piVar5[3] = DAT_0088ab24;
      DAT_0088ab24 = DAT_0088ab24 + 1;
      piVar5[2] = param_3;
      *piVar5 = (int)DAT_0088ab18;
      if (DAT_0088ab18 != (int *)0x0) {
        DAT_0088ab18[1] = (int)piVar5;
      }
      piVar5[1] = 0;
      piVar7 = piVar5 + 8;
      DAT_0088ab18 = piVar5;
      goto LAB_004ef0f3;
    }
  }
  piVar7 = (int *)0x0;
  FUN_004eedc0(param_1,param_2,param_3);
  FUN_004eeda0(param_1,param_2,param_3);
LAB_004ef0f3:
  iVar1 = (int)piVar7 + param_1;
  if (DAT_0088ab30 < iVar1) {
    DAT_0088ab30 = iVar1;
  }
  if (DAT_0088ab34 < iVar1) {
    DAT_0088ab34 = iVar1;
  }
  return piVar7;
}

