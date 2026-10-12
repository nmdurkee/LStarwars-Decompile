/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x741f90; label: FUN_00741f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00741f90(int param_1,undefined4 param_2,undefined4 param_3)

{
  short *in_ECX;
  
  if ((*(uint *)(in_ECX + 2) & 0xf0000000) == 0x10000000) {
    FUN_006e5750();
    return;
  }
  FUN_006e52e0(*in_ECX + param_1,param_3,param_2);
  return;
}

