/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x560b40; label: FUN_00560b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00560b40(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_00947cb8;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x114;
  } while ((int)puVar1 < 0x9506b8);
  return;
}

