/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4535e0; label: FUN_004535e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004535e0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  undefined4 *puVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  float10 fVar8;
  
  if (((param_3 == 0) || (piVar6 = *(int **)(param_3 + 0xd0), piVar6 == (int *)0x0)) ||
     (*piVar6 == 0)) {
    return 1;
  }
  iVar4 = *piVar6;
  if ((param_6 != 0) && (iVar7 = 0, 0 < param_5)) {
    do {
      iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"name=");
      if ((iVar5 != 0) &&
         ((piVar6 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_007fd164,
                                        iVar5 + 5), piVar6 != (int *)0x0 &&
          (iVar5 = *piVar6, iVar5 != 0)))) {
        *(int *)(param_2 + 0x6c) = iVar5;
        puVar1 = (undefined4 *)(param_2 + 0x78);
        *puVar1 = *(undefined4 *)(iVar5 + 0x1c);
        *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(iVar5 + 0x20);
        *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(iVar5 + 0x24);
        fVar8 = (float10)FUN_005506f0(0,puVar1,0x40a00000,0xffffffff);
        if ((float)fVar8 != 2e+06) {
          *(float *)(param_2 + 0x7c) = (float)fVar8;
        }
        FUN_0043e040(param_1,puVar1,param_2 + 0x84,puVar1,0,0xff);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_5);
  }
  iVar7 = *(int *)(param_2 + 0x6c);
  if ((((iVar7 != 0) && (bVar3 = *(byte *)(iVar7 + 0x3c), (bVar3 & 1) != 0)) && ((bVar3 & 2) != 0))
     && ((bVar3 & 8) == 0)) {
    FUN_0052fcb0(param_3,param_2 + 0x78,0,param_2 + 0x84,1,0);
    iVar5 = FUN_004cd110(iVar4,iVar7);
    if (iVar5 == 0) {
      if ((DAT_0093b2a4 != 0) &&
         (param_7 = *(float *)(param_2 + 0x9c) - param_7, *(float *)(param_2 + 0x9c) = param_7,
         param_7 < 0.0)) {
        *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
        puVar2 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
        *puVar2 = *puVar2 | DAT_0080228c;
        return 0;
      }
    }
    else {
      fVar8 = (float10)FUN_005b3c50(param_3 + 0x14c,param_2 + 0x78,0);
      if ((float)fVar8 < _DAT_00801c6c * _DAT_00801c6c) {
        *(int *)(param_3 + 0x1e4) = iVar7 + 0x10;
        FUN_0055dd70(iVar4,iVar7,2,1,0);
      }
    }
    return 0;
  }
  return 1;
}

