/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x5811f0; label: FUN_005811f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005811f0(int *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  ushort local_98;
  float fStack_94;
  int local_90;
  ushort local_8c [2];
  ushort local_88 [2];
  int iStack_84;
  uint uStack_80;
  uint uStack_7c;
  undefined1 local_74 [4];
  undefined1 local_70 [12];
  undefined1 local_64 [12];
  undefined1 local_58 [12];
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [64];
  
  if (param_1[1] != 0) {
    FUN_004ef660(local_88,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_88);
    }
    param_1[2] = param_1[2] + 2;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_8c,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_8c);
    }
    param_1[2] = param_1[2] + 2;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_70,param_1[2] + param_1[1],0xc);
    if (*param_1 != 0) {
      puVar9 = local_70;
      iVar6 = 3;
      do {
        FUN_00621190(puVar9);
        puVar9 = puVar9 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    param_1[2] = param_1[2] + 0xc;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_64,param_1[2] + param_1[1],0xc);
    if (*param_1 != 0) {
      puVar9 = local_64;
      iVar6 = 3;
      do {
        FUN_00621190(puVar9);
        puVar9 = puVar9 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    param_1[2] = param_1[2] + 0xc;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_58,param_1[2] + param_1[1],0xc);
    if (*param_1 != 0) {
      puVar9 = local_58;
      iVar6 = 3;
      do {
        FUN_00621190(puVar9);
        puVar9 = puVar9 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    param_1[2] = param_1[2] + 0xc;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(&local_90,param_1[2] + param_1[1],4);
    if (*param_1 != 0) {
      FUN_00621190(&local_90);
    }
    param_1[2] = param_1[2] + 4;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_74,param_1[2] + param_1[1],4);
    if (*param_1 != 0) {
      FUN_00621190(local_74);
    }
    param_1[2] = param_1[2] + 4;
  }
  uVar10 = (uint)local_88[0];
  iVar11 = uVar10 * 0x138;
  iVar8 = (uint)local_8c[0] * 0x10d8 + DAT_0093d504;
  piVar12 = &DAT_00951ce8 + uVar10 * 0x4e;
  iVar6 = *piVar12;
  if (((*(int *)(PTR_PTR_008040bc + 8) != 0) && (iVar4 = (&DAT_00951cec)[uVar10 * 0x4e], iVar4 != 0)
      ) && ((*(byte *)(iVar4 + 0x1fc) & 0x80) != 0)) {
    (**(code **)(PTR_PTR_008040bc + 8))(iVar4,&DAT_00951d70 + uVar10 * 0x4e);
  }
  if (((*(byte *)(iVar8 + 0x1fc) & 0x80) == 0) || (iVar4 = FUN_0055f250(iVar8), iVar4 == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  iVar4 = FUN_0056e0f0(0x100000);
  if ((iVar4 == 0) || (iStack_84 = 1, (*(byte *)(iVar8 + 0x1fc) & 0x80) == 0)) {
    iStack_84 = 0;
  }
  FUN_0054a850(**(undefined4 **)(iVar8 + 0xca4),0x3f000000,0);
  if ((((&DAT_00951dd8)[uVar10 * 0x4e] & 0x100) == 0) || (bVar3)) {
    iVar4 = *(char *)(iVar8 + 0x7b5) * 0x10;
    uVar7 = *(uint *)(PTR_PTR_007fb0e4 + iVar4 + 8);
    uStack_7c = *(uint *)(PTR_PTR_007fb0e4 + iVar4 + 0xc);
    if ((((uVar7 & 0x4000000) == 0) &&
        (((((uVar7 & 0x8000000) == 0 || ((*(uint *)(iVar8 + 0x7bc) & 0x20000) == 0)) && (!bVar3)) &&
         ((uVar7 & 0x800000) == 0)))) &&
       ((((uVar7 & 0x1000000) == 0 || ((*(byte *)(iVar8 + 0x7be) & 1) == 0)) &&
        (iVar4 = FUN_0058b7f0(iVar8), iVar4 == 0)))) goto LAB_005814e5;
    (**(code **)(PTR_PTR_008040bc + 0xc))(piVar12,local_70,local_90,iVar8 + 0x68,1);
    if ((DAT_00802820 != -1) && (*(char *)(iVar8 + 0x7b5) == DAT_00802820)) {
      FUN_0058dfa0(iVar8);
    }
    FUN_00547930(0x2a,local_70 + local_90 * 0xc,0,0);
    DAT_009543e8 = 1;
    if ((((DAT_0080281c == -1) || (*(char *)(iVar8 + 0x7b5) != DAT_0080281c)) && (!bVar3)) &&
       ((float)(&DAT_00951db0)[uVar10 * 0x4e] < 0.1)) goto LAB_00581b1e;
    iVar6 = (&DAT_00951cec)[uVar10 * 0x4e];
    if ((iVar6 == 0) || ((*(byte *)(iVar6 + 0x1fc) & 1) == 0)) {
      FUN_005b3800(auStack_4c,iVar11 + 0x951d7c,local_70 + local_90 * 0xc);
    }
    else {
      FUN_00550250(local_70 + local_90 * 0xc,iVar6 + 0x80,iVar6 + 0x68,
                   (&DAT_00951db4)[uVar10 * 0x4e],auStack_4c,0);
    }
    FUN_0054ff40(auStack_4c,0,0);
    if ((((((*(byte *)(&DAT_00951dd8 + uVar10 * 0x4e) & 0x40) != 0) && (!bVar3)) ||
         (((*(byte *)(iVar8 + 0x1fc) & 0x80) == 0 ||
          (((DAT_0080281c == -1 || (*(char *)(iVar8 + 0x7b5) != DAT_0080281c)) && (iStack_84 == 0)))
          ))) || ((*(byte *)(*(int *)(iVar8 + 0x54) + 4) & 8) == 0)) ||
       (((iVar6 = (&DAT_00951cec)[uVar10 * 0x4e], iVar6 != 0 &&
         ((*(uint *)(iVar6 + 0x1fc) & 1) != 0)) &&
        (((*(uint *)(iVar6 + 0x1fc) & 0x1000) == 0 || (*(char *)(iVar6 + 0x28b) != '\0')))))) {
      iVar6 = FUN_0054fa60();
      local_98 = (ushort)(int)ROUND((double)iVar6 * 1.5259021893143654e-05 * 16384.0 - 8192.0);
      DAT_0093b0c8 = DAT_0093b0c8 + local_98;
      FUN_0054fa60();
      iVar6 = FUN_006e6b90();
      DAT_0092b0bc = DAT_0092b0bc + iVar6;
      if (DAT_0092b0bc < -0x2000) {
        DAT_0092b0bc = -0x2000;
      }
      else if (0x2000 < DAT_0092b0bc) {
        DAT_0092b0bc = 0x2000;
      }
      DAT_0092b0c4 = (ushort)DAT_0092b0bc;
    }
    FUN_0054a8a0(**(undefined4 **)(iVar8 + 0xca4),0x3dcccccd,0);
    uStack_80 = (uint)DAT_0092b0c4;
    uStack_7c = (uint)DAT_0093b0c8;
    FUN_005c0820(auStack_40,&uStack_80);
    iVar6 = FUN_00582e70(iVar8,local_70 + local_90 * 0xc,auStack_40,(&DAT_00951de9)[iVar11],0);
  }
  else {
LAB_005814e5:
    if (((*(float *)(iVar8 + 0xd30) != 1.0) &&
        (((iVar4 = *(int *)(iVar8 + 0x54),
          (*(uint *)(*(int *)(iVar4 + 0x24) + 0x94) & 0x4000000) == 0 || (DAT_00951288 == 0)) ||
         (DAT_00951154 == 0)))) &&
       (((*(char *)(iVar8 + 0x107f) != '\0' || ((*(uint *)(iVar4 + 4) & 0x2000) == 0)) &&
        (((*(uint *)(iVar4 + 4) & 0x20000000) == 0 || (*(int *)(iVar8 + 0xcd0) != 0)))))) {
      (**(code **)(PTR_PTR_008040bc + 0xc))(piVar12,local_70,local_90,iVar8 + 0x68,0);
      if (((&DAT_00951dd8)[uVar10 * 0x4e] & 0x800000) == 0) {
        iVar6 = FUN_005806a0((&DAT_00951de9)[iVar11],PTR_DAT_00802c54);
        uVar7 = (uint)*(byte *)(iVar6 + 0x3c);
        iVar6 = FUN_0055f2c0(piVar12);
        if (iVar6 != 0) {
          uVar7 = uVar7 * 2;
        }
      }
      else {
        uVar7 = 0;
      }
      FUN_0057fe80(piVar12);
      iVar6 = (&DAT_00951cec)[uVar10 * 0x4e];
      if (((((iVar6 == 0) || ((*(uint *)(iVar6 + 0x1fc) & 1) == 0)) ||
           ((char)*(uint *)(iVar6 + 0x1fc) < '\0')) ||
          ((uVar5 = *(uint *)(iVar6 + 0x1f8) & 1, uVar5 == 0 ||
           (uVar5 != (*(uint *)(iVar8 + 0x1f8) & 1))))) &&
         (DAT_0095556c = piVar12,
         FUN_00438230(iVar6,iVar8,uVar7,*(undefined2 *)(&DAT_00951de0 + iVar11),0,0),
         ((&DAT_00951dd8)[uVar10 * 0x4e] & 0x800000) != 0)) {
        iVar6 = *(char *)(iVar8 + 0x7b5) * 0x10;
        uStack_7c = *(uint *)(PTR_PTR_007fb0e4 + iVar6 + 0xc);
        if ((((*(uint *)(PTR_PTR_007fb0e4 + iVar6 + 8) & 0x10000000) == 0) &&
            ((*(uint *)(PTR_PTR_007fb0e4 + iVar6 + 8) & 0x10008000) == 0)) &&
           (((*(byte *)(*(int *)(iVar8 + 0x54) + 4) & 0x10) != 0 &&
            ((DAT_00804c18 != -1 &&
             (*(int *)(*(int *)(*(int *)(iVar8 + 0x50) + 0xc) + DAT_00804c18 * 4) != 0)))))) {
          FUN_00432620(iVar8,_DAT_00804b04,0);
          if ((&DAT_00951cec)[uVar10 * 0x4e] != 0) {
            FUN_0054a8a0(**(undefined4 **)((&DAT_00951cec)[uVar10 * 0x4e] + 0xca4),0x3dcccccd,0);
          }
        }
      }
      if (((&DAT_00951cec)[uVar10 * 0x4e] != 0) &&
         (puVar1 = *(undefined4 **)((&DAT_00951cec)[uVar10 * 0x4e] + 0xca4),
         puVar1 != (undefined4 *)0x0)) {
        FUN_0054a850(*puVar1,0x3f333333,0);
      }
      goto LAB_00581b1e;
    }
    if (((&DAT_00951dd8)[uVar10 * 0x4e] & 0x4000000) != 0) {
      (**(code **)(PTR_PTR_008040bc + 0xc))(piVar12,local_70,local_90,iVar8 + 0x68,0);
      FUN_00433be0((&DAT_00951cec)[uVar10 * 0x4e],iVar8,*(undefined1 *)(iVar6 + 0x3c),piVar12);
      goto LAB_00581b1e;
    }
    (**(code **)(PTR_PTR_008040bc + 0xc))(piVar12,local_70,local_90,iVar8 + 0x68,1);
    FUN_00433be0((&DAT_00951cec)[uVar10 * 0x4e],iVar8,0,piVar12);
    FUN_00547930(0x29,&DAT_00951d70 + uVar10 * 0x4e,0,0);
    FUN_0054a8a0(**(undefined4 **)(iVar8 + 0xca4),0x3dcccccd,0);
    if (((&DAT_00951dd8)[uVar10 * 0x4e] & 0x100000) != 0) goto LAB_00581b1e;
    DAT_0093b0c8 = FUN_005be2d0((float)(&DAT_00951d70)[uVar10 * 0x4e] - *(float *)(iVar8 + 0x80),
                                (float)(&DAT_00951d78)[uVar10 * 0x4e] - *(float *)(iVar8 + 0x88));
    iVar6 = FUN_0054fa60();
    local_98 = (ushort)(int)ROUND((double)iVar6 * 1.5259021893143654e-05 * 16384.0 - 5461.0);
    DAT_0093b0c8 = DAT_0093b0c8 + local_98;
    iVar6 = FUN_0054fa60();
    uStack_7c = (uint)DAT_0093b0c8;
    uStack_80 = (uint)ROUND(-1820.0 - (double)iVar6 * 1.5259021893143654e-05 * 6371.0);
    local_98 = (ushort)uStack_80;
    uStack_80 = uStack_80 & 0xffff;
    DAT_0092b0c4 = local_98;
    FUN_005c0820(auStack_40,&uStack_80);
    DAT_009543e8 = 1;
    iVar6 = FUN_00582e70(iVar8,local_70 + local_90 * 0xc,auStack_40,(&DAT_00951de9)[iVar11],0);
  }
  if (iVar6 != 0) {
    *(uint *)(iVar6 + 0xf0) = *(uint *)(iVar6 + 0xf0) | 0x10000000;
  }
LAB_00581b1e:
  if ((*(char *)(iVar8 + 0x28b) == '\0') && ((*(byte *)(iVar8 + 0x1fc) & 2) == 0)) {
    fStack_94 = *(float *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x18);
    if (1.0 < *(float *)(iVar8 + 0xa4)) {
      fStack_94 = fStack_94 / *(float *)(iVar8 + 0xa4);
    }
    *(float *)(iVar8 + 0x68) =
         *(float *)(iVar8 + 0x68) + fStack_94 * *(float *)(&DAT_00951d94 + iVar11);
    *(float *)(iVar8 + 0x70) =
         fStack_94 * *(float *)(&DAT_00951d9c + iVar11) + *(float *)(iVar8 + 0x70);
  }
  if ((*(byte *)(iVar8 + 0x1fc) & 0x80) != 0) {
    FUN_00549f10();
  }
  iVar6 = *piVar12;
  (&DAT_00951de8)[iVar11] = 0;
  if ((iVar6 != 0) && (pcVar2 = *(code **)(iVar6 + 0x4c), pcVar2 != (code *)0x0)) {
    (*pcVar2)(piVar12);
  }
  return;
}

