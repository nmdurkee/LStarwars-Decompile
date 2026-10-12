/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a7ef0; label: FUN_006a7ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006a7ef0(float param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  float10 fVar4;
  float10 fVar5;
  double dVar6;
  
  uVar3 = 0;
  if (param_1 < 0.0) {
    param_1 = -param_1;
    uVar3 = 0x80000000;
  }
  fVar4 = (float10)FUN_006e9040();
  fVar5 = (float10)FUN_006e9040();
  FUN_006eafc0((double)((float10)(double)fVar4 / fVar5));
  iVar1 = FUN_006e6b90();
  dVar6 = _ldexp((double)param_1,0x14 - iVar1);
  FUN_006eafc0(dVar6 + 0.5);
  uVar2 = FUN_006e6b90();
  return uVar2 | (iVar1 + 0x300) * 0x200000 | uVar3;
}

