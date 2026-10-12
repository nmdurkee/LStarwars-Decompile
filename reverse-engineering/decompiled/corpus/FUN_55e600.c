/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e600; label: FUN_0055e600
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

