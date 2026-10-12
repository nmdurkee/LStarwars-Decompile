/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b3060; label: FUN_005b3060
 */

void FUN_005b3060(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_ECX;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  
  fVar1 = *in_ECX;
  fVar2 = in_ECX[1];
  fVar3 = in_ECX[2];
  fVar4 = in_ECX[3];
  auVar5._0_4_ = fVar3 * fVar3 + fVar1 * fVar1;
  auVar5._4_4_ = fVar4 * fVar4 + fVar2 * fVar2;
  auVar5._8_4_ = fVar1 * fVar1 + fVar3 * fVar3;
  auVar5._12_4_ = fVar2 * fVar2 + fVar4 * fVar4;
  auVar6._4_4_ = auVar5._0_4_ + auVar5._4_4_;
  auVar6._0_4_ = auVar5._4_4_ + auVar5._0_4_;
  auVar6._8_4_ = auVar5._12_4_ + auVar5._8_4_;
  auVar6._12_4_ = auVar5._8_4_ + auVar5._12_4_;
  auVar6 = rsqrtps(auVar5,auVar6);
  *param_1 = auVar6._0_4_ * fVar1;
  param_1[1] = auVar6._4_4_ * fVar2;
  param_1[2] = auVar6._8_4_ * fVar3;
  param_1[3] = auVar6._12_4_ * fVar4;
  return;
}

