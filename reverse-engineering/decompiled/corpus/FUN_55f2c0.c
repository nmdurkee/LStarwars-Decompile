/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f2c0; label: FUN_0055f2c0
 */

undefined4 FUN_0055f2c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0xf0) & 1) == 0) {
    if ((*(uint *)(param_1 + 0xf0) & 2) == 0) {
      return 0;
    }
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  iVar1 = (&DAT_0093d7f0)[iVar1];
  iVar2 = FUN_0056e0f0(2);
  if ((iVar2 == 0) && ((iVar1 == 0 || (*(float *)(iVar1 + 0xdec) <= 0.0)))) {
    return 0;
  }
  return 1;
}

