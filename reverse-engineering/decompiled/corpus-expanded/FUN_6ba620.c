/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba620; label: FUN_006ba620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba620(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  if (DAT_02973a3c != 0) {
    FUN_00681e90(*(undefined4 *)(param_2 + 0xc),0);
    puVar1 = (undefined *)FUN_00650e90(*(undefined4 *)(param_2 + 0xc));
    if (puVar1 == (undefined *)0x0) {
      puVar1 = &DAT_00763b90;
    }
    FUN_0061e530(*(undefined4 *)(DAT_02973a3c + 4),puVar1);
    FUN_006ba280(puVar1);
    FUN_006279f0(param_1);
    FUN_00624220(param_1);
  }
  return;
}

