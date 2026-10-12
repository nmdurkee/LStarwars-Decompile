/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a4420; label: FUN_004a4420
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4420(int param_1)

{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  int in_EAX;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  float10 fVar7;
  float local_4;
  
  local_4 = 1e+09;
  if (*(char *)(in_EAX + 0x7b5) != '\x12') {
    if ((param_1 == 0) && ((*(byte *)(*(int *)(in_EAX + 0xca4) + 0x5a) & 4) == 0)) {
      return;
    }
    if (((char)*(uint *)(in_EAX + 0x1fc) < '\0') && ((*(uint *)(in_EAX + 0x1fc) & 0x100) == 0)) {
      FUN_00469820(*(undefined4 *)(PTR_DAT_00802c54 + 0x46ac));
    }
    if (*(int *)(in_EAX + 0x10cc) == 0) {
      return;
    }
    if ((*(byte *)(*(int *)(in_EAX + 0x10cc) + 0x74) & 0x80) == 0) {
      return;
    }
    *(undefined1 *)(in_EAX + 0x7b5) = 0x12;
    *(undefined2 *)(in_EAX + 0x7aa) = 0x27;
    if (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x9c) == 0) {
      *(undefined2 *)(in_EAX + 0x7aa) = 0xb;
    }
    *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xffffffbf;
    *(undefined4 *)(in_EAX + 0x77c) = 0x40000000;
    *(undefined4 *)(in_EAX + 0x798) = 0;
    *(undefined4 *)(in_EAX + 0xd10) = 0;
    piVar6 = &DAT_0093d7f0;
    do {
      iVar4 = *piVar6;
      if ((((iVar4 != 0) && ((*(uint *)(iVar4 + 0x1fc) & 1) != 0)) &&
          ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(iVar4 + 0x28b) == '\0' &&
          ((*(uint *)(*(int *)(iVar4 + 0x54) + 4) & 0x80000) == 0)))) {
        fVar7 = (float10)FUN_005b3c50(in_EAX + 0x5c,iVar4 + 0x5c,0);
        fVar1 = (float)fVar7;
        if (*(int *)(in_EAX + 0xd10) == 0) {
          *(int *)(in_EAX + 0xd10) = *piVar6;
          local_4 = fVar1;
        }
        else if ((((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0) ||
                 ((*(byte *)(*(int *)(in_EAX + 0xd10) + 0x1fc) & 0x80) == 0)) && (fVar1 < local_4))
        {
          *(int *)(in_EAX + 0xd10) = *piVar6;
          local_4 = fVar1;
        }
      }
      piVar6 = piVar6 + 1;
    } while ((int)piVar6 < 0x93d810);
    FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),0x3f19999a,0);
    *(int *)(*(int *)(in_EAX + 0x10cc) + 0x38) = in_EAX;
    FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
    uVar3 = FUN_00467820(in_EAX + 0x5c,*(undefined4 *)(in_EAX + 0x10cc));
    *(undefined2 *)(in_EAX + 0xe0a) = uVar3;
    if ((*(byte *)(in_EAX + 0x1fc) & 0x80) == 0) {
      return;
    }
    FUN_00576960();
    return;
  }
  FUN_004399e0();
  if ((*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + *(short *)(in_EAX + 0x7aa) * 4) != 0) &&
     (iVar4 = FUN_0062f1a0(in_EAX + 8), iVar4 != *(short *)(in_EAX + 0x7aa))) {
    return;
  }
  fVar1 = *(float *)(in_EAX + 0x77c);
  fVar2 = *(float *)(in_EAX + 0x77c) - _DAT_00925018;
  *(float *)(in_EAX + 0x77c) = fVar2;
  if (fVar2 <= 0.0) {
    *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
    *(undefined4 *)(in_EAX + 0x10cc) = 0;
    return;
  }
  iVar4 = FUN_0054fa60(0);
  FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),(float)iVar4 * 1.5259022e-05 * 0.5);
  iVar4 = *(int *)(in_EAX + 0x798);
  if (iVar4 == 0) {
    if (*(int *)(in_EAX + 0x10cc) != 0) {
      if ((*(byte *)(in_EAX + 0x7bc) & 0x40) == 0) {
        FUN_004a1fb0();
        uVar3 = FUN_00467820(in_EAX + 0x5c,*(undefined4 *)(in_EAX + 0x10cc));
      }
      else {
        *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x20000;
        iVar4 = *(int *)(*(int *)(in_EAX + 0x10cc) + 0x28);
        if (((iVar4 == 0) || (*(char *)(iVar4 + 8) != '\x01')) ||
           (iVar4 = FUN_005722e0(*(int *)(iVar4 + 0x18) + 4), iVar4 == 0)) goto LAB_004a4665;
        *(int *)(in_EAX + 0xd18) = iVar4;
        *(undefined1 *)(in_EAX + 0xe2d) = 3;
        FUN_0058bee0();
        uVar3 = FUN_005be2d0(*(float *)(iVar4 + 0x30) - *(float *)(in_EAX + 0x5c),
                             *(float *)(iVar4 + 0x38) - *(float *)(in_EAX + 100));
        *(undefined4 *)(in_EAX + 0xd14) = *(undefined4 *)(in_EAX + 0xd18);
        *(undefined1 *)(in_EAX + 0xe2c) = *(undefined1 *)(in_EAX + 0xe2d);
      }
      *(undefined2 *)(in_EAX + 0xe0a) = uVar3;
    }
  }
  else if ((*(byte *)(iVar4 + 0x144) & 1) == 0) {
    *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
  }
  else {
    uVar3 = FUN_005be2d0(*(float *)(iVar4 + 0x30) - *(float *)(in_EAX + 0x5c),
                         *(float *)(iVar4 + 0x38) - *(float *)(in_EAX + 100));
    *(undefined2 *)(in_EAX + 0xe0a) = uVar3;
    FUN_0058bee0();
  }
LAB_004a4665:
  if ((1.0 < fVar1) && (*(float *)(in_EAX + 0x77c) <= 1.0)) {
    uVar5 = FUN_00467920();
    *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) | 0x40;
    *(undefined4 *)(in_EAX + 0x798) = uVar5;
    return;
  }
  return;
}

