/* ev_7142429e8a404b65d322bf9aed48ceab7ec01cf11de95b2b51b308099ee16d87 */

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

