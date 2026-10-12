/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b16e0; label: FUN_005b16e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b16e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00633440(0x24,1);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00633550(4);
    *puVar1 = &PTR_FUN_00763f4c;
    DAT_0095e418 = puVar1;
    return;
  }
  DAT_0095e418 = (undefined4 *)0x0;
  return;
}

