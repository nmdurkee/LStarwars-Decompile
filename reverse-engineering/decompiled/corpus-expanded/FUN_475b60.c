/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x475b60; label: FUN_00475b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475b60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  float10 extraout_ST0;
  float fVar3;
  
  if ((DAT_0093b324 != 0) && (param_1 == 0)) {
    iVar1 = FUN_0055f1a0();
    if (iVar1 == 0) {
      FUN_005b7d30(_DAT_00925064,0x3f000000);
      iVar1 = FUN_006e6b90();
      fVar3 = _DAT_007fa1ac * 0.6;
      uVar2 = FUN_006e6b90((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * 0.2 + 0.8,fVar3);
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008807a0 * 4),0,0xbf0ccccd,0x3f800000,fVar3,
                   fVar3,fVar3,0,0xff,0,0,(float)(extraout_ST0 * (float10)1.7000000476837158),1,0,0,
                   uVar2);
    }
  }
  return;
}

