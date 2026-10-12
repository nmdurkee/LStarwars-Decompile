/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b8fc0; label: FUN_004b8fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004b8fc0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x800) != 0) {
    return 1;
  }
  iVar2 = 0x4c;
  do {
    if (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + iVar2) != 0) {
      iVar1 = FUN_00552020(param_1 + 0x80,*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + iVar2),0,0,
                           0);
      if (iVar1 == 0) {
        return 1;
      }
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x5d);
  return 0;
}

