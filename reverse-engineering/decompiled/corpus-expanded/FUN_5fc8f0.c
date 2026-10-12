/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fc8f0; label: FUN_005fc8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint * FUN_005fc8f0(void)

{
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  return DAT_009736e0;
}

