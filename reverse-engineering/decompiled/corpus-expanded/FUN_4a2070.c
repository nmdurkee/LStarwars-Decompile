/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a2070; label: FUN_004a2070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a2070(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  int in_EAX;
  int iVar4;
  int in_ECX;
  bool bVar5;
  float10 fVar6;
  
  uVar2 = *(uint *)(in_ECX + 0xef4);
  *(uint *)(in_ECX + 0xef4) = uVar2 & 0xffefffff;
  cVar1 = *(char *)(in_ECX + 0x7b5);
  if (cVar1 != '\b') {
    if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x54) + 0x24) + 0x94) & 0x8000) != 0) {
      return;
    }
    if ((*(byte *)(in_ECX + 0xe23) & 1) != 0) {
      return;
    }
    if (cVar1 == '\x12') {
      return;
    }
    if (((*(char *)(in_ECX + 0x281) == '\0') ||
        ((cVar1 != -1 && ((*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 4) == 0)))) ||
       ((((*(byte *)(in_ECX + 0x1fc) & 0x80) == 0 || (param_1 == 0)) &&
        (((*(byte *)(*(int *)(in_ECX + 0xca4) + 0x5a) & 4) == 0 &&
         (((uVar2 >> 0x14 & 1) == 0 || (in_EAX == 0)))))))) {
      if ((*(byte *)(in_ECX + 0x1fc) & 0x80) != 0) {
        FUN_00469820(*(undefined4 *)(PTR_DAT_00802c54 + 0x46ac));
      }
    }
    else if ((((*(byte *)(*(int *)(in_ECX + 0xca4) + 0x5a) & 4) != 0) &&
             (*(int *)(in_ECX + 0x10cc) != 0)) ||
            (FUN_00469820(*(undefined4 *)(PTR_DAT_00802c54 + 0x46ac)),
            *(int *)(in_ECX + 0x10cc) != 0)) {
      *(undefined4 *)(in_ECX + 0x77c) = 0x3f000000;
      *(undefined1 *)(in_ECX + 0x7b5) = 8;
      FUN_0054a850(**(undefined4 **)(in_ECX + 0xca4),0x3f19999a,0);
      *(int *)(*(int *)(in_ECX + 0x10cc) + 0x38) = in_ECX;
      FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
      uVar3 = FUN_00467820(in_ECX + 0x5c,*(undefined4 *)(in_ECX + 0x10cc));
      *(undefined2 *)(in_ECX + 0xe0a) = uVar3;
      if ((*(byte *)(in_ECX + 0x1fc) & 0x80) != 0) {
        FUN_00576960(0x259);
        DAT_00876d9c = DAT_00876d9c | 1;
      }
    }
    if (((*(int *)(in_ECX + 0x10cc) != 0) && ((*(byte *)(in_ECX + 0x1fc) & 0x80) != 0)) &&
       (((*(uint *)(in_ECX + 0xe20) & 0x20000) == 0 && (*(char *)(in_ECX + 0x281) != '\0')))) {
      FUN_004a1fb0();
    }
    if (*(char *)(in_ECX + 0x7b5) != '\b') {
      return;
    }
    if (*(short *)(in_ECX + 0x1064) != DAT_007f198c) {
      return;
    }
    if (DAT_0088a54c == 0) {
      return;
    }
    if (*(int *)(in_ECX + 0xcd0) != 0) {
      return;
    }
    if (DAT_0093b2a4 != 0) {
      return;
    }
    FUN_004a1f50();
    iVar4 = FUN_0062f150(in_ECX + 8,0xb,1,1);
    if ((iVar4 == 0) && (iVar4 = FUN_0062f150(in_ECX + 8,0x27,1,1), iVar4 == 0)) {
      FUN_00681f40("JForcePush",in_ECX + 0x80);
      FUN_00548370();
    }
    FUN_0054a8d0(**(undefined4 **)(in_ECX + 0xca4),2,0);
    if (*(int *)(in_ECX + 0x10cc) != 0) {
      *(undefined4 *)(*(int *)(in_ECX + 0x10cc) + 0x38) = 0;
      uVar3 = FUN_00467820(in_ECX + 0x80,*(undefined4 *)(in_ECX + 0x10cc));
      *(undefined2 *)(in_ECX + 0x5a) = uVar3;
    }
    *(uint *)(in_ECX + 0xe20) = *(uint *)(in_ECX + 0xe20) | 0x1000000;
    FUN_00549fd0();
    return;
  }
  if (((in_EAX != 0) || ((*(byte *)(*(int *)(in_ECX + 0xca4) + 0x5a) & 4) != 0)) &&
     (*(int *)(in_ECX + 0x10cc) != 0)) {
    if (((DAT_0088a54c == 0) || (*(int *)(in_ECX + 0xcd0) != 0)) || (DAT_0093b2a4 != 0)) {
      iVar4 = FUN_00467890(*(int *)(in_ECX + 0x10cc));
      if (iVar4 == 0) {
        iVar4 = FUN_004677d0(*(undefined4 *)(in_ECX + 0x10cc));
        bVar5 = iVar4 == 0;
      }
      else {
        bVar5 = false;
      }
    }
    else {
      bVar5 = false;
    }
    FUN_004399e0();
    if (((bVar5) &&
        (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b160 ||
          ((*(byte *)(in_ECX + 0x1fc) & 0x80) == 0)) ||
         (((*(char *)(in_ECX + 0x288) == '\0' || (*(float *)(in_ECX + 0xc64) <= 0.0)) ||
          ((-0.85 <= *(float *)(in_ECX + 0xc5c) && (*(float *)(in_ECX + 0xc5c) <= 0.85)))))))) &&
       ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b240 ||
        ((((*(short *)(in_ECX + 0x1064) != DAT_007f198c || (DAT_0087a96c == (int *)0x0)) ||
          (*(int *)(in_ECX + 0x10cc) != *DAT_0087a96c)) ||
         (fVar6 = (float10)FUN_005a1500(*(undefined4 *)(*DAT_0087a96c + 0x28)),
         fVar6 <= (float10)0.5)))))) {
      *(int *)(*(int *)(in_ECX + 0x10cc) + 0x38) = in_ECX;
      uVar3 = FUN_00467820(in_ECX + 0x5c,*(undefined4 *)(in_ECX + 0x10cc));
      *(undefined2 *)(in_ECX + 0xe0a) = uVar3;
      FUN_004399e0();
      FUN_004a1fb0();
      goto LAB_004a2219;
    }
    *(undefined4 *)(in_ECX + 0x10cc) = 0;
  }
  *(undefined1 *)(in_ECX + 0x7b5) = 0xff;
LAB_004a2219:
  if (*(char *)(in_ECX + 0x7b5) == -1) {
    FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
  }
  return;
}

