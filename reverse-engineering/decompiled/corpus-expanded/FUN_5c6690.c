/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6690; label: FUN_005c6690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint * FUN_005c6690(void)

{
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  return DAT_009736e0;
}

