/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6bb310; label: FUN_006bb310
 */

void FUN_006bb310(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (DAT_02973a60 == 1) {
    FUN_00607ec0(0xc,5,(&DAT_02973a10)[DAT_02973a64],DAT_02973a68);
    DAT_02973a60 = 3;
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
  FUN_006b8510();
  uVar1 = param_3[1];
  puVar3 = (undefined4 *)*DAT_02854d10;
  uVar2 = param_3[2];
  *puVar3 = *param_3;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  return;
}

