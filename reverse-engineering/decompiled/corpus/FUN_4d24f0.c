/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d24f0; label: FUN_004d24f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d24f0(uint param_1)

{
  byte *pbVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  undefined4 uVar13;
  uint local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  uVar3 = param_1;
  if (0.0 < *(float *)(*(int *)(param_1 + 0xcc4) + 0x10)) {
    *(float *)(*(int *)(param_1 + 0xcc4) + 0x10) =
         *(float *)(*(int *)(param_1 + 0xcc4) + 0x10) - _DAT_00925018;
    if (*(float *)(*(int *)(param_1 + 0xcc4) + 0x10) < 0.0) {
      *(undefined4 *)(*(int *)(param_1 + 0xcc4) + 0x10) = 0;
    }
  }
  pbVar7 = *(byte **)(param_1 + 0xcc4);
  local_20 = 0.0;
  if (*pbVar7 != 0) {
    do {
      fVar4 = local_20;
      iVar11 = *(int *)(uVar3 + 0xcc4);
      local_1c = (float)(&DAT_029899a0)
                        [*(int *)(iVar11 + 0x28 + (int)local_20 * 4) + 0x4000 >> 1 & 0x7fff];
      fVar2 = *(float *)(uVar3 + 0x1dc) * 1.5 +
              (float)(int)local_20 * *(float *)(uVar3 + 0x1dc) * 1.25;
      local_18 = *(float *)(uVar3 + 0x80) +
                 fVar2 * local_1c *
                         (float)(&DAT_029899a0)
                                [*(int *)(iVar11 + 0x14 + (int)local_20 * 4) >> 1 & 0x7fff];
      local_14 = (float)(&DAT_029899a0)[*(int *)(iVar11 + 0x28 + (int)local_20 * 4) >> 1 & 0x7fff] *
                 fVar2 + *(float *)(uVar3 + 0x84);
      local_10 = local_1c *
                 (float)(&DAT_029899a0)
                        [*(int *)(iVar11 + 0x14 + (int)local_20 * 4) + 0x4000 >> 1 & 0x7fff] * fVar2
                 + *(float *)(uVar3 + 0x88);
      if ((0.8 <= *(float *)(iVar11 + 8)) || ((int)local_20 + 1U != (uint)*pbVar7)) {
        iVar11 = ((int)local_20 * 3 + 0xf) * 4;
        *(float *)(pbVar7 + iVar11) = local_18;
        *(float *)(pbVar7 + iVar11 + 4) = local_14;
        *(float *)(pbVar7 + iVar11 + 8) = local_10;
        local_20 = fVar2;
      }
      else {
        iVar11 = ((int)local_20 * 3 + 0xf) * 4;
        local_20 = fVar2;
        FUN_005b3800(local_c,&local_18,pbVar7 + iVar11);
        iVar5 = FUN_006e6b90();
        local_1c = 1.0 - ((float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] + 1.0) * 0.5;
        FUN_005b3830(local_c,local_c,local_1c);
        iVar5 = *(int *)(uVar3 + 0xcc4) + iVar11;
        FUN_005b37d0(iVar5,iVar5,local_c);
      }
      if (fVar4 == 0.0) {
        local_24 = FUN_005be590(*(undefined2 *)(uVar3 + 0x27a),0x8000);
        local_24 = local_24 & 0xffff;
        uVar9 = -*(short *)(uVar3 + 0xe1a);
      }
      else {
        local_24 = (uint)*(ushort *)(*(int *)(uVar3 + 0xcc4) + 0x10 + (int)fVar4 * 4);
        uVar9 = *(ushort *)(*(int *)(uVar3 + 0xcc4) + 0x24 + (int)fVar4 * 4);
      }
      param_1 = (uint)uVar9;
      uVar6 = FUN_00550070(*(undefined2 *)(*(int *)(uVar3 + 0xcc4) + 0x14 + (int)fVar4 * 4),local_24
                           ,0x40a00000);
      *(uint *)(*(int *)(uVar3 + 0xcc4) + 0x14 + (int)fVar4 * 4) = uVar6 & 0xffff;
      uVar6 = FUN_00550070(*(undefined2 *)(*(int *)(uVar3 + 0xcc4) + 0x28 + (int)fVar4 * 4),param_1,
                           0x40a00000);
      *(uint *)(*(int *)(uVar3 + 0xcc4) + 0x28 + (int)fVar4 * 4) = uVar6 & 0xffff;
      iVar5 = *(int *)(uVar3 + 0xcc4);
      if (fVar4 == 0.0) {
        uVar8 = (uint)(ushort)(*(short *)(iVar5 + 0x14) + 0xc000);
        uVar6 = (uint)(ushort)(*(short *)(iVar5 + 0x28) + 0xc000);
        iVar10 = uVar3 + 0x5c;
        uVar13 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0xa14);
      }
      else {
        iVar10 = ((int)fVar4 * 3 + 0xc) * 4;
        FUN_005b3800(local_c,iVar5 + iVar11,iVar5 + iVar10);
        FUN_0054ffc0(local_c,&param_1,&local_24);
        iVar10 = *(int *)(uVar3 + 0xcc4) + iVar10;
        uVar13 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0xa14);
        uVar6 = param_1;
        uVar8 = local_24;
      }
      FUN_00684be0(uVar13,iVar10,0x5a,_DAT_00925018,uVar6,uVar8,0);
      pbVar7 = *(byte **)(uVar3 + 0xcc4);
      local_20 = (float)((int)fVar4 + 1);
    } while ((int)local_20 < (int)(uint)*pbVar7);
  }
  if (((((*(char **)(uVar3 + 0xcc4))[1] & 0x20U) != 0) && (**(char **)(uVar3 + 0xcc4) != '\0')) &&
     (*(char *)(uVar3 + 0x280) == -1)) {
    iVar11 = 0;
    do {
      iVar5 = (&DAT_0093d7f0)[iVar11];
      if (((((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) &&
           ((*(char *)(iVar5 + 0x28b) == '\0' &&
            (((char)*(uint *)(iVar5 + 0x1fc) < '\0' && ((*(byte *)(iVar5 + 0xe20) & 0x20) == 0))))))
          && (**(byte **)(iVar5 + 0xcc4) < 5)) &&
         (*(float *)(*(byte **)(iVar5 + 0xcc4) + 0x10) == 0.0)) {
        fVar12 = (float10)FUN_005b3cf0(*(byte **)(uVar3 + 0xcc4) +
                                       (**(byte **)(uVar3 + 0xcc4) + 4) * 0xc,iVar5 + 0x80,local_c);
        local_1c = (float)fVar12;
        if (local_1c < _DAT_007ffa88 * _DAT_007ffa88) {
          pbVar7 = *(byte **)(uVar3 + 0xcc4) + (**(byte **)(uVar3 + 0xcc4) + 4) * 0xc;
          pbVar1 = *(byte **)((&DAT_0093d7f0)[iVar11] + 0xcc4) +
                   (**(byte **)((&DAT_0093d7f0)[iVar11] + 0xcc4) + 5) * 0xc;
          *(undefined4 *)pbVar1 = *(undefined4 *)pbVar7;
          *(undefined4 *)(pbVar1 + 4) = *(undefined4 *)(pbVar7 + 4);
          *(undefined4 *)(pbVar1 + 8) = *(undefined4 *)(pbVar7 + 8);
          *(undefined4 *)
           (*(byte **)((&DAT_0093d7f0)[iVar11] + 0xcc4) +
           (uint)**(byte **)((&DAT_0093d7f0)[iVar11] + 0xcc4) * 4 + 0x14) =
               *(undefined4 *)
                (*(byte **)(uVar3 + 0xcc4) + (uint)**(byte **)(uVar3 + 0xcc4) * 4 + 0x10);
          *(undefined4 *)
           (*(byte **)((&DAT_0093d7f0)[iVar11] + 0xcc4) +
           (uint)**(byte **)((&DAT_0093d7f0)[iVar11] + 0xcc4) * 4 + 0x28) =
               *(undefined4 *)
                (*(byte **)(uVar3 + 0xcc4) + (uint)**(byte **)(uVar3 + 0xcc4) * 4 + 0x24);
          **(char **)((&DAT_0093d7f0)[iVar11] + 0xcc4) =
               **(char **)((&DAT_0093d7f0)[iVar11] + 0xcc4) + '\x01';
          *(undefined4 *)(*(int *)((&DAT_0093d7f0)[iVar11] + 0xcc4) + 8) = 0;
          *(undefined1 *)(*(int *)((&DAT_0093d7f0)[iVar11] + 0xcc4) + 3) = 1;
          **(char **)(uVar3 + 0xcc4) = **(char **)(uVar3 + 0xcc4) + -1;
          *(undefined4 *)(*(int *)((&DAT_0093d7f0)[iVar11] + 0xcc4) + 0x10) = _DAT_007ffa84;
          return;
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 2);
  }
  return;
}

