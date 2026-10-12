/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c11c0; label: FUN_004c11c0
 */

void FUN_004c11c0(void)

{
  undefined4 *puVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [2];
  undefined4 local_4;
  
  DAT_0087bba0 = (short *)FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),"shelf_top1");
  DAT_008800dc = (short *)FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),"shelf_bottom");
  DAT_0087beb4 = (short *)FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),"shelf_6");
  psVar3 = DAT_008800dc;
  psVar2 = DAT_0087bba0;
  if (((DAT_0087bba0 != (short *)0x0) && (DAT_008800dc != (short *)0x0)) &&
     (DAT_0087beb4 != (short *)0x0)) {
    iVar4 = (int)*DAT_0087beb4;
    iVar8 = (int)*DAT_008800dc;
    iVar9 = (int)*DAT_0087bba0;
    _memset(&DAT_00880420,0,0x54);
    _memset(&DAT_00880158,0,0x48);
    _memset(&DAT_00880108,0,0x48);
    if (0 < iVar9) {
      iVar6 = 0;
      iVar7 = iVar9;
      do {
        iVar5 = *(int *)(psVar2 + 4) + iVar6;
        *(undefined4 *)((int)&DAT_00880158 + iVar6) = *(undefined4 *)(*(int *)(psVar2 + 4) + iVar6);
        *(undefined4 *)((int)&DAT_0088015c + iVar6) = *(undefined4 *)(iVar5 + 4);
        *(undefined4 *)((int)&DAT_00880160 + iVar6) = *(undefined4 *)(iVar5 + 8);
        iVar6 = iVar6 + 0xc;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    if (0 < iVar8) {
      iVar7 = 0;
      do {
        iVar6 = *(int *)(psVar3 + 4) + iVar7;
        *(undefined4 *)((int)&DAT_00880420 + iVar7) = *(undefined4 *)(*(int *)(psVar3 + 4) + iVar7);
        *(undefined4 *)((int)&DAT_00880424 + iVar7) = *(undefined4 *)(iVar6 + 4);
        *(undefined4 *)((int)&DAT_00880428 + iVar7) = *(undefined4 *)(iVar6 + 8);
        iVar7 = iVar7 + 0xc;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    if (0 < iVar4) {
      iVar8 = 0;
      do {
        iVar7 = *(int *)(DAT_0087beb4 + 4) + iVar8;
        *(undefined4 *)((int)&DAT_00880108 + iVar8) =
             *(undefined4 *)(*(int *)(DAT_0087beb4 + 4) + iVar8);
        *(undefined4 *)((int)&DAT_0088010c + iVar8) = *(undefined4 *)(iVar7 + 4);
        *(undefined4 *)((int)&DAT_00880110 + iVar8) = *(undefined4 *)(iVar7 + 8);
        iVar8 = iVar8 + 0xc;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    puVar1 = *(undefined4 **)(psVar2 + 4);
    local_24 = *puVar1;
    local_20 = puVar1[1];
    local_1c = puVar1[2];
    puVar1 = (undefined4 *)(*(int *)(psVar2 + 4) + iVar9 * 0xc);
    local_18 = *puVar1;
    local_14 = puVar1[1];
    local_10 = puVar1[2];
    FUN_005b3800(local_c,&local_18,&local_24);
    DAT_008804a0 = FUN_005be2d0(local_c[0],local_4);
  }
  return;
}

