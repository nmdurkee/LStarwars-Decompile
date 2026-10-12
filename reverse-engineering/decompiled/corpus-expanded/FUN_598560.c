/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x598560; label: FUN_00598560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00598560(int param_1,int param_2)

{
  int iVar1;
  
  if (((DAT_00955fb0 != (code *)0x0) && (iVar1 = (*DAT_00955fb0)(param_1), iVar1 != 0)) &&
     ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    if (param_2 == 0) {
      return 1;
    }
    if ((*(char *)(param_1 + 0x281) != '\0') && (iVar1 = FUN_005620f0(param_1), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

