/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a35c0; label: FUN_005a35c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a35c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_0095da3c;
  if (DAT_0095da3c != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*DAT_0095da3c;
    *DAT_0095da3c = DAT_0095da40;
    DAT_0095da3c = puVar2;
    if (DAT_0095da40 != (undefined4 *)0x0) {
      DAT_0095da40[1] = puVar1;
    }
    puVar1[1] = 0;
    DAT_0095da40 = puVar1;
    puVar1[2] = 0;
  }
  return;
}

