/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x637030; label: FUN_00637030
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00637030(void)

{
  char cVar1;
  float fVar2;
  int unaff_ESI;
  float10 fVar3;
  
  if (((*(int *)(unaff_ESI + 0x4c) != 0) && (_DAT_0291398c != 0.0)) &&
     ((cVar1 = *(char *)(*(int *)(unaff_ESI + 0x4c) + 0x58), cVar1 == '\x03' || (cVar1 == '\b')))) {
    fVar3 = (float10)FUN_005b9dd0();
    *(float *)(unaff_ESI + 0x50) =
         (float)((fVar3 - (float10)0.5) * (float10)_DAT_0080fdf0 +
                (float10)*(float *)(unaff_ESI + 0x50));
    fVar3 = (float10)FUN_005b9dd0();
    *(float *)(unaff_ESI + 0x54) =
         (float)((fVar3 - (float10)0.5) * (float10)_DAT_0080fdf4 +
                (float10)*(float *)(unaff_ESI + 0x54));
    fVar3 = (float10)FUN_005b9dd0();
    *(float *)(unaff_ESI + 0x58) =
         (float)((fVar3 - (float10)0.5) * (float10)_DAT_0080fdf8 +
                (float10)*(float *)(unaff_ESI + 0x58));
  }
  if (*(float *)(unaff_ESI + 0x5c) != 0.0) {
    FUN_005b3b30(unaff_ESI + 0x50,unaff_ESI + 0x50);
  }
  if (*(float *)(unaff_ESI + 0x70) == 0.0) {
    *(undefined4 *)(unaff_ESI + 0x130) = *(undefined4 *)(unaff_ESI + 0x5c);
    *(undefined4 *)(unaff_ESI + 0x124) = *(undefined4 *)(unaff_ESI + 0x50);
    *(undefined4 *)(unaff_ESI + 0x128) = *(undefined4 *)(unaff_ESI + 0x54);
    *(undefined4 *)(unaff_ESI + 300) = *(undefined4 *)(unaff_ESI + 0x58);
    return;
  }
  if (*(float *)(unaff_ESI + 0x70) == 1.0) {
    *(undefined4 *)(unaff_ESI + 0x6c) = *(undefined4 *)(unaff_ESI + 0x130);
    *(undefined4 *)(unaff_ESI + 0x60) = *(undefined4 *)(unaff_ESI + 0x124);
    *(undefined4 *)(unaff_ESI + 0x70) = 0x3f7fbe77;
    *(undefined4 *)(unaff_ESI + 100) = *(undefined4 *)(unaff_ESI + 0x128);
    *(undefined4 *)(unaff_ESI + 0x68) = *(undefined4 *)(unaff_ESI + 300);
  }
  if (((*(float *)(unaff_ESI + 0x60) == 0.0) && (*(float *)(unaff_ESI + 100) == 0.0)) &&
     (*(float *)(unaff_ESI + 0x68) == 0.0)) {
    *(undefined4 *)(unaff_ESI + 0x124) = *(undefined4 *)(unaff_ESI + 0x50);
    *(undefined4 *)(unaff_ESI + 0x128) = *(undefined4 *)(unaff_ESI + 0x54);
    *(undefined4 *)(unaff_ESI + 300) = *(undefined4 *)(unaff_ESI + 0x58);
  }
  else {
    FUN_005b3d80(unaff_ESI + 0x124,unaff_ESI + 0x60,unaff_ESI + 0x50,
                 *(undefined4 *)(unaff_ESI + 0x70));
  }
  FUN_005b3b30(unaff_ESI + 0x124,unaff_ESI + 0x124);
  *(float *)(unaff_ESI + 0x130) =
       *(float *)(unaff_ESI + 0x6c) * *(float *)(unaff_ESI + 0x70) +
       (1.0 - *(float *)(unaff_ESI + 0x70)) * *(float *)(unaff_ESI + 0x5c);
  fVar2 = *(float *)(unaff_ESI + 0x70) - _DAT_0080fdec * _DAT_0291398c;
  if (0.0 <= fVar2) {
    *(float *)(unaff_ESI + 0x70) = fVar2;
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x70) = 0;
  return;
}

