/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x427ad0; label: FUN_00427ad0
 */

float10 FUN_00427ad0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x7b5) == '#') {
    iVar1 = FUN_006e6b90();
    return (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
  }
  if (*(char *)(param_1 + 0x7b5) == '$') {
    iVar1 = FUN_006e6b90();
    return (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
  }
  return (float10)1;
}

