/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43d890; label: FUN_0043d890
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0043d890(uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5,int param_6,int param_7,int param_8,float *param_9,
                undefined4 param_10,int param_11)

{
  uint *puVar1;
  float *pfVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  ushort uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined2 uVar11;
  undefined4 *puVar12;
  short local_20 [2];
  uint local_1c;
  float local_18 [3];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar12 = param_2;
  if ((param_2 == (undefined4 *)0x0) && (param_8 == 0)) {
    return 0;
  }
  if ((((DAT_0087b504 != 0) && (param_1 != (int)DAT_007f191c)) ||
      (iVar8 = FUN_00475850(0), iVar8 == 0)) ||
     ((0x153 < param_1 || (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_1 * 2) == -1)))) {
    return 0;
  }
  iVar8 = FUN_0041f8f0(param_1,0);
  if (iVar8 == 0) {
    return 0;
  }
  *(uint *)(iVar8 + 0x1f8) = *(uint *)(iVar8 + 0x1f8) | 0x400;
  iVar9 = param_1 * 0x4c;
  uVar10 = *(uint *)(*(int *)(DAT_029130e4 + 0x20) + 4 + iVar9);
  if ((uVar10 & 0x200) == 0) {
    if ((uVar10 & 4) == 0) goto LAB_0043d94c;
    uVar10 = *(uint *)(iVar8 + 0x1f8) | 1;
  }
  else {
    uVar10 = *(uint *)(iVar8 + 0x1f8) | 4;
  }
  *(uint *)(iVar8 + 0x1f8) = uVar10;
LAB_0043d94c:
  *(uint *)(iVar8 + 0x1044) = *(uint *)(iVar8 + 0x1044) | 1;
  if ((*(uint *)(*(int *)(DAT_029130e4 + 0x20) + 4 + iVar9) & 0x1000) != 0) {
    *(uint *)(iVar8 + 0x1044) = *(uint *)(iVar8 + 0x1044) | 4;
  }
  *(undefined4 *)(iVar8 + 0x230) =
       *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar9) + 100);
  *(undefined4 *)(iVar8 + 0x234) =
       *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar9) + 0x68);
  *(undefined4 *)(iVar8 + 0x238) =
       *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar9) + 0x6c);
  uVar4 = *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar9) + 0x70);
  *(uint *)(iVar8 + 0x4b0) = *(uint *)(iVar8 + 0x4b0) & 0xffffafff;
  *(uint *)(iVar8 + 0xeec) = *(uint *)(iVar8 + 0xeec) & 0xfffff7fe;
  *(undefined4 *)(iVar8 + 0x23c) = uVar4;
  *(undefined4 *)(iVar8 + 0x39c) = 0;
  *(undefined4 *)(iVar8 + 0x454) = 0;
  *(undefined4 *)(iVar8 + 0x3a4) = 0;
  *(undefined4 *)(iVar8 + 0x3ac) = 0;
  *(undefined4 *)(iVar8 + 0x3a8) = 0x4e6e6b28;
  *(undefined4 *)(iVar8 + 0x3b4) = 0;
  *(undefined4 *)(iVar8 + 0x3b8) = 0x4e6e6b28;
  *(undefined4 *)(iVar8 + 0x2a8) = 0;
  *(undefined4 *)(iVar8 + 0x2ac) = 0;
  *(undefined4 *)(iVar8 + 0xeb0) = 0;
  *(undefined4 *)(iVar8 + 0xec4) = 0;
  *(undefined4 *)(iVar8 + 0xeb4) = 0;
  *(undefined4 *)(iVar8 + 0xecc) = 0;
  *(undefined4 *)(iVar8 + 0xec0) = 0;
  FUN_0041b0a0(iVar8);
  iVar9 = param_6;
  uVar4 = param_3;
  if (param_8 == 0) {
    puVar3 = (undefined4 *)(iVar8 + 0x5c);
    *puVar3 = *puVar12;
    *(undefined4 *)(iVar8 + 0x60) = puVar12[1];
    *(undefined4 *)(iVar8 + 100) = puVar12[2];
    uVar11 = (undefined2)param_3;
    *(undefined2 *)(iVar8 + 0x27a) = uVar11;
    *(undefined2 *)(iVar8 + 0x58) = uVar11;
    *(undefined2 *)(iVar8 + 0x5a) = uVar11;
    if (param_6 != 0) {
      FUN_00518040(param_6,iVar8);
      local_18[0] = (float)((*(byte *)(iVar8 + 0x411) + 1) / 2) * *(float *)(iVar9 + 0x128);
      if ((*(byte *)(iVar8 + 0x411) & 1) != 0) {
        local_18[0] = -local_18[0];
      }
      local_18[1] = 0.0;
      local_1c = (uint)*(byte *)(iVar8 + 0x412);
      local_18[2] = (float)local_1c * -*(float *)(iVar9 + 300);
      FUN_005b3620(local_18,local_18,uVar4);
      FUN_005b37d0(puVar3,puVar3,local_18);
    }
  }
  else {
    FUN_00553570((undefined4 *)(iVar8 + 0xe64),param_8,0,param_10);
    FUN_00550a20(*(undefined4 *)(iVar8 + 0xe64),*(undefined4 *)(iVar8 + 0xe80),&local_c,&param_2,
                 local_20,(int)*(char *)(iVar8 + 0xe6a));
    *(undefined2 *)(iVar8 + 0x5a) = param_2._0_2_;
    *(undefined2 *)(iVar8 + 0x58) = param_2._0_2_;
    *(undefined2 *)(iVar8 + 0x27a) = param_2._0_2_;
    *(short *)(iVar8 + 0x278) = -local_20[0];
    if (param_9 != (float *)0x0) {
      pfVar2 = (float *)(iVar8 + 0xe84);
      *pfVar2 = *param_9;
      *(float *)(iVar8 + 0xe88) = param_9[1];
      *(float *)(iVar8 + 0xe8c) = param_9[2];
      if (((*pfVar2 != 0.0) || (*(float *)(iVar8 + 0xe88) != 0.0)) ||
         (*(float *)(iVar8 + 0xe8c) != 0.0)) {
        FUN_005b35a0(local_18,pfVar2,*(undefined2 *)(iVar8 + 0x278));
        FUN_005b3620(local_18,local_18,*(undefined2 *)(iVar8 + 0x27a));
        FUN_005b37d0(&local_c,&local_c,local_18);
      }
    }
    *(undefined4 *)(iVar8 + 0x5c) = local_c;
    *(undefined4 *)(iVar8 + 0x60) = local_8;
    *(undefined4 *)(iVar8 + 100) = local_4;
  }
  puVar12 = (undefined4 *)(iVar8 + 0x5c);
  FUN_0041af70(iVar8);
  *(undefined4 *)(iVar8 + 0x80) = *puVar12;
  *(undefined4 *)(iVar8 + 0x84) = *(undefined4 *)(iVar8 + 0x60);
  *(undefined4 *)(iVar8 + 0x88) = *(undefined4 *)(iVar8 + 100);
  *(undefined4 *)(iVar8 + 0x98) = *puVar12;
  _DAT_0093d620 = *(undefined4 *)(iVar8 + 0x80);
  *(undefined4 *)(iVar8 + 0x9c) = *(undefined4 *)(iVar8 + 0x60);
  *(undefined4 *)(iVar8 + 0xa0) = *(undefined4 *)(iVar8 + 100);
  DAT_0093d624 = *(undefined4 *)(iVar8 + 0x84);
  DAT_0093d628 = *(undefined4 *)(iVar8 + 0x88);
  *(undefined4 *)(iVar8 + 0x8c) = *(undefined4 *)(iVar8 + 0x80);
  *(undefined4 *)(iVar8 + 0x90) = *(undefined4 *)(iVar8 + 0x84);
  *(undefined4 *)(iVar8 + 0x94) = *(undefined4 *)(iVar8 + 0x88);
  *(undefined4 *)(iVar8 + 0x68) = DAT_0093b0cc;
  *(undefined4 *)(iVar8 + 0x6c) = DAT_0093b0d0;
  *(undefined4 *)(iVar8 + 0x70) = DAT_0093b0d4;
  FUN_0055cd20(iVar8);
  FUN_0055cc40(iVar8);
  FUN_0054a7f0(*(int *)(iVar8 + 0xca4) + 0x40);
  FUN_00595840(puVar12,iVar8 + 0x4d8,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab4));
  *(undefined1 *)(iVar8 + 0x671) = 0xff;
  *(undefined2 *)(iVar8 + 0x672) = 0xffff;
  if (*(int *)(PTR_DAT_00802c54 + 0x2988) != 0) {
    if ((DAT_00803874 != -1) &&
       (*(char *)(DAT_00803874 * 0x13c + 0x32 + **(int **)(PTR_DAT_00802c54 + 0x2988)) != '\0')) {
      DAT_00801e38 = DAT_00803874;
    }
    FUN_00541bc0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),puVar12,(int)*(char *)(iVar8 + 0x671),
                 (int)*(short *)(iVar8 + 0x672),iVar8 + 0x670);
    FUN_0053f380(iVar8 + 0x7cc);
  }
  FUN_005b3710(iVar8 + 0xf30,0x3f800000,*(undefined2 *)(iVar8 + 0x27a));
  iVar9 = param_8;
  *(uint *)(iVar8 + 0xef0) = *(uint *)(iVar8 + 0xef0) & 0xfffbffff;
  *(undefined1 *)(iVar8 + 0x288) = 1;
  *(undefined1 *)(iVar8 + 0x1079) = 0;
  *(undefined1 *)(iVar8 + 0x28c) = 0;
  if ((param_8 == 0) && (FUN_005728a0(iVar8), param_7 != 0)) {
    FUN_00572660(iVar8,0);
  }
  FUN_0055d6a0(iVar8,1,1,0xffffffff,*(undefined4 *)(PTR_DAT_00802c54 + 0x13c));
  puVar3 = param_5;
  if (DAT_008765c4 != 0) {
    uVar5 = *(undefined1 *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0xf4);
    *(undefined1 *)(iVar8 + 0x107e) = uVar5;
    *(undefined1 *)(iVar8 + 0x107f) = uVar5;
    *(undefined1 *)(iVar8 + 0xe38) = *(undefined1 *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0xf5)
    ;
    *(undefined1 *)(iVar8 + 0xe39) = 4;
  }
  *(uint *)(iVar8 + 0x1fc) = *(uint *)(iVar8 + 0x1fc) & 0xfffffffb;
  *(undefined4 *)(iVar8 + 0xff8) = 0x3f800000;
  *(undefined1 *)(iVar8 + 0x28b) = 0;
  *(undefined1 *)(iVar8 + 0x7b5) = 0xff;
  *(undefined1 *)(iVar8 + 0x289) = 0;
  *(uint *)(iVar8 + 0x1f8) = (*(uint *)(iVar8 + 0x1f8) | 0x100) ^ 0x100;
  *(undefined4 *)(iVar8 + 0x420) = 0;
  *(undefined4 *)(iVar8 + 0x424) = 0;
  *(undefined4 *)(iVar8 + 0x428) = 0;
  *(undefined4 *)(iVar8 + 0x42c) = 0;
  *(undefined4 *)(iVar8 + 0x430) = 0;
  *(undefined4 *)(iVar8 + 0x434) = 0;
  *(undefined2 *)(iVar8 + 0x3ec) = 0xffff;
  *(undefined1 *)(iVar8 + 0x404) = 0xff;
  *(undefined1 *)(iVar8 + 0x405) = 0;
  if (iVar9 == 0) {
    if (param_5 != (undefined4 *)0x0) {
      FUN_0051a7c0(iVar8 + 0x2c8,*param_5);
      FUN_0051b890(iVar8 + 0x2c8,puVar12,puVar3[1],*(undefined1 *)(puVar3 + 2));
    }
    if (*(int *)(iVar8 + 0x424) == 0) {
      FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar8,iVar8 + 0x2c8,0xff,
                   (int)*(char *)(iVar8 + 0x281));
    }
  }
  FUN_00514640(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar8 + 0x2c8,iVar8 + 0x2c8,0,param_4,0,1,
               0,0);
  iVar9 = *(int *)(iVar8 + 0x40c);
  *(undefined4 *)(iVar8 + 0x218) = 0x49f42400;
  if (iVar9 != 0) {
    uVar10 = __allshl();
    puVar1 = (uint *)(iVar9 + 0x4c);
    *puVar1 = *puVar1 | uVar10;
    puVar3 = (undefined4 *)((uint)*(byte *)(iVar8 + 0x412) * 0x34 + 0x54 + *(int *)(iVar8 + 0x40c));
    bVar7 = __allshl();
    *(byte *)((int)puVar3 + 0x2d) = *(byte *)((int)puVar3 + 0x2d) | bVar7;
    if (*(char *)(iVar8 + 0x411) == '\0') {
      puVar3[6] = *puVar12;
      puVar3[7] = *(undefined4 *)(iVar8 + 0x60);
      puVar3[8] = *(undefined4 *)(iVar8 + 100);
      *puVar3 = *(undefined4 *)(iVar8 + 0x420);
      puVar3[1] = *(undefined4 *)(iVar8 + 0x424);
      puVar3[2] = *(undefined4 *)(iVar8 + 0x428);
      puVar3[3] = *(undefined4 *)(iVar8 + 0x42c);
      puVar3[4] = *(undefined4 *)(iVar8 + 0x430);
      puVar3[5] = *(undefined4 *)(iVar8 + 0x434);
      uVar6 = *(ushort *)(iVar8 + 0x27a);
      puVar3[0xc] = puVar3[0xc] & 0xfffffffd;
      puVar3[9] = (uint)uVar6;
      puVar3[10] = 0;
    }
  }
  FUN_00498a40(iVar8);
  FUN_004b6b80(iVar8);
  FUN_0055d2b0(iVar8);
  *(undefined4 *)(iVar8 + 0x1b4) = *puVar12;
  *(undefined4 *)(iVar8 + 0x10bc) = *puVar12;
  *(undefined4 *)(iVar8 + 0x1b8) = *(undefined4 *)(iVar8 + 0x60);
  *(undefined4 *)(iVar8 + 0x10c0) = *(undefined4 *)(iVar8 + 0x60);
  *(undefined4 *)(iVar8 + 0x1bc) = *(undefined4 *)(iVar8 + 100);
  *(undefined4 *)(iVar8 + 0x10c4) = *(undefined4 *)(iVar8 + 100);
  if (param_11 - 1U < 0x10) {
    *(char *)(iVar8 + 0x378) = (char)param_11;
    (&DAT_00876847)[param_11] = (&DAT_00876847)[param_11] + '\x01';
  }
  return iVar8;
}

