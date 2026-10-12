/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8790; label: FUN_004f8790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004f8790(int *param_1)

{
  float10 fVar1;
  
  switch(*param_1) {
  case 1:
    FUN_004f8420();
    fVar1 = (float10)FUN_004f8790(param_1);
    return -fVar1;
  default:
    FUN_004ef790();
    return (float10)0;
  case 4:
    FUN_004f8420();
    fVar1 = (float10)FUN_004f8880(param_1);
    if (*param_1 != 5) {
      FUN_004ef790();
    }
    FUN_004f8420();
    return (float10)(float)fVar1;
  case 6:
    return (float10)1;
  case 7:
    break;
  case 8:
    FUN_004ef790();
  }
  FUN_004f8420();
  return (float10)(float)param_1[1];
}

