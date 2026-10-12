/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x495740; label: FUN_00495740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00495740(void)

{
  undefined1 *puVar1;
  
  FUN_004f4c10(1);
  puVar1 = &DAT_0093d516;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x10;
  } while ((int)puVar1 < 0x93d596);
  FUN_004f4920();
  return;
}

