/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c3900; label: FUN_004c3900
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c3900(void)

{
  int iVar1;
  undefined *puVar2;
  
  switch(DAT_008801ac) {
  case 0:
    iVar1 = DAT_008800c8;
    puVar2 = DAT_0088047c;
    break;
  case 1:
    iVar1 = DAT_0087bdf8;
    puVar2 = DAT_00880478;
    break;
  case 2:
    iVar1 = DAT_0087bf0c;
    puVar2 = DAT_00880480;
    break;
  default:
    goto switchD_004c390a_caseD_3;
  case 4:
    iVar1 = DAT_0087ffa4;
    puVar2 = DAT_00880488;
    break;
  case 5:
    puVar2 = &DAT_0087c578;
    iVar1 = DAT_0087bee0;
    goto LAB_004c3920;
  }
  if (puVar2 != (undefined *)0x0) {
LAB_004c3920:
    if (iVar1 != -1) {
      iVar1 = FUN_004c2730(puVar2,iVar1);
      if (iVar1 == -1) {
        FUN_00681f40("Shop_NotEnufMuny",&DAT_00880444);
        return;
      }
      if (iVar1 == 1) {
        _DAT_0087bd78 = 0;
      }
    }
  }
switchD_004c390a_caseD_3:
  return;
}

