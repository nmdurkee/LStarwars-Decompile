/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e3390; label: thunk_FUN_006e2d20
 */

void thunk_FUN_006e2d20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  short sVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  int in_ECX;
  int iVar12;
  undefined4 *unaff_ESI;
  short sVar13;
  int *piVar14;
  uint unaff_EDI;
  undefined2 in_FPUControlWord;
  float *pfStack_b0;
  uint uStack_ac;
  int *piStack_a8;
  undefined4 uVar15;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  piVar14 = *(int **)(in_ECX + 0x6b0);
  _piStack_a8 = (ulonglong)unaff_EDI << 0x20;
  if (piVar14 != (int *)0x0) {
    _piStack_a8 = CONCAT44(unaff_EDI,piVar14);
    uStack_ac = 0x6e2d40;
    (**(code **)(*piVar14 + 8))();
    *(undefined4 *)(in_ECX + 0x6b0) = 0;
  }
  piVar14 = *(int **)(in_ECX + 0x6ec);
  if (piVar14 != (int *)0x0) {
    uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
    _piStack_a8 = CONCAT44(uVar15,piVar14);
    uStack_ac = 0x6e2d5e;
    (**(code **)(*piVar14 + 8))();
    *(undefined4 *)(in_ECX + 0x6ec) = 0;
  }
  piVar14 = *(int **)(in_ECX + 0x690);
  if (piVar14 != (int *)0x0) {
    uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
    _piStack_a8 = CONCAT44(uVar15,piVar14);
    uStack_ac = 0x6e2d72;
    (**(code **)(*piVar14 + 8))();
    *(undefined4 *)(in_ECX + 0x690) = 0;
  }
  piVar14 = *(int **)(in_ECX + 0x694);
  if (piVar14 != (int *)0x0) {
    uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
    _piStack_a8 = CONCAT44(uVar15,piVar14);
    uStack_ac = 0x6e2d8a;
    (**(code **)(*piVar14 + 8))();
    *(undefined4 *)(in_ECX + 0x694) = 0;
  }
  piVar14 = *(int **)(in_ECX + 0x698);
  if (piVar14 != (int *)0x0) {
    uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
    _piStack_a8 = CONCAT44(uVar15,piVar14);
    uStack_ac = 0x6e2dac;
    (**(code **)(*piVar14 + 8))();
    *(undefined4 *)(in_ECX + 0x698) = 0;
  }
  piVar14 = *(int **)(in_ECX + 0x688);
  puVar1 = (undefined4 *)(in_ECX + 0x688);
  if (piVar14 != (int *)0x0) {
    uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
    _piStack_a8 = CONCAT44(uVar15,piVar14);
    uStack_ac = 0x6e2dc6;
    (**(code **)(*piVar14 + 8))();
    *puVar1 = 0;
  }
  uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
  _piStack_a8 = CONCAT44(uVar15,in_ECX + 0x6b0);
  uStack_ac = 0;
  pfStack_b0 = (float *)0x0;
  (**(code **)(**(int **)(in_ECX + 4) + 0x48))(*(int **)(in_ECX + 4),0);
  (**(code **)(**(int **)(in_ECX + 4) + 0xa0))(*(int **)(in_ECX + 4),(undefined4 *)(in_ECX + 0x6ec))
  ;
  FUN_006e2610();
  piVar14 = (int *)(in_ECX + 0x6c4);
  iVar12 = 4;
  do {
    piVar3 = (int *)*piVar14;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      *piVar14 = 0;
    }
    FUN_005f7b40(piVar14[-4]);
    piVar14[-4] = 0;
    piVar14[0xb] = 0;
    piVar14 = piVar14 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  *(ushort *)(in_ECX + 0x6e4) = *(ushort *)(in_ECX + 0x66c);
  if (4 < *(ushort *)(in_ECX + 0x66c)) {
    *(undefined2 *)(in_ECX + 0x6e4) = 4;
  }
  uStack_ac = 0;
  if (*(short *)(in_ECX + 0x6e4) != 0) {
    piVar14 = (int *)(in_ECX + 0x6b4);
    do {
      switch(piVar14[8]) {
      case 0:
      case 1:
        iVar12 = FUN_00605800(1,1);
        break;
      case 3:
        iVar12 = FUN_00605890(1,1,10);
        break;
      default:
        goto switchD_006e2e7e_caseD_ffffffff;
      }
      *piVar14 = iVar12;
switchD_006e2e7e_caseD_ffffffff:
      if ((undefined4 *)*piVar14 != (undefined4 *)0x0) {
        piVar3 = *(int **)*piVar14;
        (**(code **)(*piVar3 + 0x48))(piVar3,0,piVar14 + 4);
      }
      uStack_ac = uStack_ac + 1;
      piVar14 = piVar14 + 1;
    } while (uStack_ac != *(ushort *)(in_ECX + 0x6e4));
  }
  puVar2 = (undefined4 *)(in_ECX + 0x690);
  uStack_6c = 0xbf800000;
  uStack_68 = 0x3f800000;
  uStack_48 = 0x3f800000;
  uStack_44 = 0x3f800000;
  uStack_40 = 0x3f800000;
  uStack_38 = 0x3f800000;
  uStack_30 = 0x3f800000;
  uStack_24 = 0x3f800000;
  uStack_20 = 0x3f800000;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_3c = 0;
  uStack_34 = 0;
  uStack_28 = 0;
  uStack_58 = 0xbf800000;
  uStack_54 = 0xbf800000;
  uStack_2c = 0xbf800000;
  FUN_006e4810(0x50,8,0,0,puVar2);
  FUN_006e4810(0x30,8,0,0,puVar1);
  pfStack_b0 = (float *)0x0;
  FUN_006e5b90(0,0x50,&pfStack_b0,0,*puVar2);
  FUN_004ef660(pfStack_b0,&uStack_6c,0x50);
  FUN_006e5bc0(*puVar2);
  FUN_006e5b90(0,0x30,&pfStack_b0,0,*puVar1);
  FUN_004ef660(pfStack_b0,&stack0xffffff64,0x30);
  FUN_006e5bc0(*puVar1);
  *(undefined4 *)(in_ECX + 0x6a0) = 0x10;
  uStack_ac = CONCAT22(uStack_ac._2_2_,in_FPUControlWord);
  _piStack_a8 = (longlong)ROUND(((double)DAT_00973904 / (double)DAT_00973900) * 16.0);
  *(int **)(in_ECX + 0x69c) = piStack_a8;
  *(int *)(in_ECX + 0x6a8) = *(int *)(in_ECX + 0x69c) << 5;
  *(int *)(in_ECX + 0x6a4) = ((int)piStack_a8 + 1) * 0x11;
  FUN_006e4810(((int)piStack_a8 + 1) * 0x154,8,0,0,(undefined4 *)(in_ECX + 0x694));
  FUN_006e46f0(*(int *)(in_ECX + 0x6a8) * 6,8,0x65,0,unaff_ESI,0);
  FUN_006e5b90(0,*(int *)(in_ECX + 0x6a4) * 0x14,&pfStack_b0,0,*(undefined4 *)(in_ECX + 0x694));
  iVar12 = 0;
  pfVar10 = pfStack_b0;
  if (*(int *)(in_ECX + 0x69c) != -1) {
    do {
      iVar11 = 0;
      if (*(int *)(in_ECX + 0x6a0) != -1) {
        uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
        fVar4 = (float)iVar12;
        if (iVar12 < 0) {
          fVar4 = fVar4 + 4.2949673e+09;
        }
        _piStack_a8 = CONCAT44(uVar15,fVar4);
        pfVar9 = pfVar10;
        do {
          uVar15 = (undefined4)((ulonglong)_piStack_a8 >> 0x20);
          fVar5 = (float)iVar11;
          if (iVar11 < 0) {
            fVar5 = fVar5 + 4.2949673e+09;
          }
          _piStack_a8 = CONCAT44(uVar15,fVar5);
          fVar6 = (float)*(int *)(in_ECX + 0x6a0);
          if (*(int *)(in_ECX + 0x6a0) < 0) {
            fVar6 = fVar6 + 4.2949673e+09;
          }
          *pfVar9 = (fVar5 / fVar6) * 2.0 - 1.0;
          fVar6 = (float)*(int *)(in_ECX + 0x69c);
          if (*(int *)(in_ECX + 0x69c) < 0) {
            fVar6 = fVar6 + 4.2949673e+09;
          }
          pfVar9[1] = 1.0 - (fVar4 / fVar6) * 2.0;
          pfVar9[2] = 0.0;
          fVar6 = (float)*(int *)(in_ECX + 0x6a0);
          if (*(int *)(in_ECX + 0x6a0) < 0) {
            fVar6 = fVar6 + 4.2949673e+09;
          }
          pfVar9[3] = fVar5 / fVar6;
          fVar5 = (float)*(int *)(in_ECX + 0x69c);
          if (*(int *)(in_ECX + 0x69c) < 0) {
            fVar5 = fVar5 + 4.2949673e+09;
          }
          iVar11 = iVar11 + 1;
          pfVar10 = pfVar9 + 5;
          pfVar9[4] = fVar4 / fVar5;
          pfVar9 = pfVar10;
        } while (iVar11 != *(int *)(in_ECX + 0x6a0) + 1);
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 != *(int *)(in_ECX + 0x69c) + 1);
  }
  FUN_006e5bc0(*(undefined4 *)(in_ECX + 0x694));
  FUN_006e5bd0(0,*(int *)(in_ECX + 0x6a8) * 6,&pfStack_b0,0,*unaff_ESI);
  uStack_ac = 0;
  pfVar10 = pfStack_b0;
  if (*(int *)(in_ECX + 0x69c) != 0) {
    do {
      iVar12 = 0;
      if (*(int *)(in_ECX + 0x6a0) != 0) {
        sVar8 = (short)uStack_ac;
        sVar13 = sVar8 + 1;
        do {
          sVar7 = (short)iVar12;
          *(short *)pfVar10 = (*(short *)(in_ECX + 0x6a0) + 1) * sVar8 + sVar7;
          *(short *)((int)pfVar10 + 2) = (*(short *)(in_ECX + 0x6a0) + 1) * sVar8 + sVar7 + 1;
          *(short *)(pfVar10 + 1) = (*(short *)(in_ECX + 0x6a0) + 1) * sVar13 + sVar7;
          *(short *)((int)pfVar10 + 6) = (*(short *)(in_ECX + 0x6a0) + 1) * sVar13 + sVar7;
          *(short *)(pfVar10 + 2) = (*(short *)(in_ECX + 0x6a0) + 1) * sVar8 + sVar7 + 1;
          *(short *)((int)pfVar10 + 10) = (*(short *)(in_ECX + 0x6a0) + 1) * sVar13 + sVar7 + 1;
          iVar12 = iVar12 + 1;
          pfVar10 = pfVar10 + 3;
        } while (iVar12 != *(int *)(in_ECX + 0x6a0));
      }
      uStack_ac = uStack_ac + 1;
    } while (uStack_ac != *(int *)(in_ECX + 0x69c));
  }
  FUN_006e5c00(*unaff_ESI);
  return;
}

