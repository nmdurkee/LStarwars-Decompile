/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5dee40; label: FUN_005dee40
 */

void FUN_005dee40(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_004ffaa0(DAT_00973fa4);
  FUN_006039b0(param_1);
  iVar1 = 0;
  if (0 < DAT_009739b8) {
    piVar4 = &DAT_009739bc;
    do {
      if ((undefined4 *)*piVar4 == param_1) {
        FUN_005c1300(*param_1);
        iVar1 = 0;
        if ((int)param_1[0x18] < 1) goto LAB_005deee0;
        iVar7 = 0;
        goto LAB_005deea0;
      }
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar1 < DAT_009739b8);
  }
  FUN_005c12e0();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
LAB_005deea0:
  iVar3 = DAT_00973ecc;
  if (DAT_00973ecc == param_1[0x19] + iVar7) {
LAB_005deebd:
    DAT_00973ecc = *(int *)(iVar3 + 8);
  }
  else {
    do {
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar2 + 8);
    } while (iVar3 != param_1[0x19] + iVar7);
    if (iVar2 == 0) goto LAB_005deebd;
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar3 + 8);
  }
  DAT_00973ec8 = DAT_00973ec8 + -1;
  iVar1 = iVar1 + 1;
  iVar7 = iVar7 + 0x24;
  if ((int)param_1[0x18] <= iVar1) {
LAB_005deee0:
    iVar1 = param_1[0x23];
    if (iVar1 != 0) {
      if (DAT_00973fa8 == iVar1) {
        DAT_00973fa8 = *(int *)(iVar1 + 0xc);
      }
      else {
        iVar7 = *(int *)(DAT_00973fa8 + 0xc);
        iVar3 = DAT_00973fa8;
        while (iVar7 != iVar1) {
          iVar3 = *(int *)(iVar3 + 0xc);
          iVar7 = *(int *)(iVar3 + 0xc);
        }
        *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(iVar3 + 0xc) + 0xc);
      }
    }
    iVar1 = 0;
    if (0 < DAT_009739b8) {
      puVar5 = &DAT_009739bc;
      do {
        (&DAT_009739bc)[iVar1 - iVar6] = *puVar5;
        if ((undefined4 *)*puVar5 == param_1) {
          iVar6 = iVar6 + 1;
        }
        iVar1 = iVar1 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar1 < DAT_009739b8);
      if (iVar6 != 0) {
        DAT_009739b8 = DAT_009739b8 + -1;
      }
    }
    FUN_004ffac0();
    return;
  }
  goto LAB_005deea0;
}

