/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d3800; label: FUN_004d3800
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d3800(float param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  byte *pbVar9;
  undefined4 uVar10;
  float local_8;
  undefined1 local_4;
  
  fVar4 = param_1;
  if (*(void **)((int)param_1 + 0xcc4) == (void *)0x0) {
    return;
  }
  iVar5 = *(int *)(PTR_DAT_00802c54 + 300);
  if ((iVar5 != 0) &&
     (((iVar5 == DAT_0087af84 || (iVar5 == DAT_0087af5c)) || (iVar5 == DAT_0087af78)))) {
    _memset(*(void **)((int)param_1 + 0xcc4),0,0x88);
    return;
  }
  if (0.0 < *(float *)((int)param_1 + 0xd5c)) {
    *(float *)((int)param_1 + 0xd5c) = *(float *)((int)param_1 + 0xd5c) - _DAT_00925018;
  }
  if (((PTR_DAT_00802c54 == (undefined *)0x0) || (*(int *)(PTR_DAT_00802c54 + 300) == 0)) ||
     (((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 4) == 0 ||
      (iVar5 = FUN_00580070(0x10,0,param_1), iVar5 == 0)))) {
    iVar5 = FUN_00580070(0xf,0,fVar4);
    if (iVar5 == 0) {
      pbVar9 = (byte *)(*(int *)((int)fVar4 + 0xcc4) + 1);
      *pbVar9 = *pbVar9 & 0xfd;
    }
    else {
      pbVar9 = (byte *)(*(int *)((int)fVar4 + 0xcc4) + 1);
      *pbVar9 = *pbVar9 | 2;
    }
  }
  else {
    pbVar9 = (byte *)(*(int *)((int)fVar4 + 0xcc4) + 1);
    *pbVar9 = *pbVar9 | 2;
  }
  if (((param_2 != 0) && (*(char *)((int)fVar4 + 0x7b5) == -1)) &&
     ((*(float *)((int)fVar4 + 0xd5c) <= 0.0 &&
      ((((*(char *)((int)fVar4 + 0x28b) == '\0' &&
         (pcVar3 = *(char **)((int)fVar4 + 0xcc4), (pcVar3[1] & 2U) == 0)) &&
        (0.8 <= *(float *)(pcVar3 + 8))) && ((*pcVar3 != '\0' && (0.8 <= *(float *)(pcVar3 + 8))))))
      ))) {
    FUN_00681f40("XWing_Torpedo",(int)fVar4 + 0x80);
    FUN_0054a850(**(undefined4 **)((int)fVar4 + 0xca4),0x3f000000,0);
    FUN_0054a8a0(**(undefined4 **)((int)fVar4 + 0xca4),0x3dcccccd,0);
    *(uint *)((int)fVar4 + 0xe20) = *(uint *)((int)fVar4 + 0xe20) | 0x4000000;
    *(undefined4 *)((int)fVar4 + 0xd5c) = param_3;
    *(uint *)((int)fVar4 + 0xeec) = *(uint *)((int)fVar4 + 0xeec) | 0x800;
    *(undefined1 *)(*(int *)((int)fVar4 + 0xcc4) + 2) = 0;
    if ((*(byte *)((int)fVar4 + 0x1fc) & 0x80) != 0) {
      FUN_00576960(0x289);
    }
  }
  iVar5 = FUN_004d23e0(fVar4);
  bVar1 = **(byte **)((int)fVar4 + 0xcc4);
  while (iVar5 < (int)(uint)bVar1) {
    if (((PTR_DAT_00802c54 == (undefined *)0x0) || (*(int *)(PTR_DAT_00802c54 + 300) == 0)) ||
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 4) == 0)) {
      pbVar9 = *(byte **)((int)fVar4 + 0xcc4) + (**(byte **)((int)fVar4 + 0xcc4) + 5) * 0xc;
      uVar10 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x58c);
    }
    else {
      pbVar9 = *(byte **)((int)fVar4 + 0xcc4) + (**(byte **)((int)fVar4 + 0xcc4) + 5) * 0xc;
      uVar10 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x5a0);
    }
    FUN_00684c90(uVar10,pbVar9,0x1e,0,0);
    **(char **)((int)fVar4 + 0xcc4) = **(char **)((int)fVar4 + 0xcc4) + -1;
    bVar1 = **(byte **)((int)fVar4 + 0xcc4);
  }
  pbVar9 = *(byte **)((int)fVar4 + 0xcc4);
  if (0.8 <= *(float *)(pbVar9 + 8)) {
    if (((((DAT_00881ae0 == '\0') || ((*(byte *)((int)fVar4 + 0x1fc) & 0x80) == 0)) ||
         (0.0 < *(float *)((int)fVar4 + 0xd5c))) ||
        ((*(char *)((int)fVar4 + 0x28b) != '\0' || ((pbVar9[1] & 2) != 0)))) ||
       (iVar5 <= (int)(uint)*pbVar9)) {
      iVar7 = FUN_0056e160(0x2a);
      if (((iVar7 == 0) || ((*(byte *)((int)fVar4 + 0x1fc) & 0x80) == 0)) ||
         ((0.0 < *(float *)((int)fVar4 + 0xd5c) ||
          (((*(char *)((int)fVar4 + 0x28b) != '\0' ||
            (pbVar9 = *(byte **)((int)fVar4 + 0xcc4), (pbVar9[1] & 2) != 0)) ||
           (iVar5 <= (int)(uint)*pbVar9)))))) {
        if (((((int)(uint)**(byte **)((int)fVar4 + 0xcc4) < iVar5) &&
             (iVar7 = FUN_0046fad0(PTR_DAT_00802c54,(int)fVar4 + 0x80,&local_8), iVar7 != 0)) &&
            ((*(byte *)(iVar7 + 0x2b) & 1) != 0)) && (local_8 < _DAT_007f9144)) {
          iVar6 = FUN_0054fa60(0);
          param_1 = (float)iVar6 * 1.5259022e-05 * 0.4;
          FUN_0054a850(**(undefined4 **)((int)fVar4 + 0xca4),param_1);
          if ((int)(uint)**(byte **)((int)fVar4 + 0xcc4) < iVar5) {
            FUN_0054a8a0(**(undefined4 **)((int)fVar4 + 0xca4),0x3dcccccd,0);
            pbVar9 = *(byte **)((int)fVar4 + 0xcc4) + (**(byte **)((int)fVar4 + 0xcc4) + 5) * 0xc;
            *(undefined4 *)pbVar9 = *(undefined4 *)(iVar7 + 0x10);
            *(undefined4 *)(pbVar9 + 4) = *(undefined4 *)(iVar7 + 0x14);
            *(undefined4 *)(pbVar9 + 8) = *(undefined4 *)(iVar7 + 0x18);
            **(char **)((int)fVar4 + 0xcc4) = **(char **)((int)fVar4 + 0xcc4) + '\x01';
            *(undefined4 *)(iVar7 + 0x1c) = 0;
            goto LAB_004d3c8b;
          }
        }
      }
      else {
        pbVar9 = pbVar9 + ((uint)*pbVar9 * 3 + 0xf) * 4;
        *(undefined4 *)pbVar9 = *(undefined4 *)((int)fVar4 + 0x5c);
        *(undefined4 *)(pbVar9 + 4) = *(undefined4 *)((int)fVar4 + 0x60);
        *(undefined4 *)(pbVar9 + 8) = *(undefined4 *)((int)fVar4 + 100);
        **(char **)((int)fVar4 + 0xcc4) = **(char **)((int)fVar4 + 0xcc4) + '\x01';
LAB_004d3c8b:
        *(undefined4 *)(*(int *)((int)fVar4 + 0xcc4) + 8) = 0;
        *(undefined1 *)(*(int *)((int)fVar4 + 0xcc4) + 3) = 0;
      }
    }
    else {
      pbVar9 = pbVar9 + ((uint)*pbVar9 * 3 + 0xf) * 4;
      *(undefined4 *)pbVar9 = *(undefined4 *)((int)fVar4 + 0x5c);
      *(undefined4 *)(pbVar9 + 4) = *(undefined4 *)((int)fVar4 + 0x60);
      *(undefined4 *)(pbVar9 + 8) = *(undefined4 *)((int)fVar4 + 100);
      **(char **)((int)fVar4 + 0xcc4) = **(char **)((int)fVar4 + 0xcc4) + '\x01';
      *(undefined4 *)(*(int *)((int)fVar4 + 0xcc4) + 8) = 0;
    }
  }
  else {
    *(float *)(pbVar9 + 8) = *(float *)(pbVar9 + 8) + _DAT_00925018;
    if (0.8 <= *(float *)(*(int *)((int)fVar4 + 0xcc4) + 8)) {
      *(undefined1 *)(*(int *)((int)fVar4 + 0xcc4) + 3) = 0;
    }
  }
  FUN_004d24f0(fVar4);
  if (**(char **)((int)fVar4 + 0xcc4) == '\0') {
    return;
  }
  if (((PTR_DAT_00802c54 == (undefined *)0x0) || (*(int *)(PTR_DAT_00802c54 + 300) == 0)) ||
     ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 4) == 0)) {
    uVar10 = 0xf;
  }
  else {
    uVar10 = 0x10;
  }
  iVar5 = FUN_005806a0(uVar10,PTR_DAT_00802c54);
  param_1 = *(float *)(iVar5 + 0x14) * *(float *)(iVar5 + 0x10);
  iVar5 = *(int *)((int)fVar4 + 0xcc4);
  param_1 = param_1 * param_1;
  if (((*(byte *)(iVar5 + 1) & 2) == 0) || (iVar7 = *(int *)(iVar5 + 0x84), iVar7 == 0)) {
    iVar7 = FUN_004d29f0(PTR_DAT_00802c54,(int)fVar4 + 0x5c,param_1,&param_1);
    uVar8 = param_1._0_1_;
  }
  else {
    uVar8 = *(undefined1 *)(iVar5 + 4);
  }
  if (iVar7 == 0) {
    if ((*(byte *)(*(int *)((int)fVar4 + 0xcc4) + 1) & 6) != 0) goto LAB_004d3e0a;
    if (*(float *)((int)fVar4 + 0xd80) <= 0.0) {
      *(undefined4 *)(*(int *)((int)fVar4 + 0xcc4) + 0x84) = 0;
      goto LAB_004d3e0a;
    }
  }
  else {
    iVar5 = *(int *)(*(int *)((int)fVar4 + 0xcc4) + 0x84);
    if (iVar7 == iVar5) {
      param_1 = *(float *)((int)fVar4 + 0xd80) + _DAT_00925018;
      *(float *)((int)fVar4 + 0xd80) = param_1;
      if (0.25 < param_1) {
        *(undefined4 *)((int)fVar4 + 0xd80) = 0x3e800000;
      }
      goto LAB_004d3e0a;
    }
    if ((*(float *)((int)fVar4 + 0xd80) <= 0.0) || (iVar5 == 0)) {
      *(int *)(*(int *)((int)fVar4 + 0xcc4) + 0x84) = iVar7;
      *(undefined1 *)(*(int *)((int)fVar4 + 0xcc4) + 4) = uVar8;
      *(undefined4 *)((int)fVar4 + 0xd80) = 0;
      goto LAB_004d3e0a;
    }
  }
  param_1 = *(float *)((int)fVar4 + 0xd80) - (_DAT_00925018 + _DAT_00925018);
  *(float *)((int)fVar4 + 0xd80) = param_1;
  if (param_1 < 0.0) {
    *(undefined4 *)((int)fVar4 + 0xd80) = 0;
  }
LAB_004d3e0a:
  if ((*(byte *)((int)fVar4 + 0x1fc) & 0x80) != 0) {
    iVar5 = *(int *)(*(int *)((int)fVar4 + 0xcc4) + 0x84);
    if ((iVar5 != 0) && (0.0 < *(float *)((int)fVar4 + 0xd80))) {
      cVar2 = *(char *)(*(int *)((int)fVar4 + 0xcc4) + 4);
      if (cVar2 == '\0') {
        iVar5 = iVar5 + 0x4c;
      }
      else if (cVar2 == '\x01') {
        iVar5 = FUN_005cf9e0(*(int *)(iVar5 + 0x1c) + 4);
      }
      else {
        if (cVar2 != '\x02') {
          return;
        }
        iVar5 = iVar5 + 0x28;
      }
      if (iVar5 != 0) {
        param_1 = DAT_00950f60 * 5.0;
        iVar5 = FUN_00560fa0(&DAT_00759770,iVar5,param_1,0,0,0xff,0,0xff,0x10c7,0);
        if (iVar5 != 0) {
          *(undefined1 *)(iVar5 + 0xfe) = 4;
          *(code **)(iVar5 + 0x10c) = FUN_004d3220;
          local_4 = (undefined1)(int)ROUND(*(float *)((int)fVar4 + 0xd80) * 4.0 * 128.0);
          *(undefined1 *)(iVar5 + 0xf7) = local_4;
          return;
        }
      }
    }
  }
  return;
}

