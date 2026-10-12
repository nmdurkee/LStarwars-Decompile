/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x7426d0; label: FUN_007426d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007426d0(undefined4 param_1)

{
  short *in_ECX;
  
  if ((*(uint *)(in_ECX + 2) & 0xf0000000) == 0x10000000) {
    FUN_006e5750();
    return;
  }
  FUN_006e52e0((int)*in_ECX,param_1,1);
  return;
}

