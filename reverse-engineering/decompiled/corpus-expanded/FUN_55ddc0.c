/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55ddc0; label: FUN_0055ddc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055ddc0(int param_1)

{
  int iVar1;
  short sVar2;
  bool bVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  short *psVar11;
  undefined4 local_44 [2];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  if ((*(int *)(param_1 + 300) == 0) ||
     (bVar3 = true, (*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 4) == 0)) {
    bVar3 = false;
  }
  puVar5 = &DAT_0093d5ac;
  do {
    *(undefined4 **)(puVar5 + -6) = &DAT_0093b0cc;
    *puVar5 = 0;
    puVar5 = puVar5 + 8;
  } while ((int)puVar5 < 0x93d62c);
  if ((*(int *)(param_1 + 0x46a0) == 0) || (bVar3)) {
    if (DAT_00803b74 == -1) {
      psVar11 = (short *)0x0;
    }
    else {
      psVar11 = *(short **)(*(int *)(param_1 + 0x2ac4) + DAT_00803b74 * 4);
    }
    iVar8 = 0;
  }
  else {
    psVar11 = *(short **)(*(int *)(param_1 + 0x46a0) + 0xa0);
    iVar8 = 2;
  }
  if (psVar11 != (short *)0x0) {
    puVar5 = &DAT_0093d5ac;
    iVar6 = iVar8;
    do {
      iVar1 = *(int *)(psVar11 + 4) + iVar6 * 0x18;
      *(int *)(puVar5 + -6) = iVar1;
      FUN_005b3800(local_44,*(int *)(psVar11 + 4) + 0xc + iVar6 * 0x18,iVar1);
      uVar4 = FUN_005be2d0(local_44[0],local_3c);
      *puVar5 = uVar4;
      iVar9 = iVar6 + 1;
      iVar1 = iVar6 + 3;
      iVar6 = iVar9;
      if ((int)*psVar11 < iVar1 + iVar9) {
        iVar6 = iVar8;
      }
      puVar5 = puVar5 + 8;
    } while ((int)puVar5 < 0x93d62c);
    if ((bVar3) && (sVar2 = *psVar11, 3 < sVar2)) {
      iVar6 = FUN_0054fa60();
      iVar6 = iVar6 / ((int)(0xffff / (longlong)((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 3U)) >> 2)
                            ) + 1);
      iVar8 = iVar6 * 0x30;
      DAT_0093d5a0 = (float *)(*(int *)(psVar11 + 4) + iVar8);
      DAT_0093d5ac = FUN_005be2d0(*(float *)(*(int *)(psVar11 + 4) + iVar8 + 0xc) - *DAT_0093d5a0,
                                  *(float *)(*(int *)(psVar11 + 4) + 0x14 + iVar8) - DAT_0093d5a0[2]
                                 );
      DAT_0093d5b0 = *(int *)(psVar11 + 4) + (iVar6 * 0xc + 6) * 4;
      DAT_0093d5bc = FUN_005be2d0(*(float *)(*(int *)(psVar11 + 4) + (iVar6 * 0xc + 9) * 4) -
                                  *DAT_0093d5a0,
                                  *(float *)(*(int *)(psVar11 + 4) + 0x2c + iVar8) -
                                  *(float *)(DAT_0093d5b0 + 8));
    }
  }
  if ((((DAT_00951364 != 0) && (*(int *)(param_1 + 300) == DAT_00951364)) &&
      (DAT_0095121c != *(int *)(param_1 + 0x120))) && (DAT_0095de48 == 0)) {
    if (DAT_008059f4 == -1) {
      if (DAT_008059f8 == -1) {
        if (DAT_00805a00 == -1) {
          iVar8 = DAT_008059fc;
          if (DAT_008059fc == -1) {
            if (DAT_0095121c == -1) goto LAB_0055e0b6;
            iVar6 = DAT_0095121c * 0x9c + DAT_00951354;
            iVar8 = DAT_0095121c;
            if ((((*(byte *)(iVar6 + 0x7a) & 4) != 0) &&
                (iVar6 = (int)*(char *)(iVar6 + 0x86), iVar6 != -1)) &&
               (iVar8 = FUN_0059b6a0(DAT_00956290 + iVar6 * 0x1c,5,5), iVar8 == -1)) {
              iVar8 = DAT_0095121c;
            }
          }
          iVar8 = FUN_00575920(param_1,iVar8,0xffffffff,0);
        }
        else {
          iVar8 = FUN_005756c0(param_1,"door_to_network");
        }
      }
      else {
        iVar8 = FUN_005756c0(param_1,"mission_door");
      }
    }
    else {
      uVar7 = FUN_0059b6a0(DAT_00956290 + DAT_008059f4 * 0x1c,5,5);
      iVar8 = FUN_00575920(param_1,uVar7,0xffffffff,0);
    }
    if (iVar8 != 0) {
      FUN_004f1f10(&DAT_009513b8,iVar8);
    }
  }
LAB_0055e0b6:
  FUN_00575820();
  _DAT_0095141c = 0;
  if (DAT_009513f8 != '\0') {
    _DAT_0095141c = FUN_005d0690(*(undefined4 *)(param_1 + 0x13c),&DAT_009513f8);
    if (_DAT_0095141c == 0) {
      DAT_00951420 = 0;
    }
    else {
      puVar10 = *(undefined4 **)(_DAT_0095141c + 8);
      DAT_0095138c = *puVar10;
      DAT_00951390 = puVar10[1];
      DAT_00951394 = puVar10[2];
      iVar8 = *(int *)(_DAT_0095141c + 8);
      DAT_009513a0 = *(undefined4 *)(iVar8 + 0xc);
      DAT_009513a4 = *(undefined4 *)(iVar8 + 0x10);
      DAT_009513a8 = *(undefined4 *)(iVar8 + 0x14);
    }
  }
  DAT_009513f8 = 0;
  puVar10 = &DAT_0093d5a4;
  do {
    FUN_00541bc0(*(undefined4 *)(param_1 + 0x2988),puVar10[-1],0xffffffff,0xffffffff,&local_38);
    *puVar10 = local_38;
    puVar10[1] = local_34;
    puVar10 = puVar10 + 4;
  } while ((int)puVar10 < 0x93d624);
  if ((DAT_00951364 != 0) && (*(int *)(param_1 + 300) == DAT_00951364)) {
    DAT_008059f4 = -1;
    DAT_008059f8 = -1;
    DAT_00805a00 = -1;
    DAT_008800b8 = DAT_0095de48;
    DAT_0095de48 = 0;
  }
  return;
}

