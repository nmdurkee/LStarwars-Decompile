/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x514920; label: FUN_00514920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514920(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  float10 fVar3;
  
  cVar1 = *param_3;
  pcVar2 = param_3;
  while( true ) {
    if (cVar1 == '\0') {
      fVar3 = (float10)FUN_004f28e0(param_3);
      return fVar3;
    }
    if (((cVar1 < -0x2d) || ('9' < cVar1)) || (cVar1 == '/')) break;
    cVar1 = pcVar2[1];
    pcVar2 = pcVar2 + 1;
  }
  DAT_00922260 = param_2;
  DAT_0092225c = param_1;
  fVar3 = (float10)FUN_004f88e0(param_3,FUN_00514850);
  DAT_00922260 = 0;
  return (float10)(float)fVar3;
}

