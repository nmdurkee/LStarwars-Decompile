/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x742340; label: FUN_00742340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00742340(void)

{
  int in_ECX;
  
  switch((*(int *)(in_ECX + 4) << 4) >> 0x1c) {
  case 1:
    FUN_00741f90();
    return;
  case 2:
    FUN_00741fd0();
    return;
  case 3:
    FUN_00742010();
    return;
  default:
    return;
  }
}

