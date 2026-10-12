/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49e450; label: FUN_0049e450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049e450(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (((*(byte *)(in_EAX + 0xe22) & 1) != 0) && (*(char *)(in_EAX + 0xe33) == '\0')) {
    iVar5 = *(int *)(*(int *)(in_EAX + 0x50) + 0xc);
    if ((*(int *)(iVar5 + 0x68) == 0) &&
       ((*(int *)(iVar5 + 0x6c) == 0 && (*(int *)(iVar5 + 0x70) == 0)))) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0057fec0();
    }
    *(int *)(in_EAX + 0xd04) = iVar5;
    iVar3 = FUN_0049e110();
    *(int *)(in_EAX + 0xcfc) = iVar3;
    uVar4 = FUN_0049e190();
    *(undefined4 *)(in_EAX + 0xd00) = uVar4;
    if ((iVar5 == 0) && (iVar3 == 0)) {
      uVar4 = FUN_0049e240();
      *(undefined4 *)(in_EAX + 0xcb0) = uVar4;
    }
    if (((*(uint *)(in_EAX + 0xe20) & 0x80000) == 0) &&
       ((((*(int *)(in_EAX + 0xd04) != 0 || (*(int *)(in_EAX + 0xcfc) != 0)) ||
         (*(int *)(in_EAX + 0xcb0) != 0)) && (*(char *)(in_EAX + 0x7b5) == -1)))) {
      *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x80000;
    }
  }
  if (*(char *)(in_EAX + 0x7b5) == '\f') {
    iVar5 = *(int *)(in_EAX + 0xcf8);
    if (((iVar5 != 0) && (param_3 != 0)) &&
       (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x48) != 0)) {
      FUN_0049d200(0x3f800000,0,1);
      FUN_0049e2b0(0);
      return;
    }
    if (*(char *)(in_EAX + 0xe2f) == '\0') {
      if ((iVar5 == 0) || (bVar1 = *(byte *)(in_EAX + 0xe2e), bVar1 == 0)) {
        fVar2 = *(float *)(in_EAX + 0x77c) - _DAT_00925018;
        *(float *)(in_EAX + 0x77c) = fVar2;
        if (0.0 < fVar2) {
          return;
        }
        *(undefined1 *)(in_EAX + 0xe2f) = 1;
LAB_0049e63d:
        *(undefined4 *)(in_EAX + 0x77c) = 0x3e4ccccd;
        return;
      }
      if (((*(uint *)(iVar5 + 0x1fc) & 0x1000) == 0) || (*(char *)(iVar5 + 0x28b) != '\0')) {
LAB_0049e5db:
        *(undefined1 *)(in_EAX + 0xe2e) = 0;
        return;
      }
      if ((*(uint *)(in_EAX + 0xe20) & 0x20000000) == 0) {
        if ((*(char *)(iVar5 + 0x7b5) != '\x05') || ((uint)bVar1 < *(byte *)(iVar5 + 0x7b2) + 1)) {
          *(undefined1 *)(in_EAX + 0xe2e) = 0;
          return;
        }
      }
      else if (((*(char *)(iVar5 + 0x7b5) != '&') || (*(ushort *)(iVar5 + 0x7aa) != (ushort)bVar1))
              || ((*(short *)(iVar5 + 0x1064) == DAT_007f1884 &&
                  ((*(ushort *)(iVar5 + 0x7aa) == 0x56 && ((*(byte *)(iVar5 + 0x7bc) & 0x40) != 0)))
                  ))) goto LAB_0049e5db;
    }
    else if ((*(short *)(in_EAX + 0x1064) == DAT_007f1884) &&
            ((*(byte *)(in_EAX + 0x1fc) & 0x80) == 0)) {
      fVar2 = *(float *)(in_EAX + 0x77c) - _DAT_00925018;
      *(float *)(in_EAX + 0x77c) = fVar2;
      if (fVar2 <= 0.0) {
        *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
        *(undefined4 *)(in_EAX + 0xdd8) = 0x3fc00000;
        return;
      }
    }
    else {
      if ((param_1 != 0) &&
         (((((*(int *)(in_EAX + 0xd04) != 0 || (*(int *)(in_EAX + 0xcfc) != 0)) ||
            (*(int *)(in_EAX + 0xd00) != 0)) || (*(int *)(in_EAX + 0xcb0) != 0)) &&
          (iVar5 = FUN_0049e370(), iVar5 != 0)))) {
        return;
      }
      if ((param_2 != 0) && (*(int *)(in_EAX + 0xd04) != 0)) goto LAB_0049e63d;
      fVar2 = *(float *)(in_EAX + 0x77c) - _DAT_00925018;
      *(float *)(in_EAX + 0x77c) = fVar2;
      if (fVar2 <= 0.0) {
        if ((param_2 != 0) &&
           (((iVar5 = *(int *)(in_EAX + 0xcf8), iVar5 == 0 ||
             (*(short *)(iVar5 + 0x1064) != DAT_007f1884)) ||
            ((*(char *)(iVar5 + 0x7b5) != '&' ||
             ((*(short *)(iVar5 + 0x7aa) != 0x56 || ((*(byte *)(iVar5 + 0x7bc) & 0x40) == 0))))))))
        {
          FUN_0058e3b0();
          return;
        }
        *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
        return;
      }
    }
  }
  else {
    if (0.0 < *(float *)(in_EAX + 0xdd8)) {
      *(float *)(in_EAX + 0xdd8) = *(float *)(in_EAX + 0xdd8) - _DAT_00925018;
      return;
    }
    if ((((param_4 != 0) && (param_1 != 0)) &&
        ((*(char *)(in_EAX + 0x281) != '\0' &&
         (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(in_EAX + 0x7b5) * 0x10 + 8) & 0x20) == 0 &&
          ((*(byte *)(in_EAX + 0xeec) & 2) != 0)))))) &&
       ((*(int *)(in_EAX + 0xd04) != 0 ||
        (((*(int *)(in_EAX + 0xcfc) != 0 || (*(int *)(in_EAX + 0xd00) != 0)) ||
         (*(int *)(in_EAX + 0xcb0) != 0)))))) {
      FUN_0049e370();
    }
  }
  return;
}

