/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4eab80; label: FUN_004eab80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004eab80(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  char *_Format;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  DAT_0087aa5c = FUN_005aac00(DAT_0095df4c,"ShowHearts",0);
  DAT_0087aa60 = FUN_005aac00(DAT_0095df4c,"ElectricFloor",0);
  piVar1 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"obstacle21");
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    DAT_0087a908 = *piVar1;
  }
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force15");
  DAT_0087a970 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force16");
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"lift_force_lnull1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"lift_force_rnull1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"lift_main1",1);
  DAT_0087a95c = FUN_0051acd0(*(undefined4 *)(param_1 + 0x2ae8),"ElectricFloor");
  _DAT_0088aae4 = 0;
  *DAT_0088a590 = 0;
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8);
  iVar4 = 0;
  lVar5 = 0;
  lVar6 = 0;
  if (*(char *)(iVar2 + 0x14) != '\0') {
    iVar3 = 0;
    lVar6 = 0;
    lVar5 = 0;
    do {
      DAT_0088a634 = (undefined4)((ulonglong)lVar5 >> 0x20);
      DAT_0088a630 = (undefined4)lVar5;
      DAT_0088a5a4 = (undefined4)((ulonglong)lVar6 >> 0x20);
      DAT_0088a5a0 = (undefined4)lVar6;
      iVar2 = FUN_004f8b10(*(undefined4 *)(*(int *)(iVar2 + 0x88) + iVar3),"electric_on");
      if (iVar2 == 0) {
        lVar5 = __allshl();
        lVar6 = CONCAT44(DAT_0088a5a4,DAT_0088a5a0);
      }
      else {
        iVar2 = FUN_004f8b10(*(undefined4 *)
                              (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8) +
                                       0x88) + iVar3),"electric_off");
        lVar6 = CONCAT44(DAT_0088a5a4,DAT_0088a5a0);
        lVar5 = CONCAT44(DAT_0088a634,DAT_0088a630);
        if (iVar2 == 0) {
          lVar6 = __allshl();
          lVar5 = CONCAT44(DAT_0088a634,DAT_0088a630);
        }
      }
      if ((lVar5 != 0) && (lVar6 != 0)) break;
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8);
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x28;
    } while (iVar4 < (int)(uint)*(byte *)(iVar2 + 0x14));
  }
  iVar2 = 0;
  DAT_0088aadc = &DAT_0087adfc;
  iVar4 = 0;
  do {
    DAT_0088a634 = (undefined4)((ulonglong)lVar5 >> 0x20);
    DAT_0088a630 = (undefined4)lVar5;
    DAT_0088a5a4 = (undefined4)((ulonglong)lVar6 >> 0x20);
    DAT_0088a5a0 = (undefined4)lVar6;
    if (iVar2 < 9) {
      _Format = "elecpad_0%d_on";
    }
    else {
      _Format = "elecpad_%d_on";
    }
    iVar2 = iVar2 + 1;
    _sprintf(local_24,_Format,iVar2);
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),DAT_0088aadc + iVar4,local_24,1);
    lVar5 = CONCAT44(DAT_0088a634,DAT_0088a630);
    lVar6 = CONCAT44(DAT_0088a5a4,DAT_0088a5a0);
    iVar4 = iVar4 + 0xc;
  } while (iVar4 < 0xf0);
  piVar1 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"eFloor_AlwaysOn");
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    DAT_0087a90c = *piVar1;
  }
  piVar1 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"eFloor_AlwaysOf");
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    DAT_0087a910 = *piVar1;
  }
  piVar1 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"eFloor_OnOff");
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    DAT_0087a914 = *piVar1;
  }
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

