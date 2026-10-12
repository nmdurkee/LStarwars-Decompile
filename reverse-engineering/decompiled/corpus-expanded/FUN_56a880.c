/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56a880; label: FUN_0056a880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0056a880(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (((param_1 != 0) && (param_2 != -1)) && (param_2 <= *(int *)(param_1 + 0x50bc))) {
    uVar1 = param_2 * 0x100 + *(int *)(param_1 + 0x50c4) + 0xd8;
    iVar2 = FUN_004f1ff0(uVar1);
    return -(uint)(iVar2 != 0) & uVar1;
  }
  return 0;
}

