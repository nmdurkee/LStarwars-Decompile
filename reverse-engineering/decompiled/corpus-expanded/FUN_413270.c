/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x413270; label: FUN_00413270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00413270(void)

{
  float fVar1;
  float *in_EAX;
  int in_ECX;
  float local_20;
  float local_1c;
  float local_18;
  
  if (in_EAX[0x100] == 0.0) {
    return;
  }
  FUN_0040e870();
  *(float *)(in_ECX + 0x30) = *in_EAX;
  *(float *)(in_ECX + 0x34) = in_EAX[1];
  *(float *)(in_ECX + 0x38) = in_EAX[2];
  *(float *)(in_ECX + 0x3c) = in_EAX[3];
  local_20 = in_EAX[4] - *in_EAX;
  local_1c = in_EAX[5] - in_EAX[1];
  local_18 = in_EAX[6] - in_EAX[2];
  FUN_004102c0(&local_20,0x3f800000,0);
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0x3f800000;
  *(float *)(in_ECX + 0x80) = *in_EAX;
  *(float *)(in_ECX + 0x84) = in_EAX[1];
  *(float *)(in_ECX + 0x88) = in_EAX[2];
  fVar1 = in_EAX[3];
  *(undefined4 *)(in_ECX + 0xd8) = 0;
  *(undefined4 *)(in_ECX + 0xdc) = 0;
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  *(float *)(in_ECX + 0x8c) = fVar1;
  *(undefined4 *)(in_ECX + 0x110) = 1;
  *(undefined4 *)(in_ECX + 0xd0) = 0;
  *(float **)(in_ECX + 0xd4) = in_EAX;
  *(undefined4 *)(in_ECX + 0x10c) = 1;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x120) = 0;
  fVar1 = in_EAX[0x149];
  if (fVar1 == 1.21913e-43) {
    *(undefined2 *)(in_ECX + 0xfe) = 0xfed7;
  }
  else if (fVar1 == 1.20512e-43) {
    *(undefined2 *)(in_ECX + 0xfe) = 0xfed5;
  }
  else if (fVar1 == 7.56701e-44) {
    *(undefined2 *)(in_ECX + 0xfe) = 0xfed6;
  }
  else if (fVar1 == 1.1911e-43) {
    *(undefined2 *)(in_ECX + 0xfe) = 0xfed4;
  }
  else if (fVar1 == 1.17709e-43) {
    *(undefined2 *)(in_ECX + 0xfe) = 0xfed4;
  }
  else {
    *(short *)(in_ECX + 0xfe) = SUB42(fVar1,0);
  }
  *(undefined4 *)(in_ECX + 0xf0) = 0x3f800000;
  *(undefined2 *)(in_ECX + 0xfc) = 1;
  *(undefined4 *)(in_ECX + 0xf4) = 0x42480000;
  *(float *)(in_ECX + 0x108) = in_EAX[0x148];
  *(undefined2 *)(in_ECX + 0x100) = *(undefined2 *)(in_EAX + 0x147);
  *(undefined4 *)(in_ECX + 0x124) = 1;
  fVar1 = in_EAX[0x149];
  if (((fVar1 != 1.1911e-43) && (fVar1 != 1.17709e-43)) && (fVar1 != 1.20512e-43)) {
    if (fVar1 == 7.56701e-44) {
      *(undefined4 *)(in_ECX + 0xf0) = 0x40000000;
      *(undefined4 *)(in_ECX + 0xf4) = 0x42480000;
      return;
    }
    if (fVar1 != 1.21913e-43) {
      if (fVar1 != -NAN) {
        return;
      }
      *(undefined4 *)(in_ECX + 0xf0) = 0x3f800000;
      *(undefined4 *)(in_ECX + 0xf4) = 0x42040000;
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0xf0) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0xf4) = 0x41b40000;
  return;
}

