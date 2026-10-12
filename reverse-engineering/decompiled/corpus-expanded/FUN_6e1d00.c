/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e1d00; label: FUN_006e1d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_006e1d00(float param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined1 uVar4;
  
  fVar1 = (float)(int)param_1;
  if ((int)param_1 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar2 = (float)param_2;
  if (param_2 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar1 = fVar1 / fVar2;
  param_1 = 1000.0;
  if (ABS(fVar1 - 1.3333334) < 1000.0) {
    param_1 = ABS(fVar1 - 1.3333334);
  }
  fVar3 = param_1;
  fVar2 = ABS(fVar1 - 1.7777778);
  if (fVar2 < param_1) {
    param_1 = fVar2;
  }
  uVar4 = 2;
  if (param_1 <= ABS(fVar1 - 1.6)) {
    uVar4 = fVar2 < fVar3;
  }
  return uVar4;
}

