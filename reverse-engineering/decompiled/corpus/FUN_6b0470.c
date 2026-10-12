/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6b0470; label: FUN_006b0470
 */

undefined4 FUN_006b0470(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x40) + 0x68) + 0x50);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    return 1;
  }
  return 0;
}

