/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x599a10; label: FUN_00599a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00599a10(uint *param_1)

{
  DAT_00956048 = *param_1 + 3 & 0xfffffffc;
  *param_1 = DAT_00956048;
  *param_1 = *param_1 + DAT_0093b278 * 4;
  return;
}

