/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x6299a0; label: FUN_006299a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006299a0(int *param_1)

{
  if (DAT_02912e5c != 0) {
    FUN_00627820();
  }
  if (DAT_02912e60 != (int *)0x0) {
    *(int **)((int)DAT_02912e60 + 4) = param_1;
  }
  *param_1 = (int)DAT_02912e60;
  param_1[1] = 0;
  DAT_02912e60 = param_1;
  return 1;
}

