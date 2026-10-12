/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5a96f0; label: FUN_005a96f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a96f0(void)

{
  float fVar1;
  float fVar2;
  float *in_EAX;
  byte *in_ECX;
  int iVar3;
  
  iVar3 = (uint)*in_ECX * 0x20 + (int)in_EAX[0x10];
  fVar1 = *(float *)(in_ECX + 0x14) - (*(float *)(iVar3 + 0xc) + *in_EAX);
  fVar2 = *(float *)(in_ECX + 0x1c) - (*(float *)(iVar3 + 0x10) + in_EAX[1]);
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
  if (fVar1 < 0.040000003 != (fVar1 == 0.040000003)) {
    in_ECX[1] = in_ECX[1] | 0x40;
    return 1;
  }
  return 0;
}

