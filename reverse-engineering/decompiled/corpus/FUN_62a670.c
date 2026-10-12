/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a670; label: FUN_0062a670
 */

float10 FUN_0062a670(int param_1,int param_2)

{
  float10 fVar1;
  
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    fVar1 = (float10)FUN_005ca470(*(undefined4 *)(*(int *)(param_1 + 0xc) + param_2 * 4));
    return fVar1;
  }
  return (float10)0;
}

