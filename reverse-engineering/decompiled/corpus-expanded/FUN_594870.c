/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x594870; label: FUN_00594870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00594870(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = DAT_0095587c;
  iVar1 = FUN_00594250(param_1,DAT_0095587c,_DAT_00955878);
  if (iVar1 == -1) {
    return 0;
  }
  if ((DAT_0093b288 != 0) && ((*(byte *)(DAT_0093b288 + param_1) & 2) != 0))
  goto switchD_005948b8_caseD_0;
  iVar2 = iVar2 + iVar1 * 0x1c;
  switch(*(undefined1 *)(iVar2 + 2)) {
  case 0:
    break;
  default:
    goto switchD_005948b8_caseD_1;
  case 2:
    if (*(char *)(iVar2 + 3) == -1) {
      return 0;
    }
    bVar3 = *(char *)(DAT_0095136c + 1 + *(char *)(iVar2 + 3) * 0xc) == '\0';
    goto LAB_00594919;
  case 3:
    iVar2 = FUN_0059b760();
    if (iVar2 != DAT_00956294) {
      return 0;
    }
    break;
  case 4:
    iVar2 = FUN_0059a190(DAT_0095136c);
    goto LAB_00594917;
  case 6:
    if (DAT_0093b2b4 == 0) {
      return 0;
    }
    if ((ushort)*(byte *)(DAT_0093b2b4 + 2) < *(ushort *)(iVar2 + 10)) {
      return 0;
    }
    break;
  case 7:
    iVar2 = FUN_0055c880();
LAB_00594917:
    bVar3 = iVar2 == 0;
LAB_00594919:
    if (bVar3) {
switchD_005948b8_caseD_1:
      return 0;
    }
  }
switchD_005948b8_caseD_0:
  return DAT_0095587c + iVar1 * 0x1c;
}

