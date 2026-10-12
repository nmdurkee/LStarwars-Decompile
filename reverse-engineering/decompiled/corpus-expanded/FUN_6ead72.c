/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6ead72; label: FUN_006ead72
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_006ead72(void)

{
  int iVar1;
  
  iVar1 = FUN_006f0395();
  if (iVar1 == 0) {
    return &DAT_00829a4c;
  }
  return (undefined *)(iVar1 + 0xc);
}

