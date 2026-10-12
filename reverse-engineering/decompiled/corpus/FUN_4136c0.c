/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x4136c0; label: FUN_004136c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004136c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int unaff_ESI;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar1 = *(undefined4 **)(unaff_ESI + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    if (*(int *)(unaff_ESI + 0x1c) == 4) {
      iVar2 = *(int *)(unaff_ESI + 0x18);
      *(int *)(unaff_ESI + 0x18) = iVar2 + 1;
      *(undefined4 **)(unaff_ESI + 0x14) = puVar1 + iVar2 * 2;
      iVar2 = puVar1[iVar2 * 2];
      *(int *)(unaff_ESI + 0x1c) = iVar2;
      if (iVar2 == 3) {
        *(undefined4 **)(unaff_ESI + 0x14) = puVar1;
        *(undefined4 *)(unaff_ESI + 0x18) = 1;
        *(undefined4 *)(unaff_ESI + 0x1c) = *puVar1;
      }
      iVar2 = *(int *)(unaff_ESI + 0x1c);
      if (iVar2 == 0) {
        *(undefined4 *)(unaff_ESI + 0x24) = *(undefined4 *)(*(int *)(unaff_ESI + 0x14) + 4);
      }
      else if (iVar2 == 1) {
        local_30 = *(undefined4 *)(PTR_DAT_008021b4 + 0xe8);
        local_2c = *(undefined4 *)(PTR_DAT_008021b4 + 0xec);
        local_28 = *(undefined4 *)(PTR_DAT_008021b4 + 0xf0);
        local_20 = 0;
        local_1c = 0;
        local_18 = 0x43960000;
        local_14 = 0x3f800000;
        FUN_005b30a0(&local_20,&local_20,PTR_DAT_008021b4 + 0xb8);
        FUN_00413510(&local_20,&local_30,*(undefined4 *)(*(int *)(unaff_ESI + 0x14) + 4),1);
        *(undefined4 *)(unaff_ESI + 0x1c) = 4;
      }
      else if (iVar2 == 2) {
        local_30 = 0xc1200000;
        local_2c = 0xc0a00000;
        local_28 = 0xc1200000;
        local_24 = 0x3f800000;
        uVar4 = FUN_0054fa60();
        FUN_005b3690(&local_30,&local_30,uVar4);
        FUN_005b30a0(&local_30,&local_30,PTR_DAT_008021b4 + 0xb8);
        local_20 = 0;
        local_1c = 0;
        local_18 = 0x43c80000;
        local_14 = 0x3f800000;
        FUN_005b30a0(&local_20,&local_20,PTR_DAT_008021b4 + 0xb8);
        FUN_00413510(&local_30,&local_20,*(undefined4 *)(*(int *)(unaff_ESI + 0x14) + 4),0);
        *(undefined4 *)(unaff_ESI + 0x1c) = 4;
      }
    }
    if ((*(int *)(unaff_ESI + 0x1c) == 0) &&
       (fVar3 = *(float *)(unaff_ESI + 0x24) - _DAT_00925018, *(float *)(unaff_ESI + 0x24) = fVar3,
       fVar3 <= 0.0)) {
      *(undefined4 *)(unaff_ESI + 0x1c) = 4;
    }
  }
  return;
}

