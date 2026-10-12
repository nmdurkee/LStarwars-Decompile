/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6df340; label: FUN_006df340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006df340(undefined4 param_1,float param_2,float param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float fVar4;
  double dVar5;
  
  fVar3 = (float10)FUN_005d1080(DAT_009738b8,param_5,&stack0x00000018);
  fVar4 = (float)fVar3;
  fVar3 = (float10)FUN_005d0920(fVar4);
  fVar1 = (float)(fVar3 + (float10)param_2);
  dVar5 = (double)param_3;
  fVar3 = (float10)FUN_005d0930(fVar4,dVar5);
  fVar2 = (float)((float10)dVar5 - fVar3 * (float10)0.5);
  if (param_4 == 0x10) {
    FUN_005eabb0(DAT_009738b8,fVar1,fVar2,0);
  }
  else if (param_4 == 0x20) {
    FUN_005eabb0(DAT_009738b8,fVar1 - fVar4,fVar2,0);
  }
  else if (param_4 == 0x40) {
    FUN_005eabb0(DAT_009738b8,(float)((float10)fVar1 - (float10)fVar4 * (float10)0.5),fVar2,0);
  }
  FUN_005d1060(DAT_009738b8,param_1);
  FUN_005f3580(DAT_009738b8,param_5,&stack0x00000018);
  return;
}

