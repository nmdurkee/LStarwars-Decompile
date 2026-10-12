/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x6101f0; label: FUN_006101f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006101f0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_0060f4b0();
  for (iVar1 = *(int *)(in_ECX + 0x94); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    FUN_0060f4c0(iVar1 + 0x18);
  }
                    /* WARNING: Could not recover jumptable at 0x00610233. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)**(undefined4 **)(in_ECX + 0xa0))();
  return;
}

