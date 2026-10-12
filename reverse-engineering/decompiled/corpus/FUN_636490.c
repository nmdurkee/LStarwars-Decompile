/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x636490; label: FUN_00636490
 */

void FUN_00636490(int param_1,int param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int unaff_EDI;
  float10 fVar8;
  int local_10;
  
  iVar5 = 0;
  puVar6 = (undefined4 *)(unaff_EDI + 0x9c);
  do {
    iVar3 = *(int *)(unaff_EDI + iVar5 * 4);
    if (iVar3 == 0) {
      puVar6[-9] = 0;
      puVar6[-8] = 0;
      puVar6[-7] = 0;
      *puVar6 = DAT_00806594;
      puVar6[1] = DAT_00806598;
      puVar6[2] = DAT_0080659c;
      goto LAB_006365e8;
    }
    switch(*(undefined1 *)(iVar3 + 0x58)) {
    case 2:
      goto joined_r0x00636557;
    case 3:
    case 6:
    case 8:
joined_r0x00636557:
      if (param_1 != 0) {
        FUN_005b3800(puVar6,iVar3,param_1);
        FUN_005b3b30(puVar6,puVar6);
        break;
      }
      puVar6[-9] = 0;
      puVar6[-8] = 0;
      puVar6[-7] = 0;
      goto LAB_006365e8;
    case 4:
      *puVar6 = *(undefined4 *)(iVar3 + 0xc);
      puVar6[1] = *(undefined4 *)(iVar3 + 0x10);
      puVar6[2] = *(undefined4 *)(iVar3 + 0x14);
      break;
    default:
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0x3f800000;
      FUN_005b35a0(puVar6,puVar6,(int)*(short *)(*(int *)(unaff_EDI + iVar5 * 4) + 0x5a));
      FUN_005b3620(puVar6,puVar6,(int)*(short *)(*(int *)(unaff_EDI + iVar5 * 4) + 0x5c));
      FUN_005b3200(puVar6,puVar6,&DAT_009736e8);
      *(undefined4 *)(unaff_EDI + 0xc + iVar5 * 4) = 0x3f800000;
    }
    iVar3 = *(int *)(unaff_EDI + iVar5 * 4);
    fVar8 = (float10)FUN_00636240(iVar3);
    fVar2 = (float)fVar8;
    puVar6[-9] = fVar2 * *(float *)(iVar3 + 0x18);
    puVar6[-8] = *(float *)(*(int *)(unaff_EDI + iVar5 * 4) + 0x1c) * fVar2;
    puVar6[-7] = fVar2 * *(float *)(*(int *)(unaff_EDI + iVar5 * 4) + 0x20);
LAB_006365e8:
    if (param_2 != 0) {
      FUN_005b3200(puVar6,puVar6,param_2);
    }
    iVar5 = iVar5 + 1;
    puVar6 = puVar6 + 3;
    if (2 < iVar5) {
      if (param_3 != 1.0) {
        FUN_005b3830(unaff_EDI + 0x78,unaff_EDI + 0x78,param_3);
        FUN_005b3830(unaff_EDI + 0x84,unaff_EDI + 0x84,param_3);
        FUN_005b3830(unaff_EDI + 0x90,unaff_EDI + 0x90,param_3);
      }
      pfVar1 = (float *)(unaff_EDI + 0xc0);
      *(undefined4 *)(unaff_EDI + 200) = 0;
      piVar7 = (int *)(unaff_EDI + 0x18);
      *(undefined4 *)(unaff_EDI + 0xc4) = 0;
      local_10 = 3;
      *pfVar1 = 0.0;
      do {
        iVar5 = *piVar7;
        if (iVar5 != 0) {
          fVar8 = (float10)FUN_00636240(iVar5);
          fVar2 = (float)fVar8;
          fVar4 = *pfVar1 + fVar2 * *(float *)(iVar5 + 0x18);
          if (1.0 < fVar4) {
            fVar4 = 1.0;
          }
          *pfVar1 = fVar4;
          fVar4 = *(float *)(*piVar7 + 0x1c) * fVar2 + *(float *)(unaff_EDI + 0xc4);
          if (1.0 < fVar4) {
            fVar4 = 1.0;
          }
          *(float *)(unaff_EDI + 0xc4) = fVar4;
          fVar2 = fVar2 * *(float *)(*piVar7 + 0x20) + *(float *)(unaff_EDI + 200);
          if (1.0 < fVar2) {
            fVar2 = 1.0;
          }
          *(float *)(unaff_EDI + 200) = fVar2;
        }
        piVar7 = piVar7 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
      if (param_3 != 1.0) {
        FUN_005b3830(pfVar1,pfVar1,param_3);
      }
      FUN_005b3b30(unaff_EDI + 0x134,unaff_EDI + 0x134);
      return;
    }
  } while( true );
}

