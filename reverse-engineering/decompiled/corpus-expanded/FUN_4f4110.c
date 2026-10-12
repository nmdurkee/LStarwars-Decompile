/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f4110; label: FUN_004f4110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f4110(int param_1)

{
  int *in_EAX;
  int *unaff_ESI;
  float10 fVar1;
  float local_c;
  float local_8;
  
  if (DAT_0091eef6 == '\0') {
    local_8 = (float)*in_EAX / 127.0;
    local_c = (float)*unaff_ESI / 127.0;
    if (local_8 <= 1.0) {
      if (local_8 < -1.0) {
        local_8 = -1.0;
      }
    }
    else {
      local_8 = 1.0;
    }
    if (local_c <= 1.0) {
      if (local_c < -1.0) {
        local_c = -1.0;
      }
    }
    else {
      local_c = 1.0;
    }
    fVar1 = (float10)FUN_005c0240(local_8 * local_8 + local_c * local_c);
    if (fVar1 < (float10)((float)param_1 / 127.0)) {
      *in_EAX = 0;
      *unaff_ESI = 0;
    }
    return;
  }
  FUN_004f40a0();
  return;
}

