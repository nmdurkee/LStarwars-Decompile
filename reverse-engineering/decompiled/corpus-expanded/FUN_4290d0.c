/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x4290d0; label: FUN_004290d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004290d0(int param_1)

{
  undefined4 uVar1;
  
  if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) != '\0') ||
     (uVar1 = 0x7f, (*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0)) {
    uVar1 = 0x11;
  }
  return uVar1;
}

