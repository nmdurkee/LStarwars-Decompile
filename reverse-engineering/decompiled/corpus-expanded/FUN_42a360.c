/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a360; label: FUN_0042a360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0042a360(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(PTR_DAT_00802c54 + 0x128);
  if ((((iVar1 != DAT_0087b188) || (*(char *)(param_1 + 0x285) != '\x0e')) &&
      ((iVar1 != DAT_0087b244 ||
       (((*(char *)(param_1 + 0x285) != '\x18' || ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0)) ||
        (*(char *)(param_1 + 0x283) != -1)))))) &&
     ((iVar1 != DAT_0087b1c0 || (*(short *)(param_1 + 0x1064) != DAT_007f1918)))) {
    return 0;
  }
  return 1;
}

