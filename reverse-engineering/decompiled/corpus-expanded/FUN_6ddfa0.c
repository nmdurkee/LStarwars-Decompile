/* Ghidra pseudocode, not original source.
 * ev_ed8379466d952c1ee28599ad459362d78654b4c0ec0ca4c18c489e481aca6c51
 * Entry: 0x6ddfa0; label: FUN_006ddfa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ddfa0(float param_1)

{
  float10 fVar1;
  float10 fVar2;
  float fVar3;
  double dVar4;
  float fVar5;
  
  fVar1 = (float10)FUN_006d5c50();
  fVar2 = (float10)FUN_006d5c60();
  fVar5 = (float)fVar2;
  dVar4 = (double)(param_1 * 0.025);
  fVar2 = (float10)FUN_006df290(dVar4,fVar5);
  DAT_02854d1c = DAT_02854d1c + 1;
  fVar3 = (float)((float10)dVar4 / fVar2);
  FUN_00600b20(2,fVar3);
  FUN_005db980((float)fVar1,fVar5,0,fVar3,param_1 * 0.025,0,0,0x3f800000,0x3f800000,0xffffffff,
               DAT_02975c48);
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20();
  return;
}

