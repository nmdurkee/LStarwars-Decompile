/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x594b20; label: FUN_00594b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00594b20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < _DAT_00955878) {
    iVar2 = 0;
    iVar1 = DAT_0095587c;
    do {
      if ((param_1 == 0) || (*(char *)(iVar2 + 2 + iVar1) == '\x01')) {
        FUN_00594a90((int)*(short *)(iVar2 + iVar1));
        iVar1 = DAT_0095587c;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x1c;
    } while (iVar3 < _DAT_00955878);
  }
  return;
}

