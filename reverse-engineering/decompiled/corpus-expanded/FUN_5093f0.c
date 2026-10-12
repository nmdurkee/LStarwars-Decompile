/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x5093f0; label: FUN_005093f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005093f0(int param_1)

{
  _DAT_00921d18 = 0x41700000;
  _DAT_00921d1c = 3;
  *(undefined2 *)(param_1 + 10) = 1;
  return;
}

