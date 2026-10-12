/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x65a700; label: FUN_0065a700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065a700(undefined4 param_1,int param_2)

{
  DAT_029620f4 = 0;
  DAT_02924afc = -1;
  if (*(int *)(param_2 + 0xc) != 99999) {
    DAT_02924afc = *(int *)(param_2 + 0xc);
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

