/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x557630; label: FUN_00557630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00557630(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    FUN_005a15e0(*(undefined4 *)(iVar1 + 0x34),param_2);
    *(uint *)(iVar1 + 0x94) =
         *(uint *)(iVar1 + 0x94) ^ ((uint)(param_2 != 0) * 2 ^ *(uint *)(iVar1 + 0x94)) & 2;
  }
  return;
}

