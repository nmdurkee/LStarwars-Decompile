/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514c80; label: FUN_00514c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514c80(int param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  float10 fVar2;
  float local_10;
  undefined1 local_c [12];
  
  local_10 = 3.4028235e+38;
  if ((param_3 == 0) || (*(int *)(param_3 + 0xd0) == 0)) {
    return (float10)3.4028235e+38;
  }
  if (param_1 == 0) goto LAB_00514d3d;
  if (*(int *)(param_1 + 0x138c) != 0) {
    fVar1 = (float10)FUN_005b3c50(*(int *)(param_1 + 0x138c) + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,
                                  local_c);
    local_10 = (float)fVar1;
  }
  if (*(int *)(param_1 + 0x1390) == 0) {
LAB_00514d18:
    fVar2 = (float10)local_10;
  }
  else {
    fVar1 = (float10)FUN_005b3c50(*(int *)(param_1 + 0x1390) + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,
                                  local_c);
    fVar2 = (float10)local_10;
    local_10 = (float)fVar1;
    if ((float10)(float)fVar1 < fVar2) goto LAB_00514d18;
  }
  if (fVar2 == (float10)3.4028234663852886e+38) {
    return fVar2;
  }
  fVar1 = (float10)FUN_005c0240((float)fVar2);
  local_10 = (float)fVar1;
LAB_00514d3d:
  return (float10)local_10;
}

