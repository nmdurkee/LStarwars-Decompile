/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b9160; label: FUN_006b9160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9160(undefined4 param_1)

{
  int iVar1;
  
  DAT_02973a40 = DAT_02973a40 + -1;
  FUN_004f75f0(param_1,0xf);
  iVar1 = FUN_004f6d10(param_1);
  FUN_004f6de0(param_1,*(int *)(&DAT_02973a1c + DAT_02973a40 * 4) + 4,
               *(int *)(&DAT_02973a1c + DAT_02973a40 * 4) + 4 >> 0x1f,0);
  FUN_004f04b0(param_1,iVar1 - *(int *)(&DAT_02973a1c + DAT_02973a40 * 4));
  FUN_004f6de0(param_1,iVar1,iVar1 >> 0x1f,0);
  return;
}

