/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d53f0; label: FUN_005d53f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d53f0(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  
  if ((param_3 == 0) || ((*(byte *)(param_1 + 0x80) & 1) == 0)) {
    fVar1 = *(float *)(param_1 + 0x84);
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
    fVar2 = *(float *)(param_1 + 0x88);
    iVar8 = FUN_006e6b90();
    fVar3 = (float)(&DAT_029899a0)[iVar8 + 0x4000 >> 1 & 0x7fff];
    fVar4 = (float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff];
    fVar5 = *(float *)(param_1 + 0x8c);
    fVar6 = *(float *)(param_2 + 0x44);
    fVar7 = *(float *)(param_1 + 0x90);
    _memset((float *)(param_1 + 0x40),0,0x40);
    *(float *)(param_1 + 0x40) = (fVar3 / fVar4) * fVar5 * fVar6;
    *(float *)(param_1 + 0x54) = (fVar3 / fVar4) * fVar7;
    fVar1 = fVar1 - fVar2;
    *(float *)(param_1 + 0x68) = 2.0 / fVar1;
    *(undefined4 *)(param_1 + 0x6c) = 0x3f800000;
    *(float *)(param_1 + 0x78) = (fVar2 * -2.0) / fVar1;
  }
  FUN_005c0940(&DAT_0097ad10,param_2);
  FUN_005c0500(param_1,&DAT_0097ad10,param_1 + 0x40);
  return;
}

