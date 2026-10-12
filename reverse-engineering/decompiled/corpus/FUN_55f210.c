/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f210; label: FUN_0055f210
 */

undefined4 FUN_0055f210(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0056e0f0(0x4000);
  if ((iVar1 == 0) && ((param_1 == 0 || (*(float *)(param_1 + 0xdec) <= 0.0)))) {
    return 0;
  }
  return 1;
}

