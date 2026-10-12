/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6ba7d0; label: FUN_006ba7d0
 */

void FUN_006ba7d0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (DAT_02973a60 == 1) {
    FUN_00607ec0(0xe,5,(&DAT_02973a10)[DAT_02973a64],DAT_02973a68);
    DAT_02973a60 = 2;
  }
  FUN_006b8510();
  uVar1 = param_1[1];
  puVar3 = (undefined4 *)*DAT_02854d10;
  uVar2 = param_1[2];
  *puVar3 = *param_1;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006b8510();
  uVar1 = param_2[1];
  puVar3 = (undefined4 *)*DAT_02854d10;
  uVar2 = param_2[2];
  *puVar3 = *param_2;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  return;
}

