/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x741f70; label: FUN_00741f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00741f70(void)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb8 + (in_EAX & 0xff) * 4);
  if (iVar1 != 0) {
    iVar1 = FUN_005e5310(iVar1);
    return *(undefined4 *)(iVar1 + 0x24);
  }
  return 0;
}

