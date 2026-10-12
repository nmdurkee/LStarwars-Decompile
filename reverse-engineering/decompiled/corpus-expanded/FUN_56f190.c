/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56f190; label: FUN_0056f190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056f190(void)

{
  int iVar1;
  char *pcVar2;
  char in_DL;
  
  iVar1 = 0;
  if (*(ushort *)(PTR_PTR_008033b0 + 8) != 0) {
    pcVar2 = (char *)(*(int *)PTR_PTR_008033b0 + 0xc);
    do {
      if (*pcVar2 == in_DL) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 0x38;
    } while (iVar1 < (int)(uint)*(ushort *)(PTR_PTR_008033b0 + 8));
  }
  return 0;
}

