/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x742250; label: FUN_00742250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00742250(void)

{
  int *in_EAX;
  int iVar1;
  int in_ECX;
  int unaff_ESI;
  
  if ((in_ECX != 0) && (in_EAX != (int *)0x0)) {
    iVar1 = (**(code **)(*in_EAX + 0x24))();
    if ((iVar1 != 0) && (-1 < *(int *)(unaff_ESI + 0x14))) {
      *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 0x10);
    }
    return iVar1;
  }
  return 0;
}

