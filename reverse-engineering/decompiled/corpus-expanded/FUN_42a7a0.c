/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42a7a0; label: FUN_0042a7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0042a7a0(void)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  if ((*(int *)(iVar1 + 0x128) == DAT_0087b1bc) && (PTR_DAT_008021b4[1] == '\x05')) {
    return 1;
  }
  return 0;
}

