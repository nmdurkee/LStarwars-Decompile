/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e8160; label: FUN_004e8160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e8160(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if ((DAT_0087aa20 == '\0') && (iVar1 = FUN_005cfd60(&DAT_0087aad8), iVar1 != 0)) {
    uVar2 = FUN_005cf9e0(&DAT_0087aad8);
    FUN_00681f40("env_ctrl_desk_on",uVar2);
    DAT_0087aa20 = '\x01';
  }
  _DAT_00803574 = 0x2002;
  if ((DAT_0087a934 == 0) || ((*(byte *)(DAT_0087a934 + 0x62) & 2) == 0)) {
    puVar3 = &DAT_0087aae4;
    do {
      iVar1 = FUN_005cfac0(puVar3);
      if (((iVar1 != 0) && (iVar1 = FUN_005d0420(puVar3), iVar1 != 0)) &&
         (1.0 < *(float *)(iVar1 + 0x4c))) {
        uVar2 = FUN_005cf9e0(puVar3);
        FUN_00681f40("env_steam_lp",uVar2);
        _DAT_00803574 = _DAT_00803574 | 0x4042;
      }
      puVar3 = puVar3 + 0xc;
    } while ((int)puVar3 < 0x87aafd);
  }
  if (((DAT_0087a96c != (int *)0x0) && (DAT_0087aa60 != 0)) &&
     ((*(float *)(DAT_0087aa60 + 0x28) == 0.0 &&
      ((*DAT_0087a96c != 0 && (*(char *)(*DAT_0087a96c + 0x6d) == '\x02')))))) {
    *(undefined4 *)(DAT_0087aa60 + 0x28) = 0x3f800000;
  }
  return;
}

