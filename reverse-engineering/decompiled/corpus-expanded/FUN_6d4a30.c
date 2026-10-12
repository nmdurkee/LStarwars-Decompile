/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4a30; label: FUN_006d4a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006d4a30(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x67e4)) {
    pcVar2 = (char *)(in_ECX + 0x67f1);
    do {
      if ((pcVar2[-1] == param_2) && (*pcVar2 == param_1)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 6;
    } while (iVar1 < *(int *)(in_ECX + 0x67e4));
  }
  return -1;
}

