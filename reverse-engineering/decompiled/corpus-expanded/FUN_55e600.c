/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55e600; label: FUN_0055e600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055e600(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xca4);
  if ((*(int *)(iVar1 + 0x54) != 0) && (*(float *)(iVar1 + 0x28) != 0.0)) {
    iVar1 = FUN_00550040(*(short *)(iVar1 + 0x26) + *(short *)(PTR_DAT_008021b4 + 0x1fc),
                         *(undefined2 *)(param_1 + 0x27a));
    if ((iVar1 < -0x4000) || (0x4000 < iVar1)) {
      return 1;
    }
  }
  return 0;
}

