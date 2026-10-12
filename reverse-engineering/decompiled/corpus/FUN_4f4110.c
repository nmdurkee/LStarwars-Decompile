/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f4110; label: FUN_004f4110
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

