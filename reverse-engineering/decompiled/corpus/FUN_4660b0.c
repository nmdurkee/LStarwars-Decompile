/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x4660b0; label: FUN_004660b0
 */

void FUN_004660b0(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar7 = 0;
  if ((short)param_1[1] != 0) {
    piVar6 = (int *)(*param_1 + 0x24);
    do {
      *(ushort *)((int)piVar6 + 6) = *(ushort *)((int)piVar6 + 6) | 3;
      if (piVar6[-2] != 0) {
        FUN_005a0670(piVar6[-2]);
      }
      iVar2 = *piVar6;
      if ((((iVar2 != 0) && ((*(byte *)(param_1 + 3) & 2) != 0)) &&
          ((*(uint *)(iVar2 + 0x1fc) & 1) != 0)) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) {
        FUN_004364e0(iVar2,4,0);
      }
      *piVar6 = 0;
      if ((param_2 != 0) && (iVar7 < 0x60)) {
        iVar2 = (int)(iVar7 + (iVar7 >> 0x1f & 0x1fU)) >> 5;
        uVar5 = 1 << ((byte)iVar7 & 0x1f);
        *(ushort *)((int)piVar6 + 6) =
             *(ushort *)((int)piVar6 + 6) ^
             (byte)(((*(uint *)(param_2 + 0xc + iVar2 * 4) & uVar5) != 0) * '\x02' ^
                   *(byte *)((int)piVar6 + 6)) & 2;
        *(ushort *)((int)piVar6 + 6) =
             (byte)((*(uint *)(param_2 + iVar2 * 4) & uVar5) != 0 ^
                   (byte)*(ushort *)((int)piVar6 + 6)) & 1 ^ *(ushort *)((int)piVar6 + 6);
      }
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 0xb;
    } while (iVar7 < (int)(uint)*(ushort *)(param_1 + 1));
  }
  if ((DAT_00876df4 == 0) || (DAT_00876df4 != DAT_00876df8)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  iVar7 = 0;
  do {
    if (DAT_00951b50 != 0) {
      return;
    }
    if (((((&DAT_0093d7f0)[iVar7] != 0) && ((&DAT_00876df4)[iVar7] != 0)) &&
        (iVar2 = *(int *)((&DAT_0093d7f0)[iVar7] + 0x1040), iVar2 != 0)) &&
       ((iVar2 = *(int *)(iVar2 + 4), iVar2 != 0 && (*(short *)(iVar2 + 0x1064) == DAT_007f191c))))
    {
      FUN_004364e0(iVar2,4,0);
      *(undefined4 *)((&DAT_0093d7f0)[iVar7] + 0x1040) = 0;
    }
    iVar2 = (&DAT_0093d7f0)[iVar7];
    if (((iVar2 != 0) && ((*(byte *)(iVar2 + 0x1fc) & 0x80) != 0)) &&
       (((&DAT_00876df4)[iVar7] != 0 && (*(int *)(iVar2 + 0x1040) == 0)))) {
      if ((((iVar7 == 0) || (!bVar1)) || (*(int *)(DAT_0093d7f0 + 0x1040) == 0)) ||
         ((iVar3 = *(int *)(*(int *)(DAT_0093d7f0 + 0x1040) + 4), iVar3 == 0 ||
          (*(short *)(iVar3 + 0x1064) != DAT_007f191c)))) {
        local_c = 0;
        local_8 = 0;
        local_4 = 0xc0000000;
        FUN_005b3620(&local_c,&local_c,*(undefined2 *)(iVar2 + 0x27a));
        FUN_005b37d0(&local_c,&local_c,(&DAT_0093d7f0)[iVar7] + 0x80);
        iVar3 = FUN_0043d890((int)DAT_007f191c,&local_c,0,"dragbomb",0,0,0,0,0,0,0);
      }
      if (iVar3 != 0) {
        uVar4 = FUN_00408880((&DAT_0093d7f0)[iVar7],iVar3,0);
        *(undefined4 *)((&DAT_0093d7f0)[iVar7] + 0x1040) = uVar4;
        if (*(int *)((&DAT_0093d7f0)[iVar7] + 0x1040) != 0) {
          *(undefined4 *)(*(int *)((&DAT_0093d7f0)[iVar7] + 0x1040) + 0x1c4) = 0x4e6e6b28;
        }
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  return;
}

