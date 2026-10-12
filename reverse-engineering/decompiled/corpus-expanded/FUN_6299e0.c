/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x6299e0; label: FUN_006299e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006299e0(void)

{
  if (DAT_02912e88 != 0) {
    DAT_02910ca4 = 0;
  }
  if ((DAT_02912e68 == 0) || (DAT_02912e64 == 0)) {
    FUN_006278a0();
  }
  else if (*(code **)(DAT_02912e64 + 0x30) != (code *)0x0) {
    (**(code **)(DAT_02912e64 + 0x30))();
  }
  if ((DAT_02912e88 != 0) && (DAT_02912e84 != 0)) {
    FUN_0061f510();
    return;
  }
  return;
}

