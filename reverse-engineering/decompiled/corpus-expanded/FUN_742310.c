/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x742310; label: FUN_00742310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00742310(void)

{
  short *in_ECX;
  
  if ((*(uint *)(in_ECX + 2) & 0xf0000000) == 0x10000000) {
    FUN_006e5750();
    return;
  }
  FUN_006e52e0((int)*in_ECX,&stack0x00000004,1);
  return;
}

