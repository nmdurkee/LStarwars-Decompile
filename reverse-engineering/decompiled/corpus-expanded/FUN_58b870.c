/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b870; label: FUN_0058b870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0058b870(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0055ce20(param_1,1,1,1,0);
  if (((iVar1 == 0) || ((*(uint *)(iVar1 + 0xeec) & 0x8000000) == 0)) ||
     ((*(char *)(iVar1 + 0x28b) == '\0' && (*(char *)(iVar1 + 0x107f) != '\0')))) {
    iVar1 = 0;
  }
  return iVar1;
}

