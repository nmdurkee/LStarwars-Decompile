/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4533c0; label: FUN_004533c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004533c0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  float10 fVar8;
  
  if (((param_3 == 0) || (piVar5 = *(int **)(param_3 + 0xd0), piVar5 == (int *)0x0)) ||
     (*piVar5 == 0)) {
    return 1;
  }
  iVar3 = *piVar5;
  if ((param_6 != 0) && (iVar7 = 0, 0 < param_5)) {
    do {
      iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"name=");
      if (((iVar4 != 0) &&
          ((piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_007f90d0,
                                         iVar4 + 5), piVar5 != (int *)0x0 &&
           (iVar4 = *piVar5, iVar4 != 0)))) &&
         (*(int *)(param_2 + 0x6c) = iVar4, (*(byte *)(iVar4 + 0x62) & 2) == 0)) {
        puVar1 = (undefined4 *)(param_2 + 0x78);
        *puVar1 = *(undefined4 *)(iVar4 + 100);
        *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(iVar4 + 0x68);
        *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(iVar4 + 0x6c);
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
  if (iVar7 == 0) {
    return 1;
  }
  if ((*(byte *)(iVar7 + 0x62) & 2) != 0) {
    return 1;
  }
  FUN_0052fcb0(param_3,param_2 + 0x78,0,param_2 + 0x84,1,0);
  iVar4 = FUN_0046dce0(iVar3,iVar7);
  if (iVar4 == 0) {
    if ((DAT_0093b2a4 == 0) ||
       (param_7 = *(float *)(param_2 + 0x9c) - param_7, *(float *)(param_2 + 0x9c) = param_7,
       0.0 <= param_7)) goto LAB_004535a1;
    *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
    uVar6 = DAT_0080228c;
  }
  else {
    fVar8 = (float10)FUN_005b3c50(param_3 + 0x14c,param_2 + 0x78,0);
    if (_DAT_00801c6c * _DAT_00801c6c <= (float)fVar8) goto LAB_004535a1;
    *(int *)(param_3 + 0x1e4) = iVar7 + 0x50;
    uVar6 = DAT_00802280;
  }
  puVar2 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
  *puVar2 = *puVar2 | uVar6;
LAB_004535a1:
  if ((*(char *)(iVar3 + 0x7b5) == '\v') && (*(int *)(iVar3 + 0x798) == iVar7)) {
    return 1;
  }
  return 0;
}

